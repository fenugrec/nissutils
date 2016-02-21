// test forward algo 1 (SID27 sentra; NPT_DDL)
// (c) fenugrec 2014
// sim : seed= 55AA00FF, generates key=80B3 AB3B .
//test vals : seed = F811D1E2, scode = b4395810 :  SID27 keygen = 55AA6699; decrypt (SID36 algo) => F811D1E2 !
// fits with sentra rom, not nisrepro (kline_at) !

#include <stdio.h>
#include <stdint.h>
#include "nislib.h"


#define DEFAULT_SCODE 0x9851EB85	//over-rideable with arg 2 (scode)


int main(int argc, char * argv[]) {
	uint32_t seed, scode, key;


	if (argc < 2) {
		printf("%s seed [scode]\n\tseed and scode are uint32; scode is optional.\n", argv[0]);
		printf("\tscode=9851EB85 by default if unspecified.\n");
		printf("\tUses 23710-8U9xx algo\n");
		printf("\n\tExample: %s 55AA00FF\n", argv[0]);
		return 0;
	}

	// arg 1 : seed
	if (sscanf(argv[1], "%x", &seed) != 1) {
		printf("did not understand %s\n", argv[1]);
		return 0;
	}

	if (argc == 3) {
		if (sscanf(argv[2], "%x", &scode) != 1) {
			printf("did not understand %s\n", argv[2]);
			return 0;
		}
	} else {
		scode=DEFAULT_SCODE;
	}

	printf("Generating key for seed 0x%0X and scode 0x%0X\n", seed, scode);

	key=enc1(seed, scode);
	printf("key: 0x%0X\n", key);
	printf("inverse operation ( sid36 style) : 0x%0X\n", dec1(key, scode));

	return 0;
}

