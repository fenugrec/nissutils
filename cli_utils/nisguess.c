/*bruteforce scode, given encrypted + decrypted data.
 * (c) fenugrec 2015
 * GPLv3
 * Note : because of the algo, there can be many (or no) key possibilities for any given 4-byte-in, 4-byte-out combination.
 * Should be compiled with -O3
 * usage : %0 <enc_u32> <dec_u32>
 * args in hex.
 * example : an encrypted ROM has "4166878b"  as a reset vector; we assume the real address is 0000 0104 so
 * "%0 4166878b 00000104" runs a few seconds and gives 0x1A18 0DC8 and others.

 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "nislib.h"

FILE *dbg_stream;

int main(int argc, char * argv[]) {
	uint32_t enc,dec,key;
	dbg_stream = stdout;

	if (argc < 3) {
		printf("%s <enc> <dec>\n\tboth args are uint32, in hex.\n", argv[0]);
		return 0;
	}

	// arg 1 : enc
	if (sscanf(argv[1], "%x", &enc) != 1) {
		printf("did not understand %s\n", argv[1]);
		return 0;
	}

	// arg 2 : dec
	if (sscanf(argv[2], "%x", &dec) != 1) {
		printf("did not understand %s\n", argv[2]);
		return 0;
	}

	for (key=0; key != -1; key++) {
		if (dec1(enc, key) == dec) {
			printf("found key=%#lx\n", (unsigned long) key);
		}
		if (!(key & 0x3ffffff)) {
			float status = 100.0 * key / ((uint32_t) -1);
			printf("%3.f%% complete.\r", status);
		}
	}
	return 0;
}

