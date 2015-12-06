/*bruteforce scode, given encrypted + decrypted data.
 * (c) fenugrec 2015
 * This version allows to converge on a precise key that works for a given set of u32 vals. (nisguess only gives all possible keys)
 * Note : because of the algo, there can be many (or no) key possibilities for any given 4-byte-in, 4-byte-out combination.
 * Should be compiled with -O3
 * usage : %0 <enc_file> <dec_file>
 * where enc_file contains encrypted data, and dec_file is the expected decrypted data; they have to be the same size of course,
 * and multiples of 4 bytes.
 *
 * typical use : I have en encrypted ROM. I know what a typical reset vector looks like on SH7055 :
 * 00000104  FFFF7FFC ....
 * 1- keep the first 8 bytes of the encrypted ROM in enc_file
 * 2- add those 8 guessed bytes to the dec_file
 * 3- run nisguess2 ; it may give many possible keys
 * 4- try one key, view the decrypted output - try to correct / adjust / guess more decrypted contents
 * (hint : look for "DATABASE" , "LOADER", "SH7...." strings that may be mangled
 * 5- add values to enc and dec files
 * 6- to confirm the correct key, validate the checksum.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define u32 uint32_t


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

uint32_t readinvb(const uint8_t *buf) {
	// ret 4 bytes at *buf with SH endianness
	// " reconst_4B"
	return buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3];
}

void writeinvb(uint32_t val, uint8_t *buf) {
	//write 4 bytes at *buf with SH endianness
	// "decomp_4B"
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

// ret true if key works
inline bool testkey_single(u32 enc, u32 dec, u32 key) {
	return (dec1(key, enc) == dec);
}

//decode *efh with key, return true if it matches *dfh.
//Simple version, runs only until fist EOF is reached. But files should really be the same length
//Does no rewinding on file handles
bool testkey_file(FILE *efh, FILE *dfh, u32 key) {
	while (!feof(efh) && !feof(dfh)) {
		uint8_t fbuf[4];
		u32 enc, dec;

		if (fread(fbuf, 1, 4, efh) != 4) return 1;
		enc = readinvb(fbuf);
		
		if (fread(fbuf, 1, 4, dfh) != 4) return 1;
		dec = readinvb(fbuf);
		
		if (!testkey_single(enc, dec, key)) return 0;
		
	}
	return 1;
}

//bruteforce keys starting at *key; return true if *key is valid for the given pair.
//When it returns false, *key==(u32) -1 and there's nothing else to try.
bool brute_key(u32 enc, u32 dec, u32 *key) {
	if (!key) return 0;

	do {
		(*key)++;
		if (testkey_single(enc,dec,*key)) return 1;
		if (!(*key & 0x3ffffff)) {
			float status = 100.0 * *key / ((uint32_t) -1);
			printf("Search %3.f%% complete.\r", status);
		}
	} while (*key != (u32) -1);

	return 0;
}

//brute force encrypted file *efh to find key that produces *dfh.
//just prints the key(s).
void find_key(FILE *efh, FILE *dfh) {
	uint8_t fbuf[4];
	u32 enc, dec, key;

	if (!efh || !dfh) return;
	
	rewind(efh);
	rewind(dfh);

	//work on first u32 pair:
	if (fread(fbuf, 1, 4, efh) != 4) return;
	enc = readinvb(fbuf);
	
	if (fread(fbuf, 1, 4, dfh) != 4) return;
	dec = readinvb(fbuf);

	//calling brute_key() on the first pair of the file will generate a set of possible keys,
	//which are tested on the rest of the file.
	key = 0;
	while (brute_key(enc, dec, &key)) {
		//printf("\t testing key=%#x: ", key);
		//reset to second u32 pair
		if (fseek(efh, 4, SEEK_SET) || fseek(dfh, 4, SEEK_SET)) {
			printf("fseek issues, seek counselling\n");
			return;
		}
		if (testkey_file(efh, dfh, key)) {
			printf("\t Possible key: %#x\n", key);
		} else {
			//printf("nope\n");
		}
	}
	return;
}


int main(int argc, char * argv[]) {
	FILE *efh, *dfh;
	
	if (argc < 3) {
		printf("%s <enc_file> <dec_file>\n", argv[0]);
		return 0;
	}
	
	// arg 1 : enc'd file
	if ((efh=fopen(argv[1],"rb"))==NULL) {
		printf("error opening %s.\n", argv[1]);
		return 0;
	}
	
	// arg 2 : dec'd file
	if ((dfh=fopen(argv[2],"rb"))==NULL) {
		printf("error opening %s.\n", argv[2]);
		return 0;
	}

	find_key(efh, dfh);

	return 0;
}

