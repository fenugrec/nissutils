/* (c) fenugrec 2015-2022
 * functions to locate SID27/36 keys in ROM dumps
 * GPLv3
 *
 */

#include <assert.h>
#include <limits.h>
#include <stddef.h>	//for offsetof()
#include <stdint.h>
#include <stdio.h>
#include <string.h>	//memcmp
#include <stdlib.h>	//malloc etc

#include "nislib.h"
#include "nislib_shtools.h"
#include "nisrom_keyfinders.h"

#include "stypes.h"


#define ERR_PRINTF(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)


#define SPLITKEY_MAXDIST 16
/** find literal key
 *
 * @param thorough : continue search for multiple occurences
 *
 * @return 1 if ok
 *
 * this does no code analysis, only looking for two halfkeys stored nearby.
 */
static bool find_key_literal(const u8 *buf, u32 siz, u32 key, bool thorough) {
	assert(buf && siz);

	u32 kph_cur = 0;
	int occurences = 0;

	while (kph_cur + 2 < siz) {
		const uint8_t *kp_h, *kp_l;
		uint16_t ckh, ckl;
		ckh = key >> 16;
		ckl = key >> 0;

		/* find one 16bit half */
		kp_h = u16memstr(buf + kph_cur, siz - kph_cur, ckh);
		if (kp_h == NULL) {
			// no match: abort
			return 0;
		}
		u32 kp_h_pos = (kp_h - buf);

		/* got one half; search for other close by */
		u32 start_offs = kp_h_pos - MIN(SPLITKEY_MAXDIST, kp_h_pos);	//start a bit before kp_h
		u32 end_offs = MIN(kp_h_pos + SPLITKEY_MAXDIST, siz - 2);	//don't overflow
		kp_l = u16memstr(buf + start_offs, end_offs - start_offs, ckl);
		if (kp_l == NULL) {
			// no match: try to find more occurences of kp_h.
			kph_cur = end_offs;
			continue;
		}

		fprintf(dbg_stream, "Key %lX found near 0x%lX !\n", (unsigned long) key, (unsigned long) kp_h_pos);
		occurences += 1;
		if (thorough) {
			kph_cur = end_offs;
			continue;
		}
		break;

	}	//while

	if (occurences > 1) {
		fprintf(dbg_stream, "warning : multiple copies of key found !?\n");
	}
	return 1;

}



const struct keyset_t *find_keys_bruteforce(const u8 *buf, u32 siz, enum key_quality *keyq, bool thorough) {
	int keyset=0;

	assert(buf && siz && keyq);

	/* method 1 (removed) : search for every known key with u32memstr. Was not very effective.
	 */

	/* method 2 : search as two 16bit halves close by;
	 * this is slower but much better.
	 */

	keyset = 0;
	u32 s27k = 0;
	u32 s36k1 = 0;
	bool rv;

	while (known_keys[keyset].s27k != 0) {
		s27k = known_keys[keyset].s27k;
		rv = find_key_literal(buf, siz, s27k, thorough);
		if (rv) {
			*keyq = KEYQ_BRUTE_1;
			//best scenario : also find matching s36k1
			s36k1 = known_keys[keyset].s36k1;
			rv = find_key_literal(buf, siz, s36k1, thorough);
			if (rv) {
				fprintf(dbg_stream, "found literal s27 and s36, keyset %lX\n", (unsigned long) s27k);
				*keyq = KEYQ_BRUTE_BOTH;
				return &known_keys[keyset];
			}
			fprintf(dbg_stream, "found only literal s27, keyset %lX\n", (unsigned long) s27k);
			return &known_keys[keyset];
		}
		keyset += 1;
	}

	// no s27k found, try s36.
	while (known_keys[keyset].s36k1 != 0) {
		s36k1 = known_keys[keyset].s36k1;
		rv = find_key_literal(buf, siz, s36k1, thorough);
		if (rv) {
			fprintf(dbg_stream, "found only literal s36k1, keyset %lX\n", (unsigned long) known_keys[keyset].s27k);
			*keyq = KEYQ_BRUTE_1;
			return &known_keys[keyset];
		}
	}

	fprintf(dbg_stream, "found no literal keys\n");
	return NULL;
}


struct s27_keyfinding {
	int swapf_xrefs;	//# of occurences
	bool s27_found;
	bool s36_found;
	u32 s27k_pos;	//position in ROM
	u32 s36k_pos;
	uint32_t *s27k;
	uint32_t *s36k;		//where to store the keys found
};

/** callback for every "bsr swapf" hit
 *
 * @param data is a (struct s27_keyfinding *)
 */
static void found_strat1_bsr(const u8 *buf, u32 pos, void *data) {
	struct s27_keyfinding *skf;

	assert(buf && (pos < MAX_ROMSIZE) && data);

	fprintf(dbg_stream, "found bsr swapf at %lX\n", (unsigned long) pos);
	skf = data;
	skf->swapf_xrefs += 1;
	/* now, backtrack to find constants */
	/* TODO : determine if the key is for sid27 or sid36; this just assumes that the first key we find
	 * is the s36 one. This has been true for a lot of ROMs, but is just lucky. */
	uint32_t key;
	key = fs27_bt_stmem(buf, pos);
	if (key && skf->s36_found) {
		*skf->s27k = key;
		skf->s27k_pos = pos;
		skf->s27_found = 1;
	} else if (key) {
		*skf->s36k = key;
		skf->s36k_pos = pos;
		skf->s36_found = 1;
	}
	return;
}

/** callback for every bsr encrypt() for second sid27 strategy.
 *
 * @param data is a (struct s27_keyfinding *)
 *
 * could be either in sid27 or sid36 function, but what seems to be common
 * (6GE2C, EZ11D) is to write both halfkeys to consecutive RAM locations,
 * with a MOV.W R0, @(disp, Rn)
 *
 * Can't directly use fs27_bt_stmem() since that is too permissive
 */
static void found_strat2_bsr(const u8 *buf, u32 pos, void *data) {
#define S27_STRAT2_MOVW_MAXDIST	40
#define S27_STRAT2_IMMLOAD_MAXBT 60
	assert(buf && data);

	// backtrack and search for a MOV.W R0, @(disp, Rn) 10000001nnnndddd
	u32 movw_pos;
	u32 min_pos = pos - MIN(pos, S27_STRAT2_MOVW_MAXDIST);

	enum opcode_dest reg_dest;
	unsigned mem_disp = 0;

	bool found = bt_MOVW_R0_REGDISP(buf, pos, min_pos, &movw_pos, &reg_dest, &mem_disp);
	if (!found) {
		fprintf(dbg_stream, "found a weird strat2 bsr @ %lX. Look here for sid27 / sid36 keys !\n", (unsigned long) pos);
		return;
	}
	fprintf(dbg_stream, "found a strat2 bsr @ %lX. Look here for sid27 / sid36 keys !\n", (unsigned long) pos);

	// next : find value loaded into R0 , this is KEY_L
	u16 key_l, key_h;
	u32 imm_temp;
	if (sh_bt_immload(&imm_temp, buf, movw_pos - MIN(movw_pos, S27_STRAT2_IMMLOAD_MAXBT), movw_pos, 0)) {
		//probably found a halfkey
		key_l = (u16) imm_temp & 0xFFFF;
		fprintf(dbg_stream, "halfkey 0x%04X\n", (unsigned) key_l);
	} else {
		//can't continue
		return;
	}

	//continue movw search but keep only hits that write to mem_disp +/- 2
	unsigned original_memdisp = mem_disp;	//displacement where key_l was stored
	enum opcode_dest original_regdest = reg_dest;
	found = 0;
	min_pos = movw_pos - MIN(movw_pos, S27_STRAT2_MOVW_MAXDIST);
	movw_pos = movw_pos - MIN(movw_pos, 2);	//go back 1 opcode
	while (!found && movw_pos) {
		if (!bt_MOVW_R0_REGDISP(buf, movw_pos, min_pos, &movw_pos, &reg_dest, &mem_disp)) {
			// no hit in window : can't continue.
			return;
		}
		bool correct_destination = ( ((mem_disp + 2) == original_memdisp) ||
						((mem_disp - 2) == original_memdisp));
		if ( !correct_destination ||
			(reg_dest != original_regdest)) {
			// found a movw but wrong destination or wrong base reg : keep looking
			movw_pos = movw_pos - MIN(movw_pos, 2);	//go back 1 opcode
			continue;
		}
		if (sh_bt_immload(&imm_temp, buf, movw_pos - MIN(movw_pos, S27_STRAT2_IMMLOAD_MAXBT), movw_pos, 0)) {
			key_h = (u16) imm_temp & 0xFFFF;
			fprintf(dbg_stream, "halfkey 0x%04X\n", (unsigned) key_h);
			found = 1;
		}
		break;
	}

	if (!found) {
		fprintf(dbg_stream, "strat2 couldn't find other halfkey\n");
		return;
	}
	u32 key_candidate = (key_h << 16) + key_l;
	if (key_candidate == 0) {
		//very unlikely, and will break a few lines later
		return;
	}

	// not sure if we found a s27 or s36 key. Best scenario is finding it in known keysets.
	// Assign the other without setting the _found flag
	struct s27_keyfinding *skf = data;
	const struct keyset_t *keyset;

	keyset = find_knownkey(KEY_S27, key_candidate);
	if (keyset) {
		skf->s27_found = 1;
		*skf->s27k = key_candidate;
		skf->s27k_pos = movw_pos;
		*skf->s36k = keyset->s36k1;
	}

	keyset = find_knownkey(KEY_S36K1, key_candidate);
	if (keyset) {
		skf->s36_found = 1;
		*skf->s36k = key_candidate;
		skf->s36k_pos = movw_pos;
		*skf->s27k = keyset->s27k;
	}

	keyset = find_knownkey(KEY_S36K2, key_candidate);
	if (keyset) {
		fprintf(dbg_stream, "strat2 indirectly found a known SID36k2 : 0x%08lX\n", (unsigned long) key_candidate);
	}
	return;
}

/* Second strategy (designed for SH705927) :
 - find sequence of shlr and xor opcodes targeting the same reg. Example from 6GE2C:
	0004398c 45 29           shlr16     r5
	0004398e 35 1c           add        r1,r5
	00043990 25 7a           xor        r7,r5
	00043992 25 2a           xor        r2,r5
	00043994 00 0b           rts
 * this is part of a short encrypt() function that uses the lower halfkey. Currently does not discover new keysets.
 */

#define S27_STRAT2_PATLEN 3
static const uint16_t spf2_pattern[]={0x4529, 0x351c, 0x257a, 0x252a, 0x000b};
static const uint16_t spf2_mask[]={0xf0ff, 0xf00f, 0xf00f, 0xf00f, 0xffff};
#define S27_STRAT2_MAX_FUNCLEN 0x30	// max distance between function entry and start of pattern. Typically around 0x22

enum key_quality find_s27_strat2(const uint8_t *buf, uint32_t siz, uint32_t *s27k, uint32_t *s36k) {
	assert(buf && siz && (siz <= MAX_ROMSIZE) && s27k && s36k);

	struct s27_keyfinding skf={0};
	skf.s27k = s27k;
	skf.s27_found = 0;
	skf.s36k = s36k;
	skf.s36_found = 0;
	skf.swapf_xrefs = 0;	//xrefs to "encrypt" func ; should be 2, one from each S27 and S36 func

	u32 swapf_cur = 0;

	while ( swapf_cur < (siz - S27_STRAT2_MAX_FUNCLEN)) {
		u32 patpos;
		patpos = find_pattern(&buf[swapf_cur], siz - swapf_cur,
			S27_STRAT2_PATLEN, spf2_pattern, spf2_mask);
		if (patpos == UINT32_MAX) break;
		assert((patpos & 1) == 0);

		patpos += swapf_cur;	//re-adjust to a rom_offset !
		swapf_cur = patpos + 2;

		// backtrack to guess function entry , by looking for previous RTS opcode.
		u32 searchlength = MIN(patpos, S27_STRAT2_MAX_FUNCLEN);	//safe clamp
		u32 startpos = patpos - searchlength;
		const u8 *maybe_entry = u16memstr_rev(&buf[startpos], searchlength, 0x000b);

		if (!maybe_entry) {
			fprintf(dbg_stream, "found a weird encrypt() pattern @ %lX\n", (unsigned long) patpos);
			continue;
		}
		u32 func_entry = (u32) (maybe_entry - buf) + 4;	//skip over RTS and slot opcode

		fprintf(dbg_stream, "found a likely encrypt() func @ %lX\n", (unsigned long) func_entry);

		/* Find xrefs (bsr) to this possible encrypt() instance. */
		find_bsr(buf, func_entry, found_strat2_bsr, &skf);
	}

	if (skf.s27_found && skf.s36_found) {
		fprintf(dbg_stream, "strat2 found known keys @ 0x%06lX, 0x%06lX\n",
				(unsigned long) skf.s27k_pos, (unsigned long) skf.s36k_pos);
		return KEYQ_STRAT_BOTH;
	}
	if (skf.s27_found) {
		fprintf(dbg_stream, "strat2 found s27k @ 0x%06lX\n",
				(unsigned long) skf.s27k_pos);
		return KEYQ_STRAT_1;
	}
	if (skf.s36_found) {
		fprintf(dbg_stream, "strat2 found new s36 @ 0x%06lX\n",
				(unsigned long) skf.s36k_pos);
		return KEYQ_STRAT_1;
	}
	return KEYQ_UNK;
}


/* First strategy to find SID 27 keys :
 - find "swapf" function used by both encr / decryption
 - find xrefs to "swapf" (exactly 2)
 - follow xref
 */

#define S27_SPF_PATLEN 5
static const uint16_t spf_pattern[]={0x6001, 0x6001, 0x2001, 0x000b, 0x2001};
static const uint16_t spf_mask[]={0xf00f, 0xf00f, 0xf00f, 0xffff, 0xf00f};

enum key_quality find_s27_strat1(const uint8_t *buf, uint32_t siz, uint32_t *s27k, uint32_t *s36k) {
	uint32_t swapf_cur = 0;
	//int swapf_instances = 0;

	assert(buf && siz && (siz <= MAX_ROMSIZE) && s27k && s36k);

	struct s27_keyfinding skf={0};
	skf.s27k = s27k;
	skf.s27_found = 0;
	skf.s36k = s36k;
	skf.s36_found = 0;
	skf.swapf_xrefs = 0;


	while ( swapf_cur < siz ) {
		uint32_t patpos;
		patpos = find_pattern(&buf[swapf_cur], siz - swapf_cur,
			S27_SPF_PATLEN, spf_pattern, spf_mask);
		if (patpos == (u32) -1) break;
		patpos += swapf_cur;	//re-adjust !
		//swapf_instances +=1 ;
		//printf("got 1 swapf @ %0lX;\n", patpos + 0UL);

		/* Find xrefs (bsr) to this swapf instance. */
		find_bsr(buf, patpos, found_strat1_bsr, &skf);

		swapf_cur = patpos + 2;

	}

	const struct keyset_t *tmp27 = NULL;
	const struct keyset_t *tmp36 = NULL;
	if (skf.s27_found) {
		tmp27 = find_knownkey(KEY_S27, *s27k);
	}
	if (skf.s36_found) {
		tmp36 = find_knownkey(KEY_S36K1, *s36k);
	}
	if (tmp27 && tmp36) {
		if (tmp27 != tmp36) {
			//weird, shouldn't happen
			fprintf(dbg_stream, "strat1 found mismatched keys !?  %lX @ %lX, %lX @ %lX\n",
					(unsigned long) *s27k, (unsigned long) skf.s27k_pos,
					(unsigned long) *s36k, (unsigned long) skf.s36k_pos);
			return KEYQ_STRAT_1;
		}
		fprintf(dbg_stream, "strat1 found full keyset %lX @ %lX\n",
				(unsigned long) *s27k, (unsigned long) skf.s27k_pos);
		return KEYQ_STRAT_BOTH;
	}
	if (skf.s27_found && skf.s36_found) {
		fprintf(dbg_stream, "strat1 found new s27k @ 0x%06lX, s36k1 @ 0x%06lX\n",
				(unsigned long) skf.s27k_pos, (unsigned long) skf.s36k_pos);
		return KEYQ_STRAT_2NEW;
	}
	if (skf.s27_found) {
		fprintf(dbg_stream, "strat1 found new s27k @ 0x%06lX\n",
				(unsigned long) skf.s27k_pos);
		return KEYQ_STRAT_1NEW;
	}
	if (skf.s36_found) {
		fprintf(dbg_stream, "strat1 found new s36 @ 0x%06lX\n",
				(unsigned long) skf.s36k_pos);
		return KEYQ_STRAT_1NEW;
	}
	return KEYQ_UNK;

}

/** try to guess SID27 keys using cleverness and gnarly heuristics.
 *
 * This can either find a known keyset, or discover new keys.
 * If a strategy only finds either a s27 or s36 key but is part of a known keyset, it will
 * also assign the other key. I.e. it's unlikely that one of these methods would produce a value that
 * is wrong, but coincidentally part of a known keyset.
*/
enum key_quality find_s27_hardcore(const uint8_t *buf, uint32_t siz, uint32_t *s27k, uint32_t *s36k) {
	assert(buf && siz && (siz <= MAX_ROMSIZE) && s27k && s36k);

	enum key_quality keyq;

	keyq = find_s27_strat1(buf, siz, s27k, s36k);
	if (keyq > KEYQ_UNK) {
		return keyq;
	}

	keyq = find_s27_strat2(buf, siz, s27k, s36k);
	if (keyq > KEYQ_UNK) {
		return keyq;
	}

	return KEYQ_UNK;
}
