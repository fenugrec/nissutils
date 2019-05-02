/* (c) fenugrec 2015-2017
 *
 * test heuristics to find ECUID in ROM
 *
 * Result : sucks
 * - frequent false positives (maps have sequences that look a lot like ECUIDs)
 * - misses ECUIDs that are next to valid ASCII characters, and duplicated ECUID, like "1CF43D1CF43D"
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>	//memcmp
#include <stdlib.h>	//malloc etc

#include "nislib.h"

FILE *dbg_stream;

// generic ROM struct
struct romfile {
	FILE *hf;
	size_t siz;	//in bytes
	uint8_t *buf;	//copied here
};


//load ROM to a new buffer
//ret 0 if OK
//caller MUST call close_rom() after
static int open_rom(struct romfile *rf, const char *fname) {
	FILE *fbin;
	uint8_t *buf;	//load whole ROM
	size_t file_len;

	rf->hf = NULL;	//not needed

	if ((fbin=fopen(fname,"rb"))==NULL) {
		printf("error opening %s.\n", fname);
		return -1;
	}

	file_len = flen(fbin);
	if ((file_len <= 0) || (file_len > 2048*1024L)) {
		/* TODO : add "-f" flag ? */
		printf("huge file (length %ld)\n", file_len);
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

void find_ecuid(const uint8_t *buf, long siz);

int main(int argc, char *argv[])
{
	bool	dbg_file;	//flag if dbgstream is a real file
	struct romfile rf = {0};

	printf(	"**** %s\n"
		"**** Try to find ECUID string in Nissan ROM\n"
		"**** (c) 2015-2017 fenugrec\n", argv[0]);

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
	find_ecuid(rf.buf, rf.siz);

	printf("\n");
	close_rom(&rf);
	if (dbg_file) fclose(dbg_stream);
	return 0;
}


// ret 1 if tc is a valid char for ECUID : [0-9,A-Z]
static bool valid_ecuidchar(uint8_t tc) {
	if ((tc >= '0') && (tc <= '9')) return 1;
	if ((tc >= 'A') && (tc <= 'Z')) return 1;
	return 0;
}


/* technique 1 : try to find ECUID string surrounded by invalid characters.
 * because ECUID string starts with '1', this should exclude false positives in the FID string.
 */
void find_ecuid(const uint8_t *buf, long siz) {
	long cur = 0;
	long pECUID = 0;
	int elen = 0;
	bool searching = 1;
	for (; cur < siz; cur++) {
		uint8_t curchar = buf[cur];
		if (searching) {
			if (curchar == '1') {
				//previous char needs to be invalid
				if (valid_ecuidchar(buf[cur - 1])) continue;
				searching = 0;
				pECUID = cur + 1;
				continue;
			}
			continue;
		}
		if (elen == 5) {
			//if we already have 5 valid chars, this one has to be invalid.
			if (valid_ecuidchar(curchar)) {
				searching = 1;
				elen = 0;
				continue;
			}
			printf("possible ECUID found @ 0x%lX : %.*s\n",
				pECUID, 5, (const char *) &buf[pECUID]);
			searching = 1;
			elen = 0;
			continue;
		}
		if (valid_ecuidchar(curchar)) {
			elen += 1;
			continue;
		}
		searching = 1;
		elen = 0;
	}
}
