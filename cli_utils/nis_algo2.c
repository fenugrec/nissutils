// test for auth sequence in NIS REPRO (KLINE_AT)
// duplicates fine; doesn't fit with niskey1.
// (c) fenugrec 2014
// (seed= 55AA00FF => key = A1EF5B40)


#include <stdio.h>
#include <stdint.h>




uint32_t readinvb(const uint8_t *buf) {
	// ret 4 bytes at *buf with SH endianness
	// " reconst_4B"
	return buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3];
}

void writeinvb(uint32_t val, uint8_t *buf) {
	//write 4 bytes at *buf with SH endianness
	// "deconst_4B"
	buf += 3;	//start at end
	*(buf--) = val & 0xFF;
	val >>= 8;
	*(buf--) = val & 0xFF;
	val >>= 8;
	*(buf--) = val & 0xFF;
	val >>= 8;
	*(buf--) = val & 0xFF;

	return;
}
	
int main(int argc, char * argv[]) {
	uint32_t seed, key, xorloops, ecx;
	uint8_t bs8[4];	//dummy to force compilation
	int ki;
	
	writeinvb(0, bs8);
	readinvb(bs8);
	
	const uint32_t keytable[]={0x14FA3579, 0x27CD3964, 0x1777FE32, 0x9931AF12,
		0x75DB3A49, 0x19294CAA, 0x0FF18CD76, 0x788236D,
		0x5A6F7CBB, 0x7A992254, 0x0ADFD5414, 0x343CFBCB,
		0x0C2F51639, 0x6A6D5813, 0x3729FF68, 0x22A2C751};
	
	
	if (argc < 2) {
		printf("%s seed\n", argv[0]);
		printf("\tgenerate key with KLINE_AT algo\n");
		printf("\n\tExample: %s 55AA00FF\n", argv[0]);
		return 0;
	}
	
	// arg 1 : seed
	if (sscanf(argv[1], "%x", &seed) != 1) {
		printf("did not understand %s\n", argv[1]);
		return 0;
	}
	

	
	printf("Generating key for seed 0x%0X\n", seed);
	
	ecx = (seed & 1)<<6 | (seed>>9 & 1)<<4 | (seed>>1 & 1)<<3;
	ecx |= (seed>>11 & 1)<<2 | (seed>>2 & 1)<<1 | (seed>>5 & 1);
	ecx += 0x1F;

	if (ecx <= 0) {
		printf("PROB !\n");
		return 0;
	}
	
	ki = (seed & 1)<<3 | (seed>>1 & 1)<<2 | (seed>>2 & 1)<<1 | (seed>>9 & 1);
	
	printf("starting xorloop with ecx=0x%0X, ki=0x%0X\n", ecx, ki);
	
	for (xorloops=0; xorloops < ecx; xorloops++) {
		if (seed & 0x80000000) {
			seed += seed;
			seed ^= keytable[ki];
		} else {
			seed += seed;
		}
	}
	
	key=seed;
	printf("generated key: 0x%0X\n", key);
	
	return 0;
}

