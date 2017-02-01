/* (c) fenugrec 2015-2016
 * GPLv3
 * unpack nissan .dat repro files.
 * currently recognizes only one chunk format: "FMT SRC TGT LEN 34 82 AH AM AL CL <CL bytes of data> <CRC1> <CRC2> <CKS>"
 * not very clever about possible variants, plenty of hardcoded junk. Also doesn't check CRC and cks.
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>	//malloc etc
#include <string.h>	//memcpy

#include "nislib.h"
#include "stypes.h"

FILE *dbg_stream;


struct datfile {
	FILE *hf;
	u32 siz;	//size of .dat, in bytes
	uint8_t *buf;	//copied here
	
	uint8_t *dbuf;	//unpacked data
};


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
	rf->siz = file_len;

	buf = malloc(file_len);
	if (!buf) {
		printf("malloc choke\n");
		fclose(fbin);
		return -1;
	}

	rf->dbuf = malloc(file_len);
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

#define DCHUNK_SIZE 0x8D	//chunk size is very happy
#define DCHUNK_DLEN 0x80	//bytes of payload
// "FMT SRC TGT LEN 34 82 AH AM AL CL <CL bytes of data> <CRC1> <CRC2> <CKS>"
void unpack_dat(FILE *outf, uint8_t *dest, const uint8_t *src, u32 siz) {
	// 1- search for "88 34 82"
	const uint8_t pm[]={0x88, 0x34, 0x82};
	const uint8_t *psrc;	//misc pointer inside src buf
	uint8_t *orig_dest = dest;
	uint32_t curaddr = 0;

	unsigned long plsiz = 0;	//total payload bytes
	unsigned pl_numc = 0;	//# of chunks

	psrc = u8memstr(src, siz, pm, 3);
	if (!psrc) return;

	//2- point to "AH AM AL..." and start
	psrc += 3;
	while ( psrc < &src[siz - 1] ) {
		// parse AH:AM:AL
		uint32_t temp_addr = reconst_32(psrc);
		temp_addr >>= 8;
		if (temp_addr != (curaddr + DCHUNK_DLEN)) {
			printf("addr skip @ %lX\n", (unsigned long) temp_addr);
		}
		curaddr = temp_addr;
		psrc += 3;	//seek to "CL"
		if (*psrc != DCHUNK_DLEN) {
			printf("bad chunk len ?\n");
			return;
		}
		psrc += 1;	//seek to payload data
		memcpy(dest, psrc, DCHUNK_DLEN);
		pl_numc += 1;
		dest += DCHUNK_DLEN;
		plsiz += DCHUNK_DLEN;
		psrc += (DCHUNK_SIZE - 4); //realign to AH
	}
	printf("total: %u chunks; %lu (0x%06lX) bytes in PL.\n",
			pl_numc, plsiz, plsiz);
	fwrite(orig_dest, 1, plsiz, outf);
	return;
}


int main(int argc, char *argv[])
{
	bool	dbg_file;	//flag if dbgstream is a real file
	FILE *pl0;
	struct datfile rf = {0};

	if (argc !=3) {
		printf("%s <file.dat> <out.dat> : unpack payload to <out.dat> etc\n",argv[0]);
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
	unpack_dat(pl0, rf.dbuf, rf.buf, rf.siz);

	printf("\n");
	close_dat(&rf);
	fclose(pl0);
	if (dbg_file) fclose(dbg_stream);
	return 0;
}

