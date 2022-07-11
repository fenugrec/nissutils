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


/* some helpers for hashing with a u32 key,
 * because sizeof(int) could be != 4
 */
#define HASH_FIND_U32(head,findint,out)                                          \
    HASH_FIND(hh,head,findint,sizeof(uint32_t),out)
#define HASH_ADD_U32(head,intfield,add)                                          \
    HASH_ADD(hh,head,intfield,sizeof(uint32_t),add)



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

	unsigned num_recs;	//number of valid records parsed
	unsigned num_fields;	//to enforce uniform lines

	unsigned idx_ecuid;	//0-based index for the ECUID column
	unsigned idx_fidtype;	// for FIDtype
	unsigned idx_keyset;	//sid27 key

	unsigned current_field;
	struct ecuid_rec current_ecr;	 //optional, ecr scratch area during parse

	bool parse_error;	// flag during processing to abort
	bool header_parsed;
};


/** track state while parsing the keyset db */
struct csvinfo_keyset {
	struct keyset_rec **keyset_table;	//callbacks need access to the hashtable pointer

	unsigned num_recs;	//number of valid records parsed
	unsigned num_fields;	//to enforce uniform lines

	//0-based indexes for mandatory columns
	unsigned idx_s27k;
	unsigned idx_s36k1;
	unsigned idx_s36k2;

	unsigned current_field;
	struct keyset_rec current_ks;	 //scratch area during parse

	bool parse_error;	// flag during processing to drop current record
	bool header_parsed;
};



/** initialize given struct to safe, invalid values */
static void init_ecuid_rec(struct ecuid_rec *ecr) {
	assert(ecr);
	memset(ecr, 0, sizeof(*ecr));
	ecr->fidtype = FID_UNK;
}


/** initialize given struct to safe, invalid values */
static void init_keyset_rec(struct keyset_rec *ksr) {
	assert(ksr);
	memset(ksr, 0, sizeof(*ksr));
}

/************************* CSV header processing internal funcs *****************************/

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

/* header field processing : find special fields, count fields per row */
static void csv_keyset_process_header(void *s, size_t len, void *data) {
	assert(data);
	struct csvinfo_keyset *ci = data;

	if (len) {
		if (strncmp("s27k", s, len) == 0) {
			ci->idx_s27k = ci->num_fields;
		}
		if (strncmp("s36k1", s, len) == 0) {
			ci->idx_s36k1 = ci->num_fields;
		}
		if (strncmp("s36k2", s, len) == 0) {
			ci->idx_s36k2 = ci->num_fields;
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

/** csv callback for end-of-record during header parse */
static void csv_keyset_header_done(int c, void *data) {
	assert(data);
	(void) c;
	struct csvinfo_keyset *ci = data;

	if (	ci->idx_s27k == UINT_MAX ||
			ci->idx_s36k1 == UINT_MAX ||
			ci->idx_s36k2 == UINT_MAX ) {
		printf("bad csv header\n");
		ci->parse_error = 1;
	}
	ci->header_parsed = 1;
}


/************************* CSV field processing internal funcs *****************************/

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
			}
		}
	}

	ci->current_field++;
}

/** CSV callback for field processing */
static void csv_keyset_field_cb(void *s, size_t len, void *data) {
	assert(data);

	struct csvinfo_keyset *ci = data;
	if (!ci->header_parsed) {
		csv_keyset_process_header(s, len, data);
		return;
	}

	if (!len) {
		//not necessarily an error; s36k2 could be empty
		goto fastexit;
	}

	u32 *dest = NULL;
	if (ci->current_field == ci->idx_s27k) {
		dest = &ci->current_ks.keyset.s27k;
	} else if (ci->current_field == ci->idx_s36k1) {
		dest = &ci->current_ks.keyset.s36k1;
	} else if (ci->current_field == ci->idx_s36k2) {
		dest = &ci->current_ks.keyset.s36k2;
	}
	if (!dest) {
		//useless field
		goto fastexit;
	}

	unsigned long tmp = 0;
	int rv = sscanf(s, "%lx", &tmp);
	if ((rv != 1) || (tmp > UINT32_MAX)) {
		printf("can't parse %s\n", (char *) s);
		ci->parse_error = 1;
		goto fastexit;
	}

	*dest = (u32) tmp;

fastexit:
	ci->current_field++;
	return;
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
			ci->num_recs++;
		}
		printf("%s\t%u\t%08lX\n", ecr->ecuid, ecr->fidtype, (unsigned long) ecr->s27k);
	}

recdone_exit:
	init_ecuid_rec(&ci->current_ecr);
	ci->current_field = 0;
}

/** per-record callback for end-of-record during regular parse */
static void csv_keyset_rec_cb(int c, void *data) {
	assert(data);

	struct csvinfo_keyset *ci = data;
	if (ci->parse_error) {
		goto recdone_exit;
	}

	if (!ci->header_parsed) {
		csv_keyset_header_done(c, data);
		goto recdone_exit;
	}

	if (ci->current_ks.keyset.s27k && ci->current_ks.keyset.s36k1) {
		// only s27k and s36k1 are mandatory
		struct keyset_rec *ksr;
		HASH_FIND_U32(*ci->keyset_table, &ci->current_ks.keyset.s27k, ksr);
		if (ksr == NULL) {
			ksr = calloc(1, sizeof(struct keyset_rec));
			if (!ksr) {
				return;
			}
			*ksr = ci->current_ks;
			HASH_ADD_U32(*ci->keyset_table, keyset.s27k, ksr);
			ci->num_recs++;
		}
		printf("%08lX\t%08lX\t%08lX\n", (unsigned long) ksr->keyset.s27k, (unsigned long) ksr->keyset.s36k1, (unsigned long) ksr->keyset.s36k2);
	}

recdone_exit:
	init_keyset_rec(&ci->current_ks);
	ci->current_field = 0;
}

/** append specified CSV file contents to db
 *
 * @return 1 if ok
 */

static bool romdb_addcsv_backend(const char *fname,
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

	printf("ecuid parsage done : added %u records\n", ci.num_recs);
	return 1;
}

bool romdb_keyset_addcsv(nis_romdb *romdb, const char *fname) {
	assert(romdb && fname);

	struct csvinfo_keyset ci = {0};
	ci.keyset_table = &romdb->keyset_table;

		//initialize indices to invalid value to identify any missing fields
	ci.idx_s27k = UINT_MAX;
	ci.idx_s36k1 = UINT_MAX;
	ci.idx_s36k2 = UINT_MAX;
	init_keyset_rec(&ci.current_ks);

	if (!romdb_addcsv_backend(fname, csv_keyset_field_cb, csv_keyset_rec_cb, &ci)) {
		//parse error
		return 0;
	}

	printf("keyset parsage done : added %u records\n", ci.num_recs);
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
	struct ecuid_rec *ecr;
	HASH_FIND_STR(romdb->ecuid_table, ecuid, ecr);
	if (!ecr) {
		return NULL;
	}

	struct keyset_rec *ksr;
	HASH_FIND_U32(romdb->keyset_table, &ecr->s27k, ksr);
	if (!ksr) {
		return NULL;
	}

	return &ksr->keyset;
}
