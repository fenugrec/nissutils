/*
 * (c) fenugrec 2022
 * GPLv3
 */


#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "stypes.h"

#include "nislib.h"
#include "nissan_romdefs.h"
#include "nis_romdb.h"

#include "libcsv/csv.h"

/** private struct to keep track of db data and state */
struct s_nis_romdb {
	// some hash table or csv backend data can go here
	int a;
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

	bool header_parsed;

};

/* per-field callback : find special fields, count fields per row */
static void csv_countfields_cb(void *s, size_t len, void *data) {
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

static void csv_header_done(int c, void *data) {
	assert(data);
	(void) c;
	struct csvinfo *ci = data;
	ci->header_parsed = 1;
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

	// parse header
	size_t bytes_read;
	u8 readbuf[1024];
	while (((bytes_read=fread(readbuf, 1, sizeof(readbuf), fh)) > 0) &&
			(ci.header_parsed == 0)) {
		if (csv_parse(&csvp, readbuf, bytes_read, csv_countfields_cb, csv_header_done, &ci) != bytes_read) {
			fprintf(stderr, "Error while parsing file: %s\n", csv_strerror(csv_error(&csvp)) );
			goto badexit;
		}
	}
	//csv_fini(&csvp, )

	if (ci.header_parsed == 0) {
		printf("incomplete parsage !\n");
		goto badexit;
	}
	printf("parsage done : %u fields, ecuid @ %u, fidtype @ %u, keyset @ %u\n",
			ci.num_fields, ci.idx_ecuid, ci.idx_fidtype, ci.idx_keyset);

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
