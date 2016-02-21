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

#include "nislib.h"

#define u32 uint32_t


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
		enc = reconst_32(fbuf);

		if (fread(fbuf, 1, 4, dfh) != 4) return 1;
		dec = reconst_32(fbuf);

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
	enc = reconst_32(fbuf);

	if (fread(fbuf, 1, 4, dfh) != 4) return;
	dec = reconst_32(fbuf);

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

