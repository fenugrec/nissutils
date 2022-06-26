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

	romdb_close(romdb);
	return 0;
}
