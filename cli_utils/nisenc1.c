/* nisecn1: encrypt binary file using algo_1
 * (c) fenugrec 2015
 * Specify the 32-bit key/scode to use.
 * usage : nisenc1 <key> <in_file> [<out_file>]
 * if out_file is omitted, output is written to "temp.bin"
 * scode must be in hex, such as 9851EB85 (0x prefix optional)
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "nislib.h"

#define DEFAULT_OFILE "temp.bin"	//default output filename


//encrypt ifh, write to ofh.
//Assumes both files are seeked @0
// Bonus : returns 16bit checksum of output !
uint16_t nis_encrypt1(FILE *ifh, FILE *ofh, uint32_t scode) {
	uint16_t cks = 0;
#define DBUFSIZ 256
	if (!ifh || !ofh) return 0;

	while (!feof(ifh)) {
		uint8_t ibuf[DBUFSIZ*4];	//source, plaintext
		uint8_t obuf[DBUFSIZ*4];	//encrypted
		uint8_t *icur, *ocur;
		size_t count;
		size_t realbs;	//# actually read

		realbs = fread(ibuf, 1, sizeof(ibuf), ifh);	//try to fill buf
		count = realbs;
		icur = ibuf;
		ocur = obuf;
		for (;count >= 4; count -= 4) {
			uint32_t plaint;
			uint32_t data;

			plaint = reconst_32(icur);
			data = enc1(plaint, scode);
			write_32b(data, ocur);
			cks += (data >> 16);
			cks += data;
			icur += 4;
			ocur += 4;
		}
		//if the source file didn't have a multiple of 4 bytes, warn & drop leftovers.
		if (count) {
			printf("warning : block size is not multiple of 4; dropping extra bytes.\n");
			realbs &= ~0x03;
		}
		// obuf is filled with decrypted data; write that block to output file.
		if (fwrite(obuf, 1, realbs, ofh) != realbs) {
			perror("fwrite error !?: ");
			return 0;
		}
	}	//while
	return cks;
}

int main(int argc, char * argv[]) {
	uint32_t scode;
	const char *ofn;	//output file name
	uint16_t cks16;
	FILE *i_file, *o_file;

	if (argc < 3) {
		printf("%s <scode> <in_file> [<out_file>]\n\tscode is uint32. Uses Algo 01"
			"\n\tIf out_file is omitted, output is written to " DEFAULT_OFILE
			"\n\tExample: %s 55AA00FF test.bin\n", argv[0], argv[0]);
		return 0;
	}

	// arg 1 : scode
	if (sscanf(argv[1], "%x", &scode) != 1) {
		printf("did not understand %s\n", argv[1]);
		return 0;
	}

	//2 : input file
	if ((i_file=fopen(argv[2],"rb"))==NULL) {
		printf("error opening %s.\n", argv[2]);
		return 0;
	}

	//3 : output file
	if (argc >= 4) {
		ofn = argv[3];
	} else {
		ofn = DEFAULT_OFILE;
	}
	//open it
	if ((o_file=fopen(ofn,"wb"))==NULL) {
		printf("error opening %s.\n", ofn);
		fclose(i_file);
		return 0;
	}

	rewind(i_file);

	cks16 = nis_encrypt1(i_file,o_file,scode);
	printf("encrypted payload cks16 = 0x%04X\n", (unsigned int) cks16);
	fclose(i_file);
	fclose(o_file);

	return 0;
}

