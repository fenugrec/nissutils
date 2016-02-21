/* nisdec1: decrypt binary file using algo_1 (NPT_DDL)
 * (c) fenugrec 2015
 * Needs the 32-bit scode to decrypt.
 * usage : nisdec1 <scode> <in_file> [<out_file>]
 * if out_file is omitted, output is written to "temp.bin"
 * scode must be in hex, such as 9851EB85 (omit the 0x prefix)
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "nislib.h"

#define DEFAULT_OFILE "temp.bin"	//default output filename


//decrypt ifh, write to ofh.
void nis_decrypt1(FILE *ifh, FILE *ofh, uint32_t scode) {

#define DBUFSIZ 256
	if (!ifh || !ofh) return;

	while (!feof(ifh)) {
		uint8_t ibuf[DBUFSIZ*4];	//source, encrypted
		uint8_t obuf[DBUFSIZ*4];	//decrypted
		uint8_t *icur, *ocur;
		size_t count;
		size_t realbs;	//# actually read

		realbs = fread(ibuf, 1, sizeof(ibuf), ifh);	//try to fill buf
		count = realbs;
		icur = ibuf;
		ocur = obuf;
		for (;count >= 4; count -= 4) {
			uint32_t block;
			uint32_t data;	//decrypted

			block = reconst_32(icur);
			data = dec1(block, scode);
			write_32b(data, ocur);
			icur += 4;
			ocur += 4;
		}
		//if the source file didn't have a multiple of 4 bytes, we may have leftovers.
		if (count) {
			size_t i;
			printf("warning : block size is not multiple of 4; ");
			uint32_t tb=0;
			for (i=0; i < count; i++) {
				tb |= *icur;
				tb <<= 8;
				icur++;
			}
			tb <<= 8 * (4 - count);	//left-justify in dword
			printf("tb : %#x\n", tb);
			write_32b(tb, ocur);
		}
		// obuf is filled with decrypted data; write that block to output file. Round <count> up to nearest multiple of 4.
		count = (realbs + 3) & ~(0x03);
		if (fwrite(obuf, 1, count, ofh) != count) {
			perror("fwrite error !?: ");
			return;
		}
	}
}

int main(int argc, char * argv[]) {
	uint32_t scode;
	const char *ofn;	//output file name
	FILE *i_file, *o_file;

	if (argc < 3) {
		printf("%s <scode> <in_file> [<out_file>]\n\tscode is uint32. Uses NPT_DDL algo"
			"\n\tIf out_file is omitted, output is written to %s"
			"\n\tExample: %s 55AA00FF test.bin\n", argv[0], DEFAULT_OFILE, argv[0]);
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

	nis_decrypt1(i_file,o_file,scode);
	fclose(i_file);
	fclose(o_file);

	return 0;
}

