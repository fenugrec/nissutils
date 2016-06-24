/* (c) fenugrec 2015-2016
 * Gather information about a ROM, from metadata and heuristics
 *
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

_Static_assert(sizeof(char) == 1, "HAH ! a non-8bit char system. This may not work.");
FILE *dbg_stream;

// generic ROM struct
struct romfile {
	FILE *hf;
	long siz;	//in bytes
	uint8_t *buf;	//copied here
	//and some metadata
	long p_loader;	//struct loader
	int loader_v;	//version (10, 50, 60 etc)

	long p_fid;	//location of struct fid_base
	long sfid_size;	//sizeof correct struct fid_base
	long p_ramf;	//location of struct ramf

	/* these point in buf, and so are not necessarily 0-terminated strings */
	const uint8_t *loader_cpu;	//LOADERxx CPU code
	const uint8_t *fid;	//firmware ID itself
	const uint8_t *fid_cpu;	//FID CPU code

	long p_cks;	//position of std_checksum sum
	long p_ckx;	//position of std_checksum xor

	long p_acs;	//pos of alt_cks sum
	long p_acx;	//pos of alt_cks xor

	/* real metadata here. Unknown values must be set to -1 */
	long p_ivt2;	//pos of alt. vector table
	long p_acstart;	//start of alt_cks block
	long p_acend;	//end of alt_cks block

	struct ramf_unified ramf;
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
	if ((file_len <= 0) || (file_len > 2024*1024L)) {
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


/** find sid 27 key
 * @return offset in buf if succesful, < 0 otherwise
 */
long find_s27k(struct romfile *rf, bool thorough) {
	int keyset=0;

	if (!rf) return -1;
	if (!(rf->buf)) return -1;

	/* first method : search for every known key, it
	 * seems a limited number of keysets exist.
	 */
	#if 0
	while (known_keys[keyset].s27k != 0) {
		const uint8_t *keypos;
		uint32_t curkey;
		curkey = known_keys[keyset].s27k;

		/* test 1 : search as a contig 32 bit word. Usually works */
		keypos = u32memstr(rf->buf, rf->siz, curkey);
		if (keypos != NULL) {
			long key_offs = keypos - rf->buf;
			fprintf(dbg_stream, "Keyset %lX found @ 0x%lX !\n", (unsigned long) curkey, (unsigned long) key_offs);
			return key_offs;
		}

		keyset += 1;
	}
	

	/* test 2 : search as two 16bit halves close by
	 * this is slower so only tried if required. TODO :
	 * this can replace totally "test 1" actually.
	 */
	#endif

	keyset = 0;
	long kpl_cur = 0;
	long kph_cur = 0;
	long key_offs;
	int occurences = 0;
	#define SPLITKEY_MAXDIST	12
	while (known_keys[keyset].s27k != 0) {
		const uint8_t *kp_h, *kp_l;
		int dist;
		uint32_t curkey;
		uint8_t ckh[2], ckl[2];
		curkey = known_keys[keyset].s27k;
		ckh[0] = curkey >> 24;
		ckh[1] = curkey >> 16;
		ckl[0] = curkey >> 8;
		ckl[1] = curkey >> 0;

		/* find a match for both 16 bit halves*/
		kp_h = u8memstr(rf->buf + kph_cur, rf->siz - kph_cur, ckh, 2);
		kp_l = u8memstr(rf->buf + kpl_cur, rf->siz - kpl_cur, ckl, 2);
		if ((kp_h == NULL) ||
			(kp_l == NULL)) {
			//try next keyset
			kph_cur = 0;
			kpl_cur = 0;
			keyset += 1;
			continue;
		}

		//how far
		dist = kp_h - kp_l;
		//if kp_l is misaligned, or too far behind (much lower offset in buf) : find next occurence
		if ((dist > SPLITKEY_MAXDIST)  ||
			((kp_l - rf->buf) & 1)) {
			//dubious match
			//Find next kp_l, skip current occurence
			kpl_cur = 1 + kp_l - rf->buf;
			continue;
		}
		//same idea for kp_h
		if ((dist < -SPLITKEY_MAXDIST) ||
			((kp_h - rf->buf) & 1)) {
			//dubious match
			//Find next kp_h, skip current occurence
			kph_cur = 1 + kp_h - rf->buf;
			continue;
		}

		key_offs = kp_h - rf->buf;
		fprintf(dbg_stream, "Keyset %lX found near 0x%lX !\n", (unsigned long) curkey, (unsigned long) key_offs);
		occurences += 1;
		if (thorough) {
			kph_cur = 0;
			kpl_cur = 0;
			keyset += 1;
			continue;
		}
		break;

	}	//while
	if (!occurences) {
		fprintf(dbg_stream, "No keyset found, different heuristics / manual analysis needed.\n");
		return -1;
	}
	if (occurences > 1) {
		fprintf(dbg_stream, "warning : multiple keysets found !?\n");
	}
	return key_offs;

}

//find offset of LOADER struct, update romfile struct
//ret -1 if not ok
long find_loader(struct romfile *rf) {
	const uint8_t loadstr[]="LOADER";
	const uint8_t *sl;
	int loadv;

	if (!rf) return -1;
	if (!(rf->buf)) return -1;

	rf->loader_v = 0;

	/* look for "LOADER", backtrack to beginning of struct. */
	sl = u8memstr(rf->buf, rf->siz, loadstr, 6);
	if (!sl) {
		fprintf(dbg_stream, "LOADER not found !\n");
		return -1;
	}

	//decode version #
	if (sscanf((const char *) (sl + 6), "%d", &loadv) == 1) {
		rf->loader_v = loadv;
	}

	//convert to file offset
	rf->p_loader = (long) (sl - rf->buf) - offsetof(struct loader_t, loader);

	// this is the same for all loader verions:
	rf->loader_cpu = &rf->buf[rf->p_loader + offsetof(struct loader_t, cpu)];

	return rf->p_loader;
}

//parse second part of FID struct and fill altcks + ivt2 + rf->ramf-> stuff
static void parse_ramf(struct romfile *rf) {
	assert(rf);

	//2- find altcks and IVT2 ; sanity check
	switch (rf->loader_v) {
	case 07:
		rf->p_acstart = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_07, altcks_start)]);
		rf->p_acend = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_07, altcks_end)]);
		rf->p_ivt2 = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_07, pIVECT2)]);
		rf->ramf.pRAMjump = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_07, pRAMjump)]);
		rf->ramf.pRAM_DLAmax = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_07, pRAM_DLAmax)]);
		break;
	case 10:
		rf->p_acstart = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_10, altcks_start)]);
		rf->p_acend = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_10, altcks_end)]);
		rf->p_ivt2 = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_10, pIVECT2)]);
		rf->ramf.pRAMjump = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_10, pRAMjump)]);
		rf->ramf.pRAM_DLAmax = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_10, pRAM_DLAmax)]);
		break;
	case 40:
		rf->p_acstart = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_40, altcks_start)]);
		rf->p_acend = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_40, altcks_end)]);
		rf->p_ivt2 = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_40, pIVECT2)]);
		rf->ramf.pRAMjump = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_40, pRAMjump)]);
		rf->ramf.pRAM_DLAmax = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_40, pRAM_DLAmax)]);
		break;
	case 50:
	case 60:
		rf->p_acstart = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_50, altcks_start)]);
		rf->p_acend = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_50, altcks_end)]);
		rf->p_ivt2 = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_50, pIVECT2)]);
		rf->ramf.pRAMjump = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_50, pRAMjump)]);
		rf->ramf.pRAM_DLAmax = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_50, pRAM_DLAmax)]);
		break;
	case 80:
		rf->p_acstart = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_80, altcks_start)]);
		rf->p_acend = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_80, altcks_end)]);
		rf->p_ivt2 = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_80, pIVECT2)]);
		rf->ramf.pRAMjump = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_80, pRAMjump)]);
		rf->ramf.pRAM_DLAmax = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_80, pRAM_DLAmax)]);
		break;
	default:
		rf->p_acstart = -1;
		rf->p_acend = -1;
		rf->p_ivt2 = -1;
		break;
	}
	return;
}


//find offset of FID struct, parse & update romfile struct
//ret -1 if not ok
long find_fid(struct romfile *rf) {
	const uint8_t dbstr[]="DATAB";
	const uint8_t loadstr[]="LOADER";
	const uint8_t *sf;
	uint16_t fftag;
	long sf_offset;	//offset in file

	if (!rf) return -1;
	if (!(rf->buf)) return -1;

	rf->p_fid = -1;
	/* look for "DATABASE" */
	sf = u8memstr(rf->buf, rf->siz, dbstr, 5);
	if (!sf) {
		fprintf(dbg_stream, "no DATABASE found !?\n");
		return -1;
	}
	//convert to file offset
	//Luckily, the database member is at the same offset for all variants of struct fid.
	sf_offset = (sf - rf->buf) - offsetof(struct fid_base1_t, database);

	/* check if this was the LOADER database */
	if (memcmp(sf - offsetof(struct loader_t, database), loadstr, 4) == 0 ) {
		//search again, skipping the first instance
		if ((sf_offset + 6) < rf->siz) {
			sf = u8memstr(&rf->buf[sf_offset + sizeof(struct loader_t)], rf->siz - sf_offset - 1 , dbstr, 5);
		}
		if (!sf) {
			fprintf(dbg_stream, "no FID DATABASE found !\n");
			return -1;
		}
		//convert to file offset again
		sf_offset = (sf - rf->buf) - offsetof(struct fid_base1_t, database);
	}

	//bounds check
	if ((sf_offset + FID_MAXSIZE) >= rf->siz) {
		fprintf(dbg_stream, "Possibly incomplete / bad dump ? FID too close to end of ROM\n");
		return -1;
	}

	rf->p_fid = sf_offset;

	//sanity check loader version VS the header tag.
	fftag = reconst_16(&rf->buf[sf_offset]);
	if (rf->loader_v == 80) {
		//these are special, they don't have an "FFFF" tag.
	} else {
		if (fftag != 0xffff) {
			fprintf(dbg_stream, "Unusual FID header tag = 0x%04X\n", (unsigned) fftag);
		}
	}

	/* independant of loader version : */
	rf->fid = &rf->buf[sf_offset + offsetof(struct fid_base1_t, FID)];
	rf->fid_cpu = &rf->buf[sf_offset + offsetof(struct fid_base1_t, cpu)];

	/* special case for LOADER-less ROMs that have CPU=705507. */
	if (rf->loader_v == 0) {
		const uint8_t load07[] = "705507";
		if (memcmp(rf->fid_cpu + 2, load07, 6) == 0) {
			fprintf(dbg_stream, "Looks like a loader-less \"07\" ROM.\n");
			rf->loader_v = 7;
		} else {
			fprintf(dbg_stream, "Unknown loader version / FID type !!\n");
		}
	}

	switch (rf->loader_v) {
	case 80:
		rf->sfid_size = sizeof(struct fid_base2_t);
		break;
	case 07:
	case 10:
	case 40:
	case 50:
	case 60:
	default:
		rf->sfid_size = sizeof(struct fid_base1_t);
		break;
	}
	return sf_offset;
}

/** validate alt cks block in pre-parsed romfile
 *
 * @return 0 if ok
 */
int validate_altcks(struct romfile *rf) {
	/* validate alt_cks block; it's a std algo that skips 2 u32 locs (altcks_s, altcks_x).
	 * But it seems those locs are always outside the block?
	 */
	uint32_t acs=0, acx=0;
	const uint8_t *pacs, *pacx;

	if (!rf) return -1;
	if (!(rf->buf)) return -1;
	if ((rf->p_acstart < 0) ||
		(rf->p_acend < 0) ||
		(rf->p_acstart >= rf->p_acend)) {
		return -1;
	}

	sum32(&rf->buf[rf->p_acstart], rf->p_acend - rf->p_acstart, &acs, &acx);
	fprintf(dbg_stream, "alt cks block 0x%06lX - 0x%06lX: sumt=0x%08lX, xort=0x%08lX\n",
		(unsigned long) rf->p_acstart, (unsigned long) rf->p_acend,
			(unsigned long) acs, (unsigned long) acx);
	pacs = u32memstr(rf->buf, rf->siz, acs);
	pacx = u32memstr(rf->buf, rf->siz, acx);
	if (!pacs && !pacx) {
		fprintf(dbg_stream, "altcks values not found in ROM, possibly unskipped vals or bad algo\n");
		return -1;
	} else {
		fprintf(dbg_stream, "confirmed altcks values found : acs @ 0x%lX, acx @ 0x%lX\n",
				(unsigned long) (pacs - rf->buf), (unsigned long) (pacx - rf->buf));
		//TODO : validate altcks val offsets VS end-of-IVT2, i.e. they seem to be always @
		// IVT2 + 0x400
	}
	return 0;
}


/** find & analyze 'struct ramf'
 *
 * @return 0 if ok
 *
 * it's right after struct fid, easy. The rom must already have
 * loader and fid structs found (find_loader, find_fid)
 */

long find_ramf(struct romfile *rf) {
	uint32_t testval;

	if (!rf) return -1;
	if (!(rf->buf)) return -1;
	if (rf->p_fid <= 0) return -1;

	rf->p_ramf = rf->p_fid + rf->sfid_size;

	//1- sanity check first member, has always been FFFF8000.
	testval = reconst_32(&rf->buf[rf->p_ramf]);
	if (testval != 0xffff8000) {
		long ramf_adj = 0;
		long sign = 1;
		fprintf(dbg_stream, "Unlikely contents for struct ramf; got 0x%lX.\n", (unsigned long) testval);
		while (ramf_adj != 12) {
			//search around, in a pattern like +0, +4, -4, +8, -8, +12.
			testval = reconst_32(&rf->buf[rf->p_ramf + (sign * ramf_adj)]);
			if (testval == 0xffff8000) {
				fprintf(dbg_stream, "probable RAMF found @ delta = %+d\n", (int) (sign * ramf_adj));
				rf->p_ramf += (sign * ramf_adj);
				break;
			}
			sign = -sign;	//flip sign;
			if (sign == 1) ramf_adj += 4;
		}
	}

	parse_ramf(rf);

	free(rf->buf);
	if ((rf->p_acstart >= rf->siz) ||
		(rf->p_acend >= rf->siz) ||
		(rf->p_ivt2 >= rf->siz)) {
		fprintf(dbg_stream, "warning : altcks / IVT2 values out of bounds, probably due to unusual RAMF structure.\n");
		rf->p_acstart = -1;
		rf->p_acend = -1;
		rf->p_ivt2 = -1;
	}

	if (rf->p_ivt2 >= 0) {
		if (!check_ivt(&rf->buf[rf->p_ivt2])) {
			fprintf(dbg_stream, "Unlikely IVT2 location 0x%06lX :\n", (unsigned long) rf->p_ivt2);
			fprintf(dbg_stream, "%08lX %08lX %08lX %08lX...\n", (unsigned long) reconst_32(&rf->buf[rf->p_ivt2+0]),
						(unsigned long) reconst_32(&rf->buf[rf->p_ivt2+4]),
						(unsigned long) reconst_32(&rf->buf[rf->p_ivt2+8]),
						(unsigned long) reconst_32(&rf->buf[rf->p_ivt2+12]));
		}
	}


	if (rf->p_acstart >= rf->p_acend) {
		fprintf(dbg_stream, "bad/reversed alt cks bounds; 0x%lX - 0x%lX\n",
				(unsigned long) rf->p_acstart, (unsigned long) rf->p_acend);
		rf->p_acstart = -1;
		rf->p_acend = -1;
	}

	if (rf->p_acstart >= 0) {
		(void) validate_altcks(rf);
	}

	//display some LOADER80-specific garbage
	if (rf->loader_v == 80) {
		//parse ECUREC
		long pecurec = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_80, pECUREC)]);
		if ((pecurec + 6) <= rf->siz) {
			//skip leading '1'
			fprintf(dbg_stream, "probable ECUID : %.*s\n", 5,  &rf->buf[pecurec + 1]);
		}

		//validate ROM size
		testval = reconst_32(&rf->buf[rf->p_ramf + offsetof(struct ramf_80, romend)]);
		if (testval != (rf->siz -1)) {
			fprintf(dbg_stream, "mismatched <romend> field : got %lX\n", (unsigned long) testval);
		}

        /* Locate RIPEMD-160 magic numbers */
        if ((u32memstr(rf->buf, rf->siz, 0x67452301) != NULL) &&
			(u32memstr(rf->buf, rf->siz, 0x98BADCFE) != NULL)) {
			fprintf(dbg_stream, "RIPEMD-160 hash function present.\n");
		} else {
			fprintf(dbg_stream, "RIPEMD-160 hash function not found ??\n");
		}

		/* Locate cks_alt2 checksum */
		long p_as = 0, p_ax = 0;
		long p_skip1, p_skip2;
		p_skip1 = (pecurec - 4) - pecurec;
		p_skip2 = (rf->p_ivt2 - 4) - pecurec;
		if (checksum_alt2(&rf->buf[pecurec], rf->siz - pecurec, &p_as, &p_ax, p_skip1, p_skip2) == 0) {
			fprintf(dbg_stream, "alt2 checksum found; sum @ 0x%lX, xor @ 0x%lX\n",
					(unsigned long) p_as, (unsigned long) p_ax);
		} else {
			fprintf(dbg_stream, "alt2 checksum not found ?? Bad algo, bad skip, or other problem...\n");
		}

	}

	return rf->p_ramf;
}



void find_eep(struct romfile *rf) {
	uint32_t eepread = find_eepread(rf->buf, rf->siz);
	if (eepread > 0) {
		fprintf(dbg_stream, "found eep_read() @ 0x%0X\n", eepread);
	}
}

int main(int argc, char *argv[])
{
	struct romfile rf;
	long loaderpos;
	long fidpos;
	long ramfpos;

	if (argc !=2) {
		printf("%s <ROMFILE> : analyze 512k or 1M ROM.\n",argv[0]);
		return 0;
	}

	dbg_stream = stdout;

	if (open_rom(&rf, argv[1])) {
		printf("Trouble in open_rom()\n");
		return -1;
	}

	printf("loaded %ldk ROM %s.\n", rf.siz / 1024, argv[1]);

	loaderpos=find_loader(&rf);
	if (loaderpos >= 0) {
		const char *scpu;
		scpu = (const char *) rf.loader_cpu;
		fprintf(dbg_stream, "Loader %d found @ 0x%lX, ", rf.loader_v, (unsigned long) loaderpos);
		fprintf(dbg_stream, "%.*s\n", sizeof(((struct loader_t *)NULL)->cpu), scpu);
	}

	fidpos = find_fid(&rf);
	if (fidpos >= 0) {
		const char *sfid;
		const char *scpu;

		fprintf(dbg_stream, "FID header tag = 0x%04X\n", (unsigned) reconst_16(&rf.buf[rf.p_fid]));

		sfid = (const char *) rf.fid;
		scpu = (const char *) rf.fid_cpu;
		fprintf(dbg_stream, "FID: %.*s found @ 0x%lX, ", \
			sizeof(((struct fid_base1_t *)NULL)->FID), sfid, (unsigned long) fidpos);
		fprintf(dbg_stream, "%.*s\n", sizeof(((struct fid_base1_t *)NULL)->cpu), scpu);

	} else {
		fprintf(dbg_stream, "error: no FID struct, nothing more to say...\n");
	}
	ramfpos = find_ramf(&rf);
	if (ramfpos >= 0) {
		fprintf(dbg_stream, "RAMjump : 0x%08X - 0x%08X\n", rf.ramf.pRAMjump, rf.ramf.pRAM_DLAmax);
		if (rf.p_ivt2 >= 0) {
			fprintf(dbg_stream, "IVECT2 @ 0x%lX\n", (unsigned long) rf.p_ivt2);
		} else {
			long iter;
			fprintf(dbg_stream, "no IVT2 ?? wtf. Last resort, brute force technique:\n");
			iter = 0x100;	//skip power-on IVT
			while ((iter + 0x400) < rf.siz) {
				long new_offs;
				new_offs = find_ivt(rf.buf + iter, rf.siz - iter);
				if (new_offs < 0) {
					fprintf(dbg_stream, "\t no IVT2 found.\n");
					break;
				}
				iter += new_offs;
				fprintf(dbg_stream, "\tPossible IVT @ 0x%lX\n",(unsigned long) iter);
				if (reconst_32(rf.buf + iter + 4) ==0xffff7ffc) {
					fprintf(dbg_stream, "\t\tProbable IVT !\n");
				}
				iter += 0x4;
			}
		}

	}

	if (!checksum_std(rf.buf, rf.siz, &rf.p_cks, &rf.p_ckx)) {
		fprintf(dbg_stream, "standard checksum values found : std_cks @ 0x%lX, std_ckx @0x%lX\n",
				(unsigned long) rf.p_cks, (unsigned long) rf.p_ckx);
	}

	find_s27k(&rf, 0);
	find_s27_hardcore(rf.buf, rf.siz);
	find_eep(&rf);

	printf("\n");
	close_rom(&rf);
	return 0;
}
