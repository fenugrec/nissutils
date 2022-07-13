/* front-end for a multi-source database of ROM metadata
 * (c) fenugrec 2022
 * GPLv3
 *
 * the idea is to provide a C API to common queries like
 *
 * - getting keyset for a known ECUID
 * - appending an external file (.csv) with extra entries
 * -
 *
 * for now, it holds one 'table' with ECUID as the primary key.
 */

#ifndef NIS_ROMDB_H
#define NIS_ROMDB_H

#include <stdint.h>
#include <stdbool.h>

#include "nissan_romdefs.h"
#include "stypes.h"


#define ECUID_LEN 5	//excluding 0-term
#define ECUID_STR_LEN (ECUID_LEN + 1)	//includes 0-term

/*********** some incomplete decls just as placeholders */

struct s_nis_romdb;
typedef struct s_nis_romdb nis_romdb;	//opaque struct for private stuff

/**********************  key stuff ****************************/
/* key stuff */

enum key_type {
	KEY_S27 = 0,	//SID27 key
	KEY_S36K1,	//SID36 kernel key
	KEY_S36K2,	//SID36 factory payload key (less useful)
	KEY_INVALID,
};

struct keyset_t {
	uint32_t s27k;
	uint32_t s36k1;
	uint32_t s36k2;
	};

/** try to see if candidate matches one known keyset.
 *
 * return NULL if not found
 */
const struct keyset_t *find_knownkey(nis_romdb *romdb, enum key_type ktype, u32 candidate);


/** iterate over known keysets and call user func.
 *
 * @param data : data to pass to callback
 *
 * the callback must return 1 to signal an error or request to stop
 *
 */
void keysets_iterate(nis_romdb *romdb, bool (*cb1)(const struct keyset_t *keyset, void *data), void *data);


/** initialize and return a new, empty rom db 'handle'
 *
 * @return NULL if error
 *
 */
nis_romdb *romdb_new(void);

/** close & free rom db
 */
void romdb_close(nis_romdb *romdb);


/** append specified CSV file contents to ECUID db
 *
 * @return 1 if ok
 */
bool romdb_ecuid_addcsv(nis_romdb *romdb, const char *fname);

/** append specified CSV file contents to keyset db
 *
 * @return 1 if ok
 */
bool romdb_keyset_addcsv(nis_romdb *romdb, const char *fname);

/************************** queries for basic fields. *****************************
 * the ecuid param must be a u8[5] ; 0-termination optional
 */

/** get FID IC type.
 *
 * @return FID_UNK if ECUID not found
 */
enum fidtype_ic romdb_q_fidtype(nis_romdb *romdb, const char *ecuid);

/** get keyset
 *
 * @return NULL if not found
 */
const struct keyset_t *romdb_q_keyset(nis_romdb *romdb, const char *ecuid);



#endif // NIS_ROMDB_H
