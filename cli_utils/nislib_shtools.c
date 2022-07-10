/* collection of funcs for working with SuperH ROMs
 * (c) fenugrec 2014-2022
 * GPLv3
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>	//for printf(); probably can go away someday
#include <string.h>
#include <stdbool.h>
#include "nislib.h"
#include "nislib_shtools.h"
#include "sh_opcodes.h"
#include "stypes.h"


uint32_t sh_get_PCimm(const uint8_t *buf, uint32_t pos) {
	uint16_t opc;

	assert(buf);

	opc = reconst_16(&buf[pos]);

	if (opc & 0x4000) {
		//mov.l
		pos += ((opc & 0xFF) * 4) + 4;
		/* essential : align 4 !!! */
		pos &= ~0x03;
		//printf("retrieve &er() from 0x%0X\n", pos);
		pos = reconst_32(&buf[pos]);
	} else {
		//mov.w
		u16 lit;
		pos += ((opc & 0xFF) * 2) + 4;
		//printf("retrieve &er() from 0x%0X\n", pos);
		lit = reconst_16(&buf[pos]);
		pos = sh_extsw(lit);	//sign-extend
	}
	return pos;
}


uint32_t find_pattern(const uint8_t *buf, uint32_t siz, unsigned patlen,
			const uint16_t *pat, const uint16_t *mask) {
	uint32_t bcur = 0;	//base cursor for start of pattern
	uint32_t hcur = 0;	//iterating cursor
	unsigned patcur = 0;	//cursor within pattern

	assert(buf && siz && patlen && pat && mask &&
		(siz <= MAX_ROMSIZE));

	while (hcur < (siz - patlen * 2)) {
		uint16_t val;
		val = reconst_16(&buf[hcur + patcur * 2]);
		if ((val & mask[patcur]) == (pat[patcur] & mask[patcur])) {
			if (patcur == 0) bcur = hcur;
			patcur += 1;
			if (patcur == patlen) {
				//complete match !
				return bcur;
			}
			continue;
		}
		//no match : continue where we started
		patcur = 0;
		//hcur = bcur;
		hcur += 2;
	}
	//no match : ret -1 (illegal val)
	return -1;
}


/** sign-extend u8 value to u32, like exts.b */
u32 sh_extsb(u8 val) {
	if (val & 0x80) return 0xFFFFFF00 | val;
	return val;
}

/** Sign-extend u16 value to u32, like exts.w */
u32 sh_extsw(u16 val) {
	if (val & 0x8000) return 0xFFFF0000 | val;
	return val;
}




int sh_bt_immload(u32 *imm, const uint8_t *buf, uint32_t min, uint32_t start,
				unsigned regno) {


	assert(imm && buf && (regno <= 0x0F));

	while (start >= min) {
		unsigned new_regno;
		uint16_t opc = reconst_16(&buf[start]);

		// 1) limit search to function head. Problem : sometimes this opcode is not at the head of the function !
		//if (opc == 0x4F22) return 0;

		// 2a) if we're copying from another reg, we need to recurse. opc format :
		// mov Rm, R(regno) [6n m3]
		if ((opc & 0xFF0F) == (0x6003 | (regno << 8))) {
			start -= 2;
			new_regno = (opc & 0xF0) >> 4;

			if (sh_bt_immload(imm, buf, min, start, new_regno)) {
				//Suxxess : found literal
				return 1;
			}
			// recurse failed; probably loaded from arglist or some other shit
			return 0;
		}

		// 2b) if we had a "shlr16" into regno, recurse too and shift immediate before returning.
		if (opc == (0x4029 | (regno << 8))) {
			u32 new_bt;
			start -= 2;

			if (sh_bt_immload(&new_bt, buf, min, start, regno)) {
				//Suxxess : found literal
				*imm = new_bt >> 16;
				return 1;
			}
			// recurse failed; probably loaded from arglist or some other shit
			return 0;
		}

		// 2c) EXTU.B Rm,Rn 0110nnnnmmmm1100 : special case of mov R,R : also recurse
		if ((opc & 0xFF0F) == (0x600C | (regno << 8))) {
			u32 new_bt;
			new_regno = (opc >> 4) & 0x0F;	//follow Rm
			start -= 2;

			if (sh_bt_immload(&new_bt, buf, min, start, new_regno)) {
				*imm = new_bt & 0xFF;
				return 1;
			}
			return 0;
		}

		// 2d) shll, shll2 : recurse and shift before returning
		if ((opc & 0xFFF7) == (0x4000 | (regno << 8))) {
			u32 new_bt;
			bool is_shll2 = (opc & 0x0008);

			start -= 2;
			//printf("\t\t***********shll @ %lX\n", (unsigned long) start);

			if (sh_bt_immload(&new_bt, buf, min, start, regno)) {
				if (is_shll2) {
					*imm = (new_bt << 2);
				} else {
					*imm = (new_bt << 1);
				}
				return 1;
			}
			return 0;
		}

		// 2d.5) SHLL8 Rn  0100nnnn00011000
		if (opc == (0x4018 | regno << 8)) {
			u32 new_bt;
			start -= 2;

			if (sh_bt_immload(&new_bt, buf, min, start, regno)) {
				//Suxxess : found literal
				*imm = new_bt << 8;
				return 1;
			}
			// recurse failed; probably loaded from arglist or some other shit
			return 0;
		}


		// 2e) add imm8: recurse and add before returning. b'0111nnnniiiiiiii'
		if ((opc & 0xFF00) == (0x7000 | (regno << 8))) {
			u32 add_s8;
			u32 new_bt;
			add_s8 = sh_extsb(opc & 0xFF);
			start -= 2;
			//printf("\t\t***********add @ %lX\n", (unsigned long) start);

			if (sh_bt_immload(&new_bt, buf, min, start, regno)) {
				*imm = (new_bt + add_s8);
				return 1;
			}
			return 0;
		}

		// 2f) add Rm, R<regno>: recurse for Rm and regno again; add before ret
		//ADD Rm,Rn 0011nnnnmmmm1100 Rn + Rm => Rn
		if ((opc & 0xFF0F) == (0x300C | (regno << 8))) {
			u32 add_src, add_src2;

			start -= 2;
			//printf("add rm, regno : recurs @ %X\n", start);
			new_regno = (opc >> 4) & 0x0F;
			if (sh_bt_immload(&add_src, buf, min, start, new_regno)) {
				//found Rm
				if (sh_bt_immload(&add_src2, buf, min, start, regno)) {
					//found Rn too
					*imm = (add_src + add_src2);
					return 1;
				}
			}
			return 0;
		}

		// 3) no recursion : try to find load_immediate.
		// "mov #imm8, R<regno>"	[E<regno> <i>]
		// "mov.w @(disp, PC), R<regno> 	[9<regno> <disp/2>]
		// "mov.l @(disp, PC), R<regno> 	[D<regno> <disp/4>]
		// "movi20 #imm20, R<regno>	[0<regno> <i16_19> 0][i0_15]
		// test for the "movi20" variant first, because it takes up 2 opcodes
		uint16_t prevop = reconst_16(&buf[start - 2]);
		if ((prevop & 0xFF0F) == (regno << 8)) {
			//movi20 match. just keep lower 16 bits sign-extended
			*imm = sh_extsw(opc);
			return 1;
		}
		uint8_t ic_top = (opc & 0xFF00) >> 8;
		uint32_t imloc = start; //location of mov instruction
		if (ic_top == (0xD0 | regno)) {
			//imm32 with possible shift16
			imloc += ((opc & 0xFF) * 4) + 4;
			/* essential : align 4 !!! */
			imloc &= ~0x03;
			//printf("retrieve &er() from 0x%0X\n", jackpot);
			*imm = reconst_32(&buf[imloc]);
			return 1;
		}
		if (ic_top == (0x90 | regno)) {
			//imm16
			imloc += ((opc & 0xFF) * 2) + 4;
			//printf("retrieve &er() from 0x%0X\n", jackpot);
			*imm = sh_extsw(reconst_16(&buf[imloc]));
			return 1;
		}
		if (ic_top == (0xE0 | regno)) {
			//imm8
			*imm = sh_extsb(opc & 0xFF);
			return 1;
		}

		if (sh_getopcode_dest(opc) == regno) {
			//Rn clobbered
			return 0;
		}

		start -= 2;

	}	//while
	return 0;
}


/* Find all "bsr N" occurences that call the function at <tgt>.
 * for every hit, calls <callback>(<data>), a generic proto
 */
void find_bsr(const u8 *buf, u32 tgt, void (*found_bsr_cb)(const u8 *buf, u32 pos, void *data), void *cbdata) {

	/*
	 * bsr opcode : 1011 dddd dddd dddd
	 * displacement range = 2*disp == [-4096, +4094] + PC
	 *
	 */
	int sign = 1;
	int disp = 0;

	assert(buf && (tgt < MAX_ROMSIZE) && found_bsr_cb);

	/* iterate, starting at the position where the opcode "B0 00" would jump to "swapf". */
	while ((sign * disp) != -4096) {
		uint16_t opc;
		uint32_t bsr_offs = tgt - 4 - (sign * disp);
		opc = reconst_16(&buf[bsr_offs]);
		// is it a "bsr" with the correct offset ?
		if (opc == (0xB000 | ((sign * disp / 2) & 0xFFF))) {
			found_bsr_cb(buf, bsr_offs, cbdata);
		}
		sign = -sign;
		if (sign == 1) disp +=2 ;
	}
	return;

}


bool bt_MOVW_R0_REGDISP(const u8 *buf, u32 startpos, u32 min, u32 *found_pos, enum opcode_dest *reg_dest, unsigned *disp) {
	assert(buf && found_pos && reg_dest && disp);

	startpos += 2;	//cheat
	while (startpos && (startpos > min)) {
		startpos -= 2;
		u16 test = reconst_16(&buf[startpos]);

		if (!IS_MOVW_R0_REGDISP(test)) {
			continue;
		}
		*found_pos = startpos;
		*reg_dest = (test >> 4) & 0x0F;
		*disp = (test & 0x0F) * 2;
		return 1;
	}
	return 0;
}

/* unreliable - check if opcode at *buf could be a valid func prologue.
 * for now, accepts :
 * "2F <Rn>6" (mov.l Rn, @-r15)
 * "4F 22 (sts.l pr, @-r15)
 */
static bool sh_isprologue(const uint8_t *buf) {
	uint16_t opc;
	assert(buf);

	opc = reconst_16(buf);
	if (	((opc & 0xFF0F) == 0x2F06) ||
		(opc == 0x4F22)) {
		return 1;
	}
	return 0;
}


#define FCALLTABLE_MINLENGTH 50	//typically > 100 function pointers though
#define FCALLTABLE_IVTSKIP 0x400	//skip any IVT found
#define FCALLTABLE_PROLOGS 10		//ugly hack to recognize function prologues
#define FCALLTABLE_MAXDUPS 10		//discard table if too many duplicate ptrs (like in IVTs)

uint32_t find_calltable(const uint8_t *buf, uint32_t skip, uint32_t siz, unsigned *ctlen) {
	uint32_t cur;
	unsigned consec = 0;
	unsigned good_prologs = 0;
	uint32_t table_start;
	uint32_t dupcheck = 0;
	unsigned dupcount = 0;

	siz &= ~3;
	assert(buf && siz && (siz <= MAX_ROMSIZE) && ctlen && (skip < siz));

	cur = skip & ~3;
	table_start = cur;
	for (; cur < (siz - 4); cur += 4) {
		uint32_t tv;

		//skip IVTs if applicable
		if ((siz - cur) > FCALLTABLE_IVTSKIP) {
			if (check_ivt(&buf[cur], (siz - cur))) {
				cur += FCALLTABLE_IVTSKIP;
				table_start = cur + 4;
				consec = 0;
				good_prologs = 0;
				dupcount = 0;
				continue;
			}
		}

		tv = reconst_32(&buf[cur]);
		if (!consec) {
			//just started : save first val
			dupcheck = tv;
		} else {
			//check if duplicated
			if (dupcheck == tv) dupcount += 1;
			if (dupcount >= FCALLTABLE_MAXDUPS) {
				//reset
				table_start = cur + 4;
				consec = 0;
				good_prologs = 0;
				dupcount = 0;
				continue;
			}
		}

		if ((tv >= (uint32_t) siz) ||
			(tv & 1)) {
			//invalid / unaligned func ptr. Maybe end of valid table :
			if (	(consec >= FCALLTABLE_MINLENGTH) &&
				(good_prologs >= FCALLTABLE_PROLOGS)) goto goodexit;
			//else Reset.
			table_start = cur + 4;
			consec = 0;
			good_prologs = 0;
			dupcount = 0;
			continue;
		}
		//valid func ptr; check if it points to valid code (not rigorous)
		if (sh_isprologue(&buf[tv])) {
			good_prologs += 1;
		}

		consec += 1;
	}
	return -1;
goodexit:
	*ctlen = consec;
	return table_start;
}




/* for bt,bf sign-extended offsets : return PC+4+ (exts.b offset)<<1 */
u32 disarm_8bit_offset (u32 pos, u32 offs) {
	/* sign extend if higher bit is 1 (0x08) */
	if ((offs & 0x80) == 0x80)
		offs |= ~0xFF;
	return (offs<<1) + pos + 4;
}

/* for {bra,bsr} only: (sign-extend 12bit offset)<<1 + PC +4 */
u32 disarm_12bit_offset (u32 pos, u32 insoff) {
	u32 off = insoff;
	/* sign extend if higher bit is 1 (0x0800) */
	if ((off & 0x0800) == 0x0800)
		off |= ~0xFFF;
	return (pos) + (off<<1) + 4;
}

enum opcode_dest sh_getopcode_dest(u16 code) {

	if (IS_MOVB_R0REL_TO_REG(code) || (IS_MOVW_R0REL_TO_REG(code)) || (IS_MOVL_R0REL_TO_REG(code)) ||
		IS_MOVT(code) || (IS_STSMAC(code)) || (IS_STCSR1(code)) || IS_STSPR(code)
		) {
		return GET_TARGET_REG(code);
	}
	if (IS_AND_REGS(code) || IS_XOR_REGS(code) || IS_OR_REGS(code) || IS_XTRCT(code)
		) {
		return GET_TARGET_REG(code);
	}
	if (IS_ADD(code) || IS_ADDC(code) || IS_ADDV(code) ||
		IS_SUB(code) || IS_SUBC(code) || IS_SUBV(code)
		) {
		return GET_TARGET_REG(code);
	}
	if (IS_ROT(code) || IS_SHIFT1(code) || IS_DT(code)
		) {
		return GET_TARGET_REG(code);		//incomplete
	}
	if ((code & 0xF000) == 0x5000) {
		return GET_TARGET_REG(code);
	}
	if ((code & 0xF000) == 0x6000) {
		return GET_TARGET_REG(code);
	}
	if ((code & 0xF000) == 0x7000) {
		return GET_TARGET_REG(code);
	}
	if (IS_MOVB_REGDISP_R0(code) || IS_MOVW_REGDISP_R0(code)
		) {
		return 0;
	}
	if ((code & 0xF000) == 0x9000) {
		return GET_TARGET_REG(code);
	}
	if (IS_MOVA_PCREL_R0(code) || IS_BINLOGIC_IMM_R0(code) ||
		IS_MOVB_GBRREF_R0(code) || IS_MOVW_GBRREF_R0(code) || IS_MOVL_GBRREF_R0(code)
		) {
		return 0;
	}
	if ((code & 0xF000) == 0xD000) {
		return GET_TARGET_REG(code);
	}
	if ((code & 0xF000) == 0xE000) {
		return GET_TARGET_REG(code);
	}
	return OPC_DEST_OTHER;
}


#define SH_TRACK_REG_MAXRECURSE 2000	//Hitting this limit is definitely abnormal and possibly indicates a bug
/* recursive reg tracker.
 * The visited[] cells are bitfielsd : when a certain location has been parsed
 * while tracking a certain reg, the corresponding bit (1 << regno) is set.
 * To fit inside a u16 value, gbr is aliased to r15 since r15 is normally only
 * used as a stack ptr. */
void sh_track_reg(const u8 *buf, u32 pos, u32 siz, unsigned regno, u16 *visited,
			void (*tracker_cb)(const uint8_t *buf, uint32_t pos, unsigned regno, void *data), void *cbdata) {

	static int recurselevel = 0;
	recurselevel += 1;

	assert(buf && siz && (siz <= MAX_ROMSIZE) && (pos < siz) &&
				(regno <= 0x0F) && visited && tracker_cb);

	if (recurselevel >= SH_TRACK_REG_MAXRECURSE) {
		printf("Warning : hit maximum recursion depth @ %lX!!\n", (unsigned long) pos);
		goto endrec;
	}

	for (; pos < siz; pos += 2) {
		unsigned aliased_regno = regno;
		if (aliased_regno > 15) aliased_regno = 15;

		if (visited[pos] & (1 << aliased_regno)) {
			//deja vu with this reg
			goto endrec;
		}
		visited[pos] |= (1 << aliased_regno);

		u16 opc = reconst_16(&buf[pos]);

		//end recursion if we hit RTS
		if (IS_RTS(opc) || IS_RTE(opc)) {
			//go check next opcode for delay slot
			tracker_cb(buf, pos + 2, regno, cbdata);
			goto endrec;
		}

		if (regno < 16) {
			//new recurse if match mov Rm, Rn
			if ((opc & 0xF0FF) == ((regno << 4) | 0x6003)) {
				//regno is copied to a new one.
				int newreg = (opc & 0xF00) >> 8;
				fprintf(dbg_stream, "Entering %4d.%6lX MOV\n", recurselevel, (unsigned long) pos + 2);
				sh_track_reg(buf, pos + 2, siz, newreg, visited, tracker_cb, cbdata);
			}

			//new recurse if we copy to gbr ( LDC Rm,GBR 0100mmmm00011110 )
			if (opc == (0x401E | (regno << 8))) {
				fprintf(dbg_stream, "Entering %4d.%6lX LDC GBR\n", recurselevel, (unsigned long) pos + 2);
				sh_track_reg(buf, pos + 2, siz, GBR, visited, tracker_cb, cbdata);
			}
		}

		if (regno == GBR) {
			//new recurse if we STC gbr, Rn
			if ((opc & 0xF0FF) == 0x0012) {
				int newreg = (opc >> 8) & 0xF;
				fprintf(dbg_stream, "Entering %4d.%6lX STC GBR\n", recurselevel, (unsigned long) pos + 2);
				sh_track_reg(buf, pos + 2, siz, newreg, visited, tracker_cb, cbdata);
			}
		}

		//new recurse if bt/bf. TODO : split case with a delay slot, since
		//there is a corner case where it copies/alters the reg before jumping
		if (IS_BT_OR_BF(opc)) {
			u32 newpos = disarm_8bit_offset(pos, GET_BTF_OFFSET(opc));
			fprintf(dbg_stream, "Branch %4d.%6lX BT/BF to %6lX\n", recurselevel, (unsigned long) pos, (unsigned long) newpos);
			sh_track_reg(buf, newpos, siz, regno, visited, tracker_cb, cbdata);
		}

		bool isbra = 0;
		u32 bra_newpos = pos + 2;
		//bra : don't recurse, just alter path
		if (IS_BRA(opc)) {
			bra_newpos = disarm_12bit_offset(pos, GET_BRA_OFFSET(opc));
			fprintf(dbg_stream, "Branch %4d.%6lX BRA to %6lX\n", recurselevel, (unsigned long) pos, (unsigned long) bra_newpos);
			isbra = 1;
		}

		//TODO : how to deal with jsr / bsr ?

		// almost done: check if we have a hit
		if (isbra) {
				//go check next opcode for delay slot
			tracker_cb(buf, pos + 2, regno, cbdata);
			pos = bra_newpos -2;	//alter path
			continue;
		}
		tracker_cb(buf, pos, regno, cbdata);

		//end recursion if reg is clobbered
		if (sh_getopcode_dest(opc) == regno) {
			goto endrec;
		}
	}	//for

endrec:
	recurselevel -= 1;
	return;
}
