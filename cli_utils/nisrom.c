/* WIP, this gathers generic ROM functionality
 * for the moment, guess as much information as possible from a ROM dump
 *
 *
 * needs a compiler with C11. Compile with nislib.c
 *
 * usage:
 * nisrom <romfile>
 */

#include <assert.h>	//TODO : replace _Static_assert() with static_assert()
#include <stddef.h>	//for offsetof()
#include <stdint.h>
#include <stdio.h>
#include <string.h>	//memcmp
#include <stdlib.h>	//malloc etc

#include "nissan_romdefs.h"
#include "nislib.h"

// generic ROM struct
struct romfile {
	FILE *hf;
	long siz;	//in bytes
	uint8_t *buf;	//copied here
	//and some metadata
	long p_loader;	//struct loader
	long p_fid;	//struct fid
	long p_cks;	//position of checksum sum
	long p_ckx;	//position of checksum xor
};

// hax, get file length but restore position
static long flen(FILE *hf) {
	long siz;
	long orig;

	if (!hf) return 0;
	orig = ftell(hf);
	if (orig < 0) return 0;

	if (fseek(hf, 0, SEEK_END)) return 0;

	siz = ftell(hf);
	if (siz < 0) siz=0;
	if (fseek(hf, orig, SEEK_SET)) return 0;
	return siz;
}

//load ROM to a new buffer
//ret 0 if OK
//caller MUST call close_rom() after
static int open_rom(struct romfile *rf, const char *fname) {
	FILE *fbin;
	uint8_t *buf;	//load whole ROM
	long file_len;

	rf->hf = NULL;	//not needed

	if ((fbin=fopen(fname,"rb"))==NULL) {
		printf("error opening %s.\n", fname);
		return -1;
	}	

	file_len = flen(fbin);
	if ((file_len <= 0) || (file_len > 1024*1024L)) {
		printf("bad file length %ld, wtf\n", file_len);
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

	
	if ((file_len != 1024*1024L) && (file_len !=512*1024L)) {
		printf("warning: not a 512k or 1M ROM !\n");
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

//search a <buflen> u8 buffer for a <len>-byte long sequence 
//ret NULL if not found
const uint8_t *u8memstr(const uint8_t *buf, long buflen, const uint8_t *needle, long nlen) {
	long hcur, ncur;
	_Static_assert(sizeof(char) == 1, "HAH ! a non-8bit char system. This may not work.");
	if (!buf || !needle || (nlen > buflen)) return NULL;

	for (hcur=0, ncur=0; (hcur < buflen) && (ncur < nlen); hcur++, ncur++) {
		if (buf[hcur] != needle[ncur]) {
			//no match : reset needle ptr
			ncur = 0;
		}
	}
	if (ncur == nlen) {
		//match !
		return &buf[hcur - ncur];
	}
	return NULL;
}

//find offset of LOADER struct
//ret -1 if not ok
long find_loader(struct romfile *rf) {
	const uint8_t loadstr[]="LOADER";
	const uint8_t *sl;

	if (!rf) return -1;
	if (!(rf->buf)) return -1;

	/* look for "LOADER", backtrack to beginning of struct. */
	sl = u8memstr(rf->buf, rf->siz, loadstr, 6);
	if (!sl) {
		printf("LOADER not found !\n");
		return -1;
	}
	//convert to file offset
	return (long) (sl - rf->buf) - offsetof(struct loader_t, loader);
}

//find offset of FID struct
//ret -1 if not ok
long find_fid(struct romfile *rf) {
	const uint8_t dbstr[]="DATAB";
	const uint8_t loadstr[]="LOADER";
	const uint8_t *sf;
	long sf_offset;	//offset in file

	if (!rf) return -1;
	if (!(rf->buf)) return -1;

	/* look for "DATABASE" */
	sf = u8memstr(rf->buf, rf->siz, dbstr, 5);
	if (!sf) {
		printf("no DATABASE found !?\n");
		return -1;
	}
	//convert to file offset
	sf_offset = (sf - rf->buf) - offsetof(struct fid_t, database);

	/* check if this was the LOADER database */
	if (memcmp(sf - offsetof(struct loader_t, database), loadstr, 4) == 0 ) {
		//search again, skipping the first instance
		//TODO bounds check
		sf = u8memstr(&rf->buf[sf_offset + sizeof(struct loader_t)], rf->siz - sf_offset - 1 , dbstr, 5);
		if (!sf) {
			printf("no FID DATABASE found !\n");
			return -1;
		}
	}

	//convert to file offset again
	sf_offset = (sf - rf->buf) - offsetof(struct fid_t, database);
	return sf_offset;
}

int main(int argc, char *argv[])
{
	struct romfile rf;
	long loaderpos;
	long fidpos;
	
	if (argc !=2) {
		printf("%s <ROMFILE> : analyze 512k or 1M ROM.\n",argv[0]);
		return 0;
	}

	if (open_rom(&rf, argv[1])) {
		printf("Trouble in open_rom()\n");
		return -1;
	}

	printf("loaded %ldk ROM %s.\n", rf.siz / 1024, argv[1]);

	loaderpos=find_loader(&rf);
	if (loaderpos >= 0) {
		const char *scpu;
		scpu = (const char *) &rf.buf[loaderpos + offsetof(struct loader_t, cpu)];
		printf("%.*s found @ 0x%lX, ", 8, &rf.buf[loaderpos], loaderpos);
		printf("%.*s\n", sizeof(((struct loader_t *)NULL)->cpu), scpu);
		rf.p_loader=loaderpos;
	}
	
	fidpos = find_fid(&rf);
	if (fidpos >= 0) {
		const char *sfid;
		const char *scpu;
		uint32_t pthis, pivect2=0;
		int i;
		
		rf.p_fid = fidpos;
		sfid = (const char *) &rf.buf[fidpos + offsetof(struct fid_t, FID)];
		scpu = (const char *) &rf.buf[fidpos + offsetof(struct fid_t, cpu)];
		printf("FID: %.*s found @ 0x%lX, ", \
			sizeof(((struct fid_t *)NULL)->FID), sfid, fidpos);
		printf("%.*s\n", sizeof(((struct fid_t *)NULL)->cpu), scpu);

		//XXX hax : to deal with various sizes of struct fid; find IVECT2 by finding pTHIS
		//not super reliable
		for (i=0; i < 30; i++) {
			uint32_t tv;
			pthis = 4*i + fidpos + offsetof(struct fid_t, pRAMjump);
			tv = reconst_32(&rf.buf[pthis]);
			if (tv == fidpos) {
				//found "pTHIS" member; pIVECT2 is right after
				pivect2 = pthis + 4;
				printf("IVECT2 = 0x%lX\n", (unsigned long) reconst_32(&rf.buf[pivect2]));
				break;
			}
		}
		//alt_cks block starts at &pISR_IMI3A, until &FID
		long acsblock = reconst_32(&rf.buf[pthis-4]);
		uint32_t acs=0, acx=0;
		sum32(&rf.buf[acsblock], fidpos - acsblock, &acs, &acx);
		printf("alt cks block @ 0x%lX; sumt=%lX, xort=%lX\n",
			(unsigned long) acsblock, acs, acx);
		
		/*
		printf("short struct IVECT2=0x%lX, long struct IVECT2=0x%lX\n",
			(unsigned long) reconst_32(&rf.buf[fidpos + offsetof(struct fidshort_t, pIVECT2)]),
			(unsigned long) reconst_32(&rf.buf[fidpos + offsetof(struct fid_t, pIVECT2)]));
		*/
		
	}

	if (!checksum_std(rf.buf, rf.siz, &rf.p_cks, &rf.p_ckx)) {
		printf("Standard checksums found @ 0x%lX, 0x%lX\n", rf.p_cks, rf.p_ckx);
	}

	close_rom(&rf);
	return 0;
}
