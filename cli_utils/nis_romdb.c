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

/** private struct to keep track of db data and state */
struct s_nis_romdb {
	// some hash table or csv backend data can go here
	int a;
};


/** one ECUID 'record' */
struct ecuid_rec {
	char ecuid[ECUID_LEN+1];
	enum fidtype_ic fidtype;
	u32 s27k;
	UT_hash_handle hh;
};


nis_romdb *romdb_new(void) {
	nis_romdb *temp = malloc(sizeof(nis_romdb));
	return temp;
}



/** close & free rom db
 */
void romdb_close(nis_romdb *romdb) {
	assert(romdb);
	free(romdb);
}


/********** stuff for parsing CSV */
struct csvinfo {
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
static void csv_process_header(void *s, size_t len, void *data) {
	assert(data);
	struct csvinfo *ci = data;

	if (len) {
		//printf("cb1 #%u, %s \n", ci->num_fields, (const char *)s);
		if (strncmp("ECUID", s, len) == 0) {
			ci->idx_ecuid = ci->num_fields;
		}
		if (strncmp("FIDtype", s, len) == 0) {
			ci->idx_fidtype = ci->num_fields;
		}
		if (strncmp("s27k", s, len) == 0) {
			ci->idx_keyset = ci->num_fields;
		}
	}

	ci->num_fields++;
}

/** csv callback for end-of-record during header parse */
static void csv_header_done(int c, void *data) {
	assert(data);
	(void) c;
	struct csvinfo *ci = data;

	if (	ci->idx_ecuid == UINT_MAX ||
			ci->idx_fidtype == UINT_MAX ||
			ci->idx_keyset == UINT_MAX ) {
		printf("bad csv header\n");
		ci->parse_error = 1;
	}
	ci->header_parsed = 1;
}


/** CSV callback for field processing */
static void csv_field_cb(void *s, size_t len, void *data) {
	assert(data);

	struct csvinfo *ci = data;
	if (!ci->header_parsed) {
		csv_process_header(s, len, data);
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
		// TODO : call find_fidtype
		ci->current_ecr.fidtype = FID705101;

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
static void csv_rec_done(int c, void *data) {
	assert(data);

	struct csvinfo *ci = data;
	if (ci->parse_error) {
		goto recdone_exit;
	}

	if (!ci->header_parsed) {
		csv_header_done(c, data);
		goto recdone_exit;
	}

	if ((strlen(ci->current_ecr.ecuid) == ECUID_LEN) &&
		(ci->current_ecr.fidtype != FID_UNK) &&
		(ci->current_ecr.s27k)) {
		//ok, valid contents :add to hashtable
		printf("%s\t%u\t%08lX\n", ci->current_ecr.ecuid, ci->current_ecr.fidtype, (unsigned long) ci->current_ecr.s27k);
	}

recdone_exit:
	init_ecuid_rec(&ci->current_ecr);
	ci->current_field = 0;
}

/** append specified CSV file contents to db
 *
 * @return 1 if ok
 */

bool romdb_addcsv(nis_romdb *romdb, const char *fname) {
	assert(romdb && fname);

	struct csvinfo ci = {0};

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

	//initialize indices to invalid value to identify any missing fields
	ci.idx_ecuid = UINT_MAX;
	ci.idx_fidtype = UINT_MAX;
	ci.idx_keyset = UINT_MAX;

	// parse header and records
	size_t bytes_read;
	u8 readbuf[1024];
	ci.current_field = 0;
	init_ecuid_rec(&ci.current_ecr);
	while ((bytes_read=fread(readbuf, 1, sizeof(readbuf), fh)) > 0) {
		if (csv_parse(&csvp, readbuf, bytes_read, csv_field_cb, csv_rec_done, &ci) != bytes_read) {
			fprintf(stderr, "Error while parsing file: %s\n", csv_strerror(csv_error(&csvp)) );
			goto badexit;
		}
	}

	printf("parsage done : %u fields, ecuid @ %u, fidtype @ %u, keyset @ %u\n",
			ci.num_fields, ci.idx_ecuid, ci.idx_fidtype, ci.idx_keyset);

	csv_fini(&csvp, csv_field_cb, csv_rec_done, &ci);
	csv_free(&csvp);
	return 1;

badexit:
	csv_free(&csvp);
	return 0;
}


/************************** queries for basic fields.
 * the ecuid param must be a u8[5] ; 0-termination optional
 */

enum fidtype_ic romdb_q_fidtype(nis_romdb *romdb, const u8 *ecuid) {
	assert(romdb && ecuid);
	return FID_UNK;
}

const struct keyset_t *romdb_q_keyset(nis_romdb *romdb, const u8 *ecuid) {
	assert(romdb && ecuid);
	return NULL;
}
