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

#include "stypes.h"


#define ECUID_LEN 5	//excluding 0-term

/*********** some incomplete decls just as placeholders */

struct s_nis_romdb;
typedef struct s_nis_romdb nis_romdb;	//opaque struct for private stuff
enum fidtype_ic;	//comes from nissan_romdefs.h
struct keyset_t;	//from nislib.h


/** initialize and return a new, empty rom db 'handle'
 *
 * @return NULL if error
 *
 */
nis_romdb *romdb_new(void);

/** close & free rom db
 */
void romdb_close(nis_romdb *romdb);


/** append specified CSV file contents to db
 *
 * @return 1 if ok
 */

bool romdb_addcsv(nis_romdb *romdb, const char *fname);


/************************** queries for basic fields.
 * the ecuid param must be a u8[5] ; 0-termination optional
 */

/** get FID IC type.
 *
 * @return FID_UNK if ECUID not found
 */
enum fidtype_ic romdb_q_fidtype(nis_romdb *romdb, const u8 *ecuid);

/** get keyset
 *
 * @return NULL if not found
 */
const struct keyset_t *romdb_q_keyset(nis_romdb *romdb, const u8 *ecuid);

#endif // NIS_ROMDB_H
