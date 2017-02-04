/* nisckfix2
 * simple strategy: rewrite original checksum locations
 * (c) fenugrec 2015
 * GPLv3
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "nislib.h"
#include "stypes.h"

#define DEFAULT_OFILE "temp.bin"	//default output filename

FILE *dbg_stream;

static void fixck2(FILE *i_file, FILE *o_file,
		unsigned long pcs,unsigned long pcx) {
	uint8_t *src;
	u32 file_len;
	u32 ts, tx;		//test sum&xor values

	file_len = flen(i_file);
	if ((file_len <= 0) || (file_len > 3*1024*1024UL)) {
		printf("huge file (length %lu)\n", (unsigned long) file_len);
	}

	src = malloc(file_len);
	if (!src) {
		printf("malloc choke\n");
		return;
	}

	/* load whole ROM */
	if (fread(src,1,file_len,i_file) != file_len) {
		printf("trouble reading\n");
		free(src);
		return;
	}

	if (((pcs + 4)>= file_len) || ((pcx + 4) >= file_len)) return;
	//write 0 at the sum & xor locations, so they won't affect the overall calculation
	
	write_32b(0, &src[pcs]);
	write_32b(0, &src[pcx]);

	sum32(src, file_len, &ts, &tx);

	// and write new ck vals.
	write_32b(ts, &src[pcs]);
	write_32b(tx, &src[pcx]);

	fwrite(src, 1, file_len, o_file);
	return;
}


int main(int argc, char * argv[]) {
	unsigned long pcs, pcx;
	const char *ofn;	//output file name
	FILE *i_file, *o_file;

	dbg_stream = stdout;

	if (argc < 4) {
		printf("%s <&cks_s> <&cks_x> <in_file> [<out_file>]"
			"\n\tIf out_file is omitted, output is written to %s"
			"\n\tExample: %s 757c 7574 hackrom.bin\n", argv[0], DEFAULT_OFILE, argv[0]);
		return 0;
	}

	// arg 1,2 : orig checksum locations
	if (sscanf(argv[1], "%lx", &pcs) != 1) {
		printf("did not understand %s\n", argv[1]);
		return 0;
	}
	if (sscanf(argv[2], "%lx", &pcx) != 1) {
		printf("did not understand %s\n", argv[2]);
		return 0;
	}

	//input file
	if ((i_file=fopen(argv[3],"rb"))==NULL) {
		printf("error opening %s.\n", argv[4]);
		return 0;
	}

	if ((pcs & 3) || (pcx & 3)) {
		printf("unaligned stuff\n");
		return 0;
	}

	//3 : output file
	if (argc >= 5) {
		ofn = argv[4];
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

	fixck2(i_file,o_file, pcs, pcx);
	fclose(i_file);
	fclose(o_file);

	return 0;
}

