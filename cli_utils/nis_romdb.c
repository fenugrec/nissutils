/*
 * (c) fenugrec 2022
 * GPLv3
 */


#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "stypes.h"

#include "nislib.h"
#include "nissan_romdefs.h"
#include "nis_romdb.h"

#include "libcsv/csv.h"
#include "uthash/uthash.h"

/** one ECUID 'record' */
struct ecuid_rec {
	char ecuid[ECUID_STR_LEN];
	enum fidtype_ic fidtype;
	u32 s27k;
	//char md5[MD5_DIGEST_STRING_LENGTH];
	UT_hash_handle hh;
};

/** one keyset 'record' */
struct keyset_rec {
	struct keyset_t keyset;
	UT_hash_handle hh;
};


/** opaque struct to keep track of db data and state */
struct s_nis_romdb {
	struct ecuid_rec *ecuid_table;
	struct keyset_rec *keyset_table;
};


nis_romdb *romdb_new(void) {
	nis_romdb *temp = calloc(1, sizeof(nis_romdb));
	return temp;
}



/** close & free rom db
 */
void romdb_close(nis_romdb *romdb) {
	assert(romdb);
	//TODO : delete hashtables
	free(romdb);
}


/********** stuff for parsing CSV */

/** track state while parsing the ecuid db */
struct csvinfo_ecuid {
	struct ecuid_rec **ecuid_table;	//callbacks need access to the hashtable pointer

	unsigned num_fields;	//to enforce uniform lines

	unsigned idx_ecuid;	//0-based index for the ECUID column
	unsigned idx_fidtype;	// for FIDtype
	unsigned idx_keyset;	//sid27 key

	unsigned current_field;
	struct ecuid_rec current_ecr;	 //optional, ecr scratch area during parse
	bool parse_error;	// flag during processing to abort

	bool header_parsed;
};


/** initialize given struct to safe, invalid values */
static void init_ecuid_rec(struct ecuid_rec *ecr) {
	assert(ecr);
	memset(ecr, 0, sizeof(*ecr));
	ecr->fidtype = FID_UNK;
}

/* header field processing : find special fields, count fields per row */
static void csv_ecuid_process_header(void *s, size_t len, void *data) {
	assert(data);
	struct csvinfo_ecuid *ci = data;

	if (len) {
		//printf("cb1 #%u, %s \n", ci->num_fields, (const char *)s);
		if (strncmp("ECUID", s, len) == 0) {
			ci->idx_ecuid = ci->num_fields;
		}
		if (strncmp("FID CPU", s, len) == 0) {
			ci->idx_fidtype = ci->num_fields;
		}
		if (strncmp("s27k", s, len) == 0) {
			ci->idx_keyset = ci->num_fields;
		}
	}

	ci->num_fields++;
}

/** csv callback for end-of-record during header parse */
static void csv_ecuid_header_done(int c, void *data) {
	assert(data);
	(void) c;
	struct csvinfo_ecuid *ci = data;

	if (	ci->idx_ecuid == UINT_MAX ||
			ci->idx_fidtype == UINT_MAX ||
			ci->idx_keyset == UINT_MAX ) {
		printf("bad csv header\n");
		ci->parse_error = 1;
	}
	ci->header_parsed = 1;
}


/** CSV callback for field processing */
static void csv_ecuid_field_cb(void *s, size_t len, void *data) {
	assert(data);

	struct csvinfo_ecuid *ci = data;
	if (!ci->header_parsed) {
		csv_ecuid_process_header(s, len, data);
		return;
	}

	if (ci->current_field == ci->idx_ecuid) {
		if (len != ECUID_LEN) {
			printf("bad ECUID field: %s\n", (char *) s);
			ci->parse_error = 1;
		} else {
			memcpy(ci->current_ecr.ecuid, s, ECUID_LEN);
		}
	} else if (ci->current_field == ci->idx_fidtype) {
		if (len < FIDTYPE_LEN) {
			printf("bad FIDTYPE: %s\n", (char *) s);
			ci->parse_error = 1;
		} else {
			enum fidtype_ic fidtype = get_fidtype(s);
			if (fidtype == FID_UNK) {
				printf("bad FIDTYPE: %s\n", (char *) s);
				ci->parse_error = 1;
			} else {
				ci->current_ecr.fidtype = fidtype;
			}
		}
	} else if (ci->current_field == ci->idx_keyset) {
		if (!len) {
			printf("bad keyset field\n");
			ci->parse_error = 1;
		} else {
			unsigned long s27k = 0;
			sscanf(s, "%lx", &s27k);
			if (!s27k || (s27k > UINT32_MAX)) {
				printf("bad keyset %s\n", (char *) s);
				ci->parse_error = 1;
			} else {
				ci->current_ecr.s27k = s27k;
				// TODO : find_keyset
			}
		}
	}

	ci->current_field++;
}

/** per-record callback for end-of-record during regular parse */
static void csv_ecuid_rec_cb(int c, void *data) {
	assert(data);

	struct csvinfo_ecuid *ci = data;
	if (ci->parse_error) {
		goto recdone_exit;
	}

	if (!ci->header_parsed) {
		csv_ecuid_header_done(c, data);
		goto recdone_exit;
	}

	if ((strlen(ci->current_ecr.ecuid) == ECUID_LEN) &&
		(ci->current_ecr.fidtype != FID_UNK) &&
		(ci->current_ecr.s27k)) {
		//ok, valid contents :add to hashtable
		struct ecuid_rec *ecr;
		HASH_FIND_STR(*ci->ecuid_table, ci->current_ecr.ecuid, ecr);
		if (ecr == NULL) {
			ecr = calloc(1, sizeof(struct ecuid_rec));
			if (!ecr) {
				return;
			}
			*ecr = ci->current_ecr;
			HASH_ADD_STR(*ci->ecuid_table, ecuid, ecr);
		}
		printf("%s\t%u\t%08lX\n", ecr->ecuid, ecr->fidtype, (unsigned long) ecr->s27k);
	}

recdone_exit:
	init_ecuid_rec(&ci->current_ecr);
	ci->current_field = 0;
}

/** append specified CSV file contents to db
 *
 * @return 1 if ok
 */

bool romdb_addcsv_backend(const char *fname,
						void (*field_cb)(void *, size_t, void *), void (*record_cb)(int, void *), void *cbdata) {

	assert(fname && field_cb && record_cb && cbdata);

	struct csv_parser csvp;
	if (csv_init(&csvp,
			CSV_STRICT | CSV_STRICT_FINI | CSV_APPEND_NULL | CSV_EMPTY_IS_NULL)) {
		return NULL;
	}

	// open file
	FILE *fh = fopen(fname, "rb");
	if (!fh) {
		printf("bad fopen\n");
		goto badexit;
	}

	rewind(fh);

	// parse header and records
	size_t bytes_read;
	u8 readbuf[1024];
	while ((bytes_read=fread(readbuf, 1, sizeof(readbuf), fh)) > 0) {
		if (csv_parse(&csvp, readbuf, bytes_read, field_cb, record_cb, cbdata) != bytes_read) {
			fprintf(stderr, "Error while parsing file: %s\n", csv_strerror(csv_error(&csvp)) );
			goto badexit;
		}
	}

	csv_fini(&csvp, field_cb, record_cb, cbdata);
	csv_free(&csvp);
	return 1;

badexit:
	csv_free(&csvp);
	return 0;
}

bool romdb_ecuid_addcsv(nis_romdb *romdb, const char *fname) {
	assert(romdb && fname);

	struct csvinfo_ecuid ci = {0};
	ci.ecuid_table = &romdb->ecuid_table;

		//initialize indices to invalid value to identify any missing fields
	ci.idx_ecuid = UINT_MAX;
	ci.idx_fidtype = UINT_MAX;
	ci.idx_keyset = UINT_MAX;
	init_ecuid_rec(&ci.current_ecr);

	if (!romdb_addcsv_backend(fname, csv_ecuid_field_cb, csv_ecuid_rec_cb, &ci)) {
		//parse error
		return 0;
	}

		// TODO : better check result if csv parse errors (bad headers, no records, etc...)
	printf("parsage done : %u fields, ecuid @ %u, fidtype @ %u, keyset @ %u\n",
			ci.num_fields, ci.idx_ecuid, ci.idx_fidtype, ci.idx_keyset);
	return 1;
}



/************************** queries for basic fields.
 * the ecuid param must be a u8[5] ; 0-termination optional
 */

enum fidtype_ic romdb_q_fidtype(nis_romdb *romdb, const char *ecuid) {
	assert(romdb && ecuid);
	struct ecuid_rec *ecr;
	HASH_FIND_STR(romdb->ecuid_table, ecuid, ecr);
	if (!ecr) {
		return FID_UNK;
	}
	return ecr->fidtype;
}

const struct keyset_t *romdb_q_keyset(nis_romdb *romdb, const char *ecuid) {
	assert(romdb && ecuid);
	return NULL;
}
