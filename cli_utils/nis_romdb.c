/*
 * (c) fenugrec 2022
 * GPLv3
 */


#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "stypes.h"

#include "nislib.h"
#include "nissan_romdefs.h"
#include "nis_romdb.h"


/** private struct to keep track of db data and state */
struct s_nis_romdb {
	// some hash table or csv backend data can go here
	void *stuff;
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


/** append specified CSV file contents to db
 *
 * @return 1 if ok
 */

bool romdb_addcsv(nis_romdb *romdb, const char *fname) {
	assert(romdb && fname);

	(void) fname;
	return 1;
}


/************************** queries for basic fields.
 * the ecuid param must be a u8[5] ; 0-termination optional
 */

enum fidtype_ic romdb_q_fidtype(nis_romdb *romdb, const u8 *ecuid) {
	return FID_UNK;
}

const struct keyset_t *romdb_q_keyset(nis_romdb *romdb, const u8 *ecuid) {
	assert(romdb && ecuid);
	return NULL;
}
