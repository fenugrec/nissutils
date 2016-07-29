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

#define DBG_OUTFILE	"nisrom_dbg.log"	//default log file

_Static_assert(sizeof(char) == 1, "HAH ! a non-8bit char system. This may not work.");
FILE *dbg_stream;

// generic ROM struct
struct romfile {
	FILE *hf;
	long siz;	//in bytes
	uint8_t *buf;	//copied here
	//and some metadata
	long p_loader;	//struct loader
	enum loadvers_t loader_v;	//version (10, 50, 60 etc)

	long p_fid;	//location of struct fid_base
	enum fidtype_ic fidtype;
	long sfid_size;	//sizeof correct struct fid_base
	long p_ramf;	//location of struct ramf
	int	ramf_offset;	//RAMF struct wasn't found where expected (offset != 0)

	/* these point in buf, and so are not necessarily 0-terminated strings */
	const uint8_t *loader_cpu;	//LOADERxx CPU code
	const uint8_t *fid;	//firmware ID itself
	const uint8_t *fid_cpu;	//FID CPU code

	long p_cks;	//position of std_checksum sum
	long p_ckx;	//position of std_checksum xor

	long p_acs;	//pos of alt_cks sum
	long p_acx;	//pos of alt_cks xor
	
	long p_a2cs;
	long p_a2cx;	//pos of alt2 cks sum, xor

	/* real metadata here. Unknown values must be set to -1 */
	long p_ivt2;	//pos of alt. vector table
	long p_acstart;	//start of alt_cks block
	long p_acend;	//end of alt_cks block


	long	p_eepread;	//address of eeprom_read() func
	uint32_t	eep_port;	//PORT reg used for EEPROM pins

	/* some flags */
	bool	cks_alt_good;	//alt cks found + valid
	bool	cks_alt2_good;	//alt2 cks found + valid
	bool	has_rm160;	//RIPEMD160 hash found

	struct ramf_unified ramf;	//not useful atm
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


/** find sid 27 key
 * @param key_idx : index in known key db
 * @return sets *key_idx if succesful
 */
bool find_s27k(struct romfile *rf, int *key_idx, bool thorough) {
	int keyset=0;

	if (!rf) return 0;
	if (!(rf->buf)) return 0;

	/* first method : search for every known key, it
	 * seems a limited number of keysets exist.
	 */
	#if 0
	check retval
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
		uint16_t ckh, ckl;
		curkey = known_keys[keyset].s27k;
		ckh = curkey >> 16;
		ckl = curkey >> 0;

		/* find a match for both 16 bit halves*/
		kp_h = u16memstr(rf->buf + kph_cur, rf->siz - kph_cur, ckh);
		kp_l = u16memstr(rf->buf + kpl_cur, rf->siz - kpl_cur, ckl);
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
			kpl_cur = 2 + kp_l - rf->buf;
			continue;
		}
		//same idea for kp_h
		if ((dist < -SPLITKEY_MAXDIST) ||
			((kp_h - rf->buf) & 1)) {
			//dubious match
			//Find next kp_h, skip current occurence
			kph_cur = 2 + kp_h - rf->buf;
			continue;
		}

		key_offs = kp_h - rf->buf;
		*key_idx = keyset;
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
		return 0;
	}
	if (occurences > 1) {
		fprintf(dbg_stream, "warning : multiple keysets found !?\n");
	}
	return 1;

}

//find offset of LOADER struct, update romfile struct
//ret -1 if not ok
long find_loader(struct romfile *rf) {
	const uint8_t loadstr[]="LOADER";
	const uint8_t *sl;
	int loadv;

	if (!rf) return -1;
	if (!(rf->buf)) return -1;

	rf->loader_v = L_UNK;

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
	const struct fidtype_t *ft;	//helper
	assert(rf);

	ft = &fidtypes[rf->fidtype];

	if (ft->pRAMjump) {
		rf->ramf.pRAMjump = reconst_32(&rf->buf[rf->p_ramf + ft->pRAMjump]);
		rf->ramf.pRAM_DLAmax = reconst_32(&rf->buf[rf->p_ramf + ft->pRAM_DLAmax]);
	}

	if (ft->packs_start) {
		rf->p_acstart = reconst_32(&rf->buf[rf->p_ramf + ft->packs_start]);
		rf->p_acend = reconst_32(&rf->buf[rf->p_ramf + ft->packs_end]);
	} else {
		rf->p_acstart = -1;
		rf->p_acend = -1;
	}

	if (ft->pIVT2) {
		rf->p_ivt2 = reconst_32(&rf->buf[rf->p_ramf + ft->pIVT2]);
	} else {
		rf->p_ivt2 = -1;
	}

	return;
}


//find offset of FID struct, parse & update romfile struct. find_loader() must have been run before calling this.
//ret -1 if not ok
long find_fid(struct romfile *rf) {
	const uint8_t dbstr[]="DATAB";
	const uint8_t loadstr[]="LOADER";
	const uint8_t *sf;
	long sf_offset;	//offset in file
	int fid_idx;

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

	/* independant of loader version : */
	rf->fid = &rf->buf[sf_offset + offsetof(struct fid_base1_t, FID)];
	rf->fid_cpu = &rf->buf[sf_offset + offsetof(struct fid_base1_t, cpu)];

	rf->fidtype = FID_UNK;
	/* determine FID type : iterate through array of known types, matching the CPU string */
	for (fid_idx = 0; fidtypes[fid_idx].fti != FID_UNK; fid_idx++) {
		if (memcmp(rf->fid_cpu, fidtypes[fid_idx].FIDIC, 8) == 0) {
			rf->fidtype = fidtypes[fid_idx].fti;
			break;
		}
	}
	if (rf->fidtype == FID_UNK) {
		fprintf(dbg_stream, "Unknown FID IC type %.8s ! Cannot proceed\n", rf->fid_cpu);
		return -1;
	}

	if ((rf->fidtype == FID705507) || (rf->fidtype == FID705101)) {
		fprintf(dbg_stream, "Loader-less ROM.\n");
		rf->loader_v = L_UNK;
	}

	switch (rf->fidtype) {
	case FID705828:
		rf->sfid_size = sizeof(struct fid_base2_t);
		break;
	case FID705101:
	case FID705507:
	case FID705513:
	case FID705519:
	case FID705520:
	case FID705821:
	case FID705822:
	case FID705823:
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
		rf->p_acs = (unsigned long) (pacs - rf->buf);
		rf->p_acx = (unsigned long) (pacx - rf->buf);
		fprintf(dbg_stream, "confirmed altcks values found : acs @ 0x%lX, acx @ 0x%lX\n",
				rf->p_acs, rf->p_acx);
		rf->cks_alt_good = 1;
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
		long ramf_adj = 4;
		long sign = 1;
		fprintf(dbg_stream, "Unlikely contents for struct ramf; got 0x%lX.\n",
					(unsigned long) testval);
		while (ramf_adj < 0x300) {
			//search around, in a pattern like +4, -4, +8, -8, +12  and then +16, +20 etc
			testval = reconst_32(&rf->buf[rf->p_ramf + (sign * ramf_adj)]);
			if (testval == 0xffff8000) {
				fprintf(dbg_stream, "probable RAMF found @ delta = %+d\n",
							(int) (sign * ramf_adj));
				rf->ramf_offset = (sign * ramf_adj);
				rf->p_ramf += rf->ramf_offset;
				break;
			}
			if (ramf_adj < 0x0c) {
				sign = -sign;	//flip sign;
				if (sign == 1) ramf_adj += 4;
			} else {
				sign = 1;
				ramf_adj += 4;
			}
		}
	}

	parse_ramf(rf);
	if (fidtypes[rf->fidtype].pROMend) {
		testval = reconst_32(&rf->buf[rf->p_ramf + fidtypes[rf->fidtype].pROMend]);
		if (testval != (rf->siz -1)) {
			fprintf(dbg_stream, "ROMend field doesn't match ?\n");
		}
	}

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

	long pecurec = 0;
	//display some LOADER80-specific garbage
	if (fidtypes[rf->fidtype].pECUREC) {
		pecurec = reconst_32(&rf->buf[rf->p_ramf + fidtypes[rf->fidtype].pECUREC]);
		testval = reconst_32(&rf->buf[rf->p_ramf + fidtypes[rf->fidtype].pROMend]);

		//parse ECUREC
		if (pecurec < 0) {
			fprintf(dbg_stream, "unlikely pecurec = %lX\n", (unsigned long) pecurec);
		} else if ((pecurec + 6) <= rf->siz) {
			//skip leading '1'
			fprintf(dbg_stream, "probable ECUID : %.*s\n", 5,  &rf->buf[pecurec + 1]);
		}

		//validate ROM size
		if (testval != (rf->siz -1)) {
			fprintf(dbg_stream, "mismatched <romend> field : got %lX\n", (unsigned long) testval);
		}

		/* Locate RIPEMD-160 magic numbers */
		if ((u32memstr(rf->buf, rf->siz, 0x67452301) != NULL) &&
			(u32memstr(rf->buf, rf->siz, 0x98BADCFE) != NULL)) {
			rf->has_rm160 = 1;
			fprintf(dbg_stream, "RIPEMD-160 hash function present.\n");
		} else {
			fprintf(dbg_stream, "RIPEMD-160 hash function not found ??\n");
		}
		if ((pecurec < 0) || (pecurec >= rf->siz)) goto no_ripemd;

		/* Locate cks_alt2 checksum */
		long p_as = 0, p_ax = 0;
		long p_skip1, p_skip2;
		p_skip1 = (pecurec - 4) - pecurec;
		p_skip2 = (rf->p_ivt2 - 4) - pecurec;
		if (checksum_alt2(&rf->buf[pecurec], rf->siz - pecurec, &p_as, &p_ax, p_skip1, p_skip2) == 0) {
			fprintf(dbg_stream, "alt2 checksum found; sum @ 0x%lX, xor @ 0x%lX\n",
					(unsigned long) p_as, (unsigned long) p_ax);
			rf->cks_alt2_good = 1;
			rf->p_a2cs = p_as;
			rf->p_a2cx = p_ax;
		} else {
			fprintf(dbg_stream, "alt2 checksum not found ?? Bad algo, bad skip, or other problem...\n");
		}

	}
no_ripemd:

	return rf->p_ramf;
}



void find_eep(struct romfile *rf) {
	uint32_t port;
	uint32_t eepread = find_eepread(rf->buf, rf->siz, &port);
	if (eepread > 0) {
		rf->p_eepread = eepread;
		rf->eep_port = port;
	}
}

int main(int argc, char *argv[])
{
	bool	dbg_file;	//flag if dbgstream is a real file
	struct romfile rf = {0};
	long loaderpos;
	long fidpos;
	long ramfpos;

	if (argc !=2) {
		printf("%s <ROMFILE> : analyze 512k or 1M ROM.\n",argv[0]);
		return 0;
	}

	dbg_file = 1;
	dbg_stream = fopen(DBG_OUTFILE, "a");
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

	/* print column header */
	printf("file\tsize\tLOADER ##\tLOADER ofs\tLOADER CPU\tLOADER CPUcode\t"
		"&FID\tFID\tFID CPU\tFID CPUcode\t"
		"RAMF_weird\tRAMjump entry\tIVT2\tIVT2 confidence\t"
		"std cks?\t&std_s\t&std_x\t"
		"alt cks?\t&alt_s\t&alt_x\tack_start\t&ack_end\t"
		"alt2 cks?\t&alt2_s\t&alt2_x\tRIPEMD160\t"
		"known keyset\ts27k\ts36k\tguessed keyset\ts27k\ts36k\t"
		"&EEPROM_read()\tEEPROM PORT\t"
		"\n"
		);

	/* output file name + size */
	printf("%s\t%ldk\t", argv[1], rf.siz / 1024);

	/* output LOADER info : ##, pos, CPU, CPUcode*/
	loaderpos=find_loader(&rf);
	if (loaderpos >= 0) {
		const char *scpu;
		scpu = (const char *) rf.loader_cpu;
		printf("%0d\t0x%lX\t", rf.loader_v, (unsigned long) loaderpos);
		printf( "%.6s\t%.2s\t", scpu, scpu + 6);
	} else {
		printf("N/A\tN/A\tN/A\tN/A\t");
	}

	fidpos = find_fid(&rf);
	if (fidpos >= 0) {
		const char *sfid;
		const char *scpu;
		sfid = (const char *) rf.fid;
		scpu = (const char *) rf.fid_cpu;
		printf("0x%lX\t%.*s\t%.6s\t%.2s\t",
			(unsigned long) rf.p_fid, sizeof(((struct fid_base1_t *)NULL)->FID), sfid, scpu, scpu+6);

	} else {
		fprintf(dbg_stream, "error: no FID struct !?\n");
		printf("N/A\tN/A\tN/A\tN/A\t");
	}

	//"RAMF_off\RAMjump entry\tIVT2\tIVT2 confidence\t"
	ramfpos = find_ramf(&rf);
	if (ramfpos >= 0) {
		int ivt_conf = 0;
		printf("%+d\t0x%08X\t", rf.ramf_offset, rf.ramf.pRAMjump);
		if (rf.p_ivt2 > 0) {
			ivt_conf = 99;
		} else {
			long iter;
			fprintf(dbg_stream, "no IVT2 ?? wtf. Last resort, brute force technique:\n");
			iter = 0x100;	//skip power-on IVT
			bool ivtfound = 0;
			while ((iter + 0x400) < rf.siz) {
				long new_offs;
				new_offs = find_ivt(rf.buf + iter, rf.siz - iter);
				if (new_offs < 0) {
					if (ivtfound) break;
					fprintf(dbg_stream, "\t no IVT2 found.\n");
					break;
				}
				iter += new_offs;
				ivt_conf = 50;
				fprintf(dbg_stream, "\tPossible IVT @ 0x%lX\n",(unsigned long) iter);
				if (reconst_32(rf.buf + iter + 4) ==0xffff7ffc) {
					ivt_conf = 75;
					fprintf(dbg_stream, "\t\tProbable IVT !\n");
					ivtfound = 1;
				}
				iter += 0x4;
			}
		}
		printf("0x%lX\t0.%02d\t", (unsigned long) rf.p_ivt2, ivt_conf);

	} else {
		fprintf(dbg_stream, "find_ramf() failed !!\n");
		printf("N/A\tN/A\tN/A\tN/A\t");
	}

	//std cks	std_cks_s	std_cks_x
	if (!checksum_std(rf.buf, rf.siz, &rf.p_cks, &rf.p_ckx)) {
		printf("1\t0x%lX\t0x%lX\t",
			(unsigned long) rf.p_cks, (unsigned long) rf.p_ckx);
	} else {
		printf("0\tN/A\tN/A\t");
	}
	
	//alt cks?\t&alt_s\t&alt_x\tack_start\t&ack_end\talt2 cks?\t&alt2_s\t&alt2_x\tRIPEMD160
	if (rf.cks_alt_good) {
		printf("1\t0x%lX\t0x%lX\t0x%lX\t0x%lX\t",
			(unsigned long) rf.p_acs, (unsigned long) rf.p_acx,
			(unsigned long) rf.p_acstart, (unsigned long) rf.p_acend);
	} else {
		printf("0\tN/A\tN/A\tN/A\tN/A\t");
	}

	if (rf.cks_alt2_good) {
		printf("1\t0x%lX\t0x%lX\t",
			(unsigned long) rf.p_a2cs, (unsigned long) rf.p_a2cx);
	} else {
		printf("0\tN/A\tN/A\t");
	}

	if (rf.has_rm160) {
		printf("1\t");
	} else {
		printf("0\t");
	}


	//known s27k s36k guessed s27k s36k
	int key_idx;
	if (find_s27k(&rf, &key_idx, 0)) {
		printf("1\t0x%08lX\t0x%08lX\t",
			(unsigned long) known_keys[key_idx].s27k, (unsigned long) known_keys[key_idx].s36k1);
	} else {
		printf("0\tN/A\tN/A\t");
	}
	uint32_t s27k, s36k;
	if (find_s27_hardcore(rf.buf, rf.siz, &s27k, &s36k)) {
		printf("1\t0x%08X\t0x%08X\t",
			s27k, s36k);
	} else {
		printf("0\tN/A\tN/A\t");
	}

	// EEPROM info
	find_eep(&rf);
	if (rf.p_eepread) {
		printf("0x%lX\t0x%08lX\t",
			(unsigned long) rf.p_eepread, (unsigned long) rf.eep_port);
	} else {
		printf("N/A\tN/A\t");
	}

	//test : find calltable
	unsigned ctlen = 0;
	uint32_t ctpos = 0;
	while (1) {
		ctpos = find_calltable(rf.buf, ctpos + ctlen * 4, rf.siz, &ctlen);
		if (ctpos == -1) break;
		fprintf(dbg_stream, "possible calltable @ %lX, len=0x%X\n", (unsigned long) ctpos, ctlen);
	}

	printf("\n");
	close_rom(&rf);
	if (dbg_file) fclose(dbg_stream);
	return 0;
}
