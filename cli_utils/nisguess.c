/*bruteforce scode, given encrypted + decrypted data.
 * (c) fenugrec 2015
 * Note : because of the algo, there can be many (or no) key possibilities for any given 4-byte-in, 4-byte-out combination.
 * Should be compiled with -O3
 * usage : %0 <enc_u32> <dec_u32>
 * args in hex.
 * example : an encrypted ROM has "4166878b"  as a reset vector; we assume the real address is 0000 0104 so
 * "%0 4166878b 00000104" runs a few seconds and gives 0x1A18 0DC8.
 
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>


uint16_t mess1(const uint16_t a, const uint16_t b, const uint16_t x) {
	//orig : a = r4= u16 *, b=r5 = u16 *, x = [ffff8416]
	//sub 15FB2 dans rom sentra
	uint16_t var2,var2b, var6;
	uint32_t var3;
	
	var2 = (x + b);	// & 0xFFFF;
	var3 = var2 << 2;
	var6 = (var3 >>16);
	
	var2b = var6 + var2 + var3 -1;
	
	return var2b ^ a;
	
}

uint16_t mess2(const uint16_t a, const uint16_t b, const uint16_t x) {
	//orig : sub 15FDE
	uint16_t var0,var2, var3;
	uint32_t var1, var2b;
	
	var0 = (x + b) ;
	var1 = var0 << 1;
	
	var2 = (var1 >>16) + var0 + var1 -1;
	var2b = var2 << 4;
	var3 = var2b + (var2b >>16);
	return a ^ var3 ^ var2;
	
}

uint32_t prepkey(uint32_t seed, uint32_t m) {
	//m: scrambling code (hardcoded in ECU firmware)
	//seed is pseudorandom generated on SID 27 01
	uint16_t mH,mL, sH, sL;
	uint16_t kL, kH;	//temp words
	
	mL = m & 0xFFFF;
	mH= m >> 16;
	sL = seed & 0xFFFF;
	sH = seed >> 16;

	
	kL = mess1(sH, sL, mH);
	
	kH = mess2(sL, kL, mL);
	
	return (kH << 16) | kL;
}

//decrypt 4 bytes in <data> with firmware's key <scode>
uint32_t dec1(uint32_t scode, uint32_t data) {
	//based on sub 15F18, ugly rewrite
	uint16_t scH, scL;
	uint16_t dH, dL;
	uint16_t t0, t1, tx; //temp vars

	//split in 16b words
	scH = scode >> 16;
	scL = scode;
	dH = data >> 16;
	dL = data;

	t0 = dH;
	t1 = dL;
	t0 = mess2(t0, t1, scL);
	//printf("mess1 returns %0#x\n", t0);
	tx=t0;
	t0=t1;	//swap t0,t1
	t1=tx;

	t0 = mess1(t0, t1, scH);
	//printf("mess2 returns %0#x\n", t0);
	//printf("local_0: %0#X\tlocal_1: %0#X\n", t0, t1);
	return (t0 << 16) | t1;	
}

int main(int argc, char * argv[]) {
	uint32_t enc,dec,key;
	
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
		if (dec1(key, enc) == dec) {
			printf("found key=%#x\n", key);
		}
		if (!(key & 0x3ffffff)) {
			float status = 100.0 * key / ((uint32_t) -1);
			printf("%3.f%% complete.\r", status);
		}
	}
	return 0;
}

