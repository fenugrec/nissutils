/* (c) fenugrec 2015-2016
 *
 * test heuristics to find code that looks like xoradd checksum loops
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>	//memcmp
#include <stdlib.h>	//malloc etc

#include "nislib.h"
#include "stypes.h"

FILE *dbg_stream;

// generic ROM struct
struct romfile {
	FILE *hf;
	u32 siz;	//in bytes
	uint8_t *buf;	//copied here
};


//load ROM to a new buffer
//ret 0 if OK
//caller MUST call close_rom() after
static int open_rom(struct romfile *rf, const char *fname) {
	FILE *fbin;
	uint8_t *buf;	//load whole ROM
	u32 file_len;

	rf->hf = NULL;	//not needed

	if ((fbin=fopen(fname,"rb"))==NULL) {
		printf("error opening %s.\n", fname);
		return -1;
	}

	file_len = flen(fbin);
	if (file_len > 2048*1024L) {
		/* TODO : add "-f" flag ? */
		printf("huge file (length %lu)\n", (unsigned long) file_len);
		fclose(fbin);
		return -1;
	}
	rf->siz = file_len;

	buf = malloc(file_len);
	if (!buf) {
		printf("malloc choke\n");
		fclose(fbin);
		return -1;
	}

	/* load whole ROM */
	if (fread(buf,1,file_len,fbin) != file_len) {
		printf("trouble reading\n");
		free(buf);
		fclose(fbin);
		return -1;
	}
	rf->buf = buf;

	fclose(fbin);


	if ((file_len != 1024*1024L) && (file_len !=512*1024L)
		&& (file_len != 256 * 1024L)) {
		printf("warning: not a 256k/512k/1M ROM !\n");
	}

	return 0;
}

//close & free whatever
void close_rom(struct romfile *rf) {
	if (!rf) return;
	if (rf->buf) {
		free(rf->buf);
		rf->buf = NULL;
	}
	return;
}

void find_cksloop(const uint8_t *buf, u32 siz);

int main(int argc, char *argv[])
{
	bool	dbg_file;	//flag if dbgstream is a real file
	struct romfile rf = {0};

	if (argc !=2) {
		printf("%s <ROMFILE> : analyze 512k or 1M ROM.\n",argv[0]);
		return 0;
	}

	dbg_file = 1;
	//dbg_stream = fopen(DBG_OUTFILE, "a");
	dbg_stream = NULL;
	if (!dbg_stream) {
		dbg_file = 0;
		dbg_stream = stdout;
	}

	if (open_rom(&rf, argv[1])) {
		if (dbg_file) fclose(dbg_stream);
		printf("Trouble in open_rom()\n");
		return -1;
	}

	/* add header to dbg log */
	fprintf(dbg_stream, "\n********************\n**** Started analyzing %s\n", argv[1]);
	find_cksloop(rf.buf, rf.siz);

	printf("\n");
	close_rom(&rf);
	if (dbg_file) fclose(dbg_stream);
	return 0;
}




/**** technique
 * 1) find "xor rx, r_" opcode
 * 2) backtrack to make sure rn is loaded with "mov.l @r_, rx"
 * 3) make sure sure that rn is also used in a subsequent "add rx, r_"
 */


/**recursive backtrack inside function to find a "mov.l @Rm, Rn"
 *
 * regno : n from "Rn"
 * min : don't backtrack further than buf[min]
 * 
 * @return 0 if failed; if found: offset of mov.x opcode in *buf
 *
 * Limitation: doesn't detect if Rn is modified between start and mov.l !
*/
static long sh_bt_findmemload(const uint8_t *buf, u32 min, u32 start,
				unsigned regno) {
	uint16_t opc;
	for (; start >= min; start -= 2) {
		opc = reconst_16(&buf[start]);
		if ((opc & 0xF00F) != 0x6002) continue;

		if (((opc >> 8) & 0x0F) == (regno & 0x0F)) {
			//got one !
			return start;
		}
	}
	return 0;	//failed
}

#define CKS_MAXBT 20
#define CKS_MAXDIST_ADD 40
//TODO : bounds check
void find_cksloop(const uint8_t *buf, u32 siz) {
	uint32_t cur = 0;
	int occ = 0;	//occurences

	siz &= ~1;

	for (cur = 0; cur < siz; cur += 2) {
		/* find xor rm, rn : 2<rn> <rm>A */
		uint16_t opc;
		int regno;

		opc = reconst_16(&buf[cur]);
		if ((opc & 0xF00F) != 0x200A) continue;

		// got one : try to backtrack
		regno = (opc >> 4) & 0x0F;
		long movl_pos;
		movl_pos = sh_bt_findmemload(buf, cur - CKS_MAXBT, cur, regno);
		if (!movl_pos) {
			//no mov.l
			continue;
		}

		//final test : find "add" too. add Rm, Rn : 3<n> <m>C
		uint32_t add_pos;
		uint16_t addpat=0x300C | (regno << 4);
		uint16_t addmask=0xF0FF;
		add_pos = find_pattern(&buf[movl_pos], CKS_MAXDIST_ADD, 1, &addpat, &addmask);
		if (add_pos == (u32) -1) {
			//printf("\tno add near\n");
		} else {
			printf("xor @ %lX, movl @ %lX, add @ %lX !\n", (long unsigned) cur,
				(long unsigned) movl_pos, (long unsigned) add_pos);
			occ +=1 ;
		}
	}
	printf("%d xorsum loops found\n", occ);
	return;
}