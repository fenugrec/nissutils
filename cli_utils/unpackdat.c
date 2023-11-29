/* (c) fenugrec 2015-2016
 * GPLv3
 * unpack nissan .dat, .kwp and other repro files.
 * currently recognizes two chunk formats:
 *  extended "FMT     SRC TGT LEN 34 82 AH AM AL CL <CL bytes of data> <CRC1> <CRC2> <CKS>"
 *  short 	 "FMT_LEN SRC TGT     34 82 AH AM AL CL <CL bytes of data> <CRC1> <CRC2> <CKS>"
 * Also doesn't check CRC and cks.
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>	//malloc etc
#include <string.h>	//memcpy

#include "nislib.h"
#include "stypes.h"

FILE *dbg_stream;

#define FMT_CHUNK_EXT 0x80
#define CRC_TAIL_LEN 3
#define MAX_DAT_OFFSET 0xffffff

struct datfile {
	FILE *hf;
	u32 	buf_size;	//size of .dat, in bytes
	uint8_t *buf;	//copied here
	
	u32 	dbuf_size;	//size of .bin, in bytes
	uint8_t *dbuf;	//unpacked data
};

typedef struct {
	uint8_t sign[3]; 		// 0xA1 XX XX

	char part_number[5];
	uint32_t date; 			//?
	char part_number2[5];    

	char ver_str[6]; 		// e.g. LBC ZE1/ VCM

	uint32_t off17; 		// 00 00 00 80
	char zeroes[5];

	uint32_t off20; 		// 82 00 00 0x
	uint8_t cks; 			//?
} dat_header_t;

typedef struct {
	uint8_t fmt; 	// 0x80 if exist extra byte ckslen
					// or 0x80 + len (ckslen missed) 
	uint8_t src;
	uint8_t tgt;

	uint8_t ckslen; // data for cks from cmd upto cks.
					// byte missed if fmt != 0x80
} chunk_header_t;

typedef struct {
	uint16_t cmd;	// 34 82

	uint8_t offset_hi;
	uint8_t offset_mid;
	uint8_t offset_low;

	uint8_t chunklen;
	uint8_t payload[]; // chunklen size

	// CRC at the end
    //uint16_t crc;
	//uint8_t cks;
} chunk_t;


//load ROM to a new buffer
//ret 0 if OK
//caller MUST call close_rom() after
static int open_dat(struct datfile *rf, const char *fname) {
	FILE *fbin;
	uint8_t *buf;	//load whole ROM
	u32 file_len;

	rf->hf = NULL;	//not needed

	if ((fbin=fopen(fname,"rb"))==NULL) {
		printf("error opening %s.\n", fname);
		return -1;
	}

	file_len = flen(fbin);
	if ((!file_len) || (file_len > 3*1024*1024L)) {
		printf("empty, or huge file (length %lu)\n", (unsigned long) file_len);
	}
	rf->buf_size = file_len;

	buf = malloc(file_len);
	if (!buf) {
		printf("malloc choke\n");
		fclose(fbin);
		return -1;
	}

	// Allocate max size for output according to offset field dimension
	rf->dbuf_size = MAX_DAT_OFFSET;
	rf->dbuf = malloc(rf->dbuf_size);
	if (!rf->dbuf) {
		printf("malloc choke\n");
		free(buf);
		fclose(fbin);
		return -1;
	}

	/* load whole ROM */
	if (fread(buf,1,file_len,fbin) != file_len) {
		printf("trouble reading\n");
		free(buf);
		free(rf->dbuf);
		fclose(fbin);
		return -1;
	}
	rf->buf = buf;
	fclose(fbin);

	return 0;
}

//close & free whatever
void close_dat(struct datfile *rf) {
	if (!rf) return;
	if (rf->buf) {
		free(rf->buf);
		rf->buf = NULL;
	}
	if (rf->dbuf) {
		free(rf->dbuf);
		rf->dbuf = NULL;
	}
	return;
}

void print_hex(const void *src, int len) {
	const uint8_t *ptr = src;
	for (int i = 0; i < len; i++) {
		printf(" %02x", ptr[i]);
	}
	printf("\n");
}

void unpack_dat(FILE *outf, struct datfile *rf, bool trim) {
	const uint8_t *src = rf->buf;
	const u32 src_size = rf->buf_size;
	const uint8_t pm[] = {0x34, 0x82};
	const uint8_t *psrc;	//misc pointer inside src buf
	uint8_t *dest = NULL;
	
	const chunk_header_t *ch_header = NULL;

	uint8_t chklen = 0;
	uint32_t offset = 0;
	uint32_t firstchaddr = 0;
	unsigned long outsize = 0;
	unsigned pl_numc = 0;	//# of chunks

	const dat_header_t *dath = (const dat_header_t *)src;

	printf("SIGN:");
	print_hex(dath->sign, 3);
	printf("PART1: %.*s\n", 5, dath->part_number);
	printf("DATE:");
	print_hex(&dath->date, sizeof(dath->date));
	printf("PART2: %.*s", 5, dath->part_number2);
	print_hex(dath->part_number2, 5);
	printf("VER: %.*s", 6, dath->ver_str);
	print_hex(dath->ver_str, 6);

	// TODO get rid of search. The first chunk is located at a constant offset 0x25
	psrc = u8memstr(src, src_size, pm, 2);
	if (!psrc) {
		printf("Pattern 34 82 not found\n");
		return;
	}
	
	ch_header = (const chunk_header_t *)(psrc - sizeof(chunk_header_t));
	if (ch_header->fmt != FMT_CHUNK_EXT) {
		// fallback to short chunk
		ch_header = (const chunk_header_t *)(psrc - offsetof(chunk_header_t, ckslen));
	}

	printf("SRC: %#x\n", ch_header->src);
	printf("TGT: %#x\n", ch_header->tgt);

	while (true) {
		const chunk_t *ch = NULL;
		if (ch_header->fmt == FMT_CHUNK_EXT) {
			// 80 SRC TGT LEN 34 82
			ch = (chunk_t*)((uint8_t*)ch_header + sizeof(chunk_header_t));
		} else {
			// XX SRC TGT 34 82
			ch = (chunk_t*)((uint8_t*)ch_header + offsetof(chunk_header_t, ckslen));
		}
		// TODO check whether ch buffer is not go beyond the end of file

		if (ch->cmd != 0x8234) {
			printf("Unexpected cmd pattern %#x at offset %#llx\n",
				ch->cmd, ((uint8_t*)ch - src + offsetof(chunk_t, cmd)));
			break;
		}

		offset = ch->offset_hi << 16 | ch->offset_mid << 8 | ch->offset_low;
		if (pl_numc == 0) {
			if (trim) firstchaddr = offset;
			printf("Trim gap in .bin before first chunk offset 0x%06x\n", offset);

			printf("Chunks:\n");
			printf("#    : offset   @ size\n");
		}

		pl_numc++;
		chklen = ch->chunklen;
		printf("#%04d: 0x%06x @ %d\n", pl_numc, offset, chklen);
		dest = rf->dbuf + offset;
		memcpy(dest, ch->payload, chklen);

		ch_header = (const chunk_header_t *)((uint8_t*)ch + offsetof(chunk_t, payload) + chklen + CRC_TAIL_LEN);
		if (((uint8_t*)ch_header - src) >= src_size) {
			// This is the end of file
			break;
		}
	}

	outsize = offset + chklen - firstchaddr;
	dest = rf->dbuf + firstchaddr;
	printf("total: %u chunks; %lu (0x%06lX) bytes in PL.\n",
			pl_numc, outsize, outsize);

	if (pl_numc > 0)
		fwrite(dest, outsize, 1, outf);
	else
	  	printf("No recognized chunks to save in file\n");
	return;
}


int main(int argc, char *argv[])
{
	bool	dbg_file;	//flag if dbgstream is a real file
	FILE *pl0;
	struct datfile rf = {0};
	bool trim = true;

	if (argc < 3) {
		printf("%s <file.dat> <out.dat>: unpack payload to <out.dat>\n",argv[0]);
		return 0;
	}

	dbg_file = 1;
	//dbg_stream = fopen(DBG_OUTFILE, "a");
	dbg_stream = NULL;
	if (!dbg_stream) {
		dbg_file = 0;
		dbg_stream = stdout;
	}

	if (open_dat(&rf, argv[1])) {
		if (dbg_file) fclose(dbg_stream);
		printf("Trouble in open_dat()\n");
		return -1;
	}

	if ((pl0=fopen(argv[2],"wb"))==NULL) {
		printf("error opening %s.\n", argv[2]);
		return -1;
	}

	/* add header to dbg log */
	fprintf(dbg_stream, "\n********************\n**** Started analyzing %s\n", argv[1]);
	unpack_dat(pl0, &rf, trim);

	printf("\n");
	close_dat(&rf);
	fclose(pl0);
	if (dbg_file) fclose(dbg_stream);
	return 0;
}

