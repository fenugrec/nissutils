/* test ROM db queries*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stypes.h"

#include "nislib.h"
#include "nissan_romdefs.h"
#include "nis_romdb.h"

FILE *dbg_stream;

int main(int argc, char * argv[]) {
	dbg_stream = stdout;

	if (argc != 2) {
		printf("%s <ECUID>"
			"\n\tCase-sensitive; Example: %s 6Z68A\n", argv[0], argv[0]);
		return -1;
	}

	nis_romdb *romdb = romdb_new();
	if (!romdb) {
		printf("bad new\n");
		return -1;
	}

	if (!romdb_ecuid_addcsv(romdb, "test_ecuid.csv")) {
		return -1;
	}
	if (!romdb_keyset_addcsv(romdb, "test_keysets.csv")) {
		return -1;
	}

	enum fidtype_ic fidtype = romdb_q_fidtype(romdb, argv[1]);
	if (fidtype != FID_UNK) {
		printf("fidtype query returns %d\n", fidtype);
	}

	const struct keyset_t *keyset = romdb_q_keyset(romdb, argv[1]);
	if (keyset) {
		printf("keyset query returns %08lX,%08lX,%08lX\n",
				(unsigned long) keyset->s27k, (unsigned long) keyset->s36k1, (unsigned long) keyset->s36k2);
	}

	romdb_close(romdb);
	return 0;
}
