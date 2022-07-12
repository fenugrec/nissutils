/* just some funcs to find structures and patterns for nisrom
 * (c) fenugrec 2014-2022
 * GPLv3
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>	//for printf(); probably can go away someday
#include <stdbool.h>

#include "nislib.h"
#include "nislib_shtools.h"
#include "sh_opcodes.h"
#include "stypes.h"


 /* Example of a valid IVT : 0000 0104, ffff 7ffc, 0000 0104, ffff 7ffc
 */
bool check_ivt(const uint8_t *buf, unsigned siz) {
	uint32_t por_pc, por_sp;
	uint32_t mr_pc, mr_sp;

	assert(buf);
	if (siz < IVT_MINSIZE) {
		return 0;
	}

	por_pc = reconst_32(buf);
	por_sp = reconst_32(buf + 4);
	mr_pc = reconst_32(buf + 8);
	mr_sp = reconst_32(buf + 12);

	if ((por_pc & 1) || (mr_pc & 1)) return 0;
	if ((por_sp & 3) || (mr_sp & 3)) return 0;
	if (por_pc != mr_pc) return 0;
	if (por_sp != mr_sp) return 0;
	if (por_pc > 0x00ffffff) return 0;
	if (por_sp < 0xfff80000) return 0;

	return 1;
}


uint32_t find_ivt(const uint8_t *buf, uint32_t siz) {
	uint32_t offs;

	assert(buf && (siz <= MAX_ROMSIZE));

	siz &= ~3;
	for (offs = 0; siz != 0; siz -= 4, offs += 4) {
		if (check_ivt(buf + offs, siz)) return offs;
	}
	return -1;
}


/* check if the code at offset "func" inside the buffer looks like an eeprom read function.
 * ret 1 if good.
 *
 * assumes "func" is 16-bit aligned. Note : the bounds are valid for 7051, 7055, 7058, 7059
 */
#define EEPREAD_GETIOREG 30	//check only the first N opcodes
static const struct t_eep_iobound {
	uint16_t L;
	uint16_t H;} eep_iobounds[] = {
		{0xF720, 0xF789},	//bounds for 7055/7058/7059 IO regs
		{0x8380, 0x83B7},	//bounds for 7051 IO regs
		{0, 0}
	};

static bool analyze_eepread(const u8 *buf, u32 siz, u32 func, u32 *portreg) {
	/* algo : look for a mov.w (), Rn that loads an IO register address. This should cover both
	 * bit-bang SPI and SCI-based code.
	 */
	uint32_t fcur;
	bool good = 0;

	assert(buf && siz && portreg &&
		(siz <= MAX_ROMSIZE));

	for (fcur = 0;fcur < EEPREAD_GETIOREG; fcur += 1) {
		uint16_t opc;
		uint32_t litofs;
		uint16_t literal;
		int idx;

		if ((func + fcur * 2) >= siz) return 0;

		opc = reconst_16(&buf[func + fcur * 2]);
		if ((opc & 0xF000) != 0x9000) continue;

		// so we do have a mov.w (@x, PC), Rn opcode.
		litofs = (func + fcur * 2) + 4;	//PC;
		litofs += (opc & 0xFF) * 2;	//PC + disp*2
		literal = reconst_16(&buf[litofs]);

		for (idx = 0; eep_iobounds[idx].L ; idx ++) {
			if (literal > eep_iobounds[idx].H) continue;
			if (literal < eep_iobounds[idx].L) continue;
			good = 1;
			/* Bonus : identify the port register */
			*portreg = literal;
			fprintf(dbg_stream, "EEPROM Port reg : 0xFFFF%04X\n", literal);
			goto exit;
		}
	}
exit:
	return good;
}

#define EEPREAD_POSTJSR	6	//search for "jsr" within [-1, +POSTJSR] instructions of "mov 7B"
#define EEPREAD_MAXBT 25	//max backtrack to locate the mov that loads the function address
#define EEPREAD_MINJ 1		//min # of identical, nearby calls to eepread()
#define EEPREAD_JSRWINDOW 10	//search within a radius of _JSRWINDOW for identical jsr opcodes

uint32_t find_eepread(const uint8_t *buf, uint32_t siz, uint32_t *real_portreg) {
	int occurences = 0;
	uint32_t cur = 0;
	uint32_t jackpot = 0;
	uint32_t real_jackpot = 0;
	uint32_t portreg = 0;

	siz &= ~1;
	assert(buf && siz && real_portreg &&
		(siz <= MAX_ROMSIZE));

	for (cur = 0; cur <= (siz - 2); cur += 2) {
		/* find E4 7B opcode, for every occurence check if the pattern is credible */
		uint16_t opc;
		int jumpreg;
		int window;
		bool found_seq;
		uint32_t jsr_loc;	//offset of jsr instr
		uint32_t jsr_opcode;	//copy of opcode

		opc = reconst_16(&buf[cur]);
		if (opc != 0xE47B) continue;
		/* We found a "mov 0x7B, r4" :
		 * see if there's a jsr just before, or within [POSTJSR] instructions
		*/
		found_seq = 0;
		for (window = -1; window <= EEPREAD_POSTJSR; window ++) {
			// cppcheck-suppress integerOverflow
			uint32_t pos = (cur + window * 2);
			if (pos >= (siz - 2)) break;

			opc = reconst_16(&buf[pos]);
			if (!IS_JSR(opc)) continue;
			//printf("found a mov + jsr sequence;");
			jsr_loc = (pos);
			found_seq = 1;
			break;
		}
		if (!found_seq) continue;
		/* here, we found a new mov + jsr sequence. Get jsr register # :*/
		jumpreg = (opc & 0x0F00) >> 8;
		/* backtrack to find a "mov.x ..., Rn" */
		found_seq = 0;
		for (window -= 1; (window + EEPREAD_MAXBT) > 0; window--) {
			uint32_t pos = (cur + window * 2);
			if (pos >= (siz - 2)) break;

			opc = reconst_16(&buf[pos]);
			if (opc == 0x4F22) break;	// "sts.l pr, @-r15" :function entry; abort.

			//2 possible opcodes : - mov.w @(i, pc), Rn : (0x9n 0xii) , or
			// mov.l @(i, pc), Rn : (0xDn 0xii)
			jsr_opcode = opc;
			uint8_t jc_top = (opc & 0xBF00) >> 8;
			if (jc_top == (0x90 | jumpreg)) {
				found_seq = 1;
				break;
			}
		}
		if (!found_seq) {
			//unusual; algo should be tweaked if this happens
			fprintf(dbg_stream, "Occurence %d : jumpreg setting not found near 0x%x \n",
				occurences, cur);
			continue;
		}
		/* looking good : found the instruction that loads the function address.
		 * Compute PC offset, retrieve addr
		*/
		jackpot = (cur + window * 2);	//location of "mov.x" instr
		jackpot = sh_get_PCimm(buf, jackpot);

		/* discard out-of-ROM addresses */
		if (jackpot >= MAX_ROMSIZE) {
			//printf("Occurence %d @ 0x%0X: bad; &eep_read() out of bounds (0x%0X)\n",
			//	occurences, cur + window * 2, jackpot);
			continue;
		}

		/* improve confidence level : there should really be 2-3 identical "jsr" opcodes nearby */
		int other_jsrs = 0;
		int sign = 1;
		window = 0;
		while (window != EEPREAD_JSRWINDOW) {
			opc = reconst_16(&buf[jsr_loc + window * 2 * sign]);
			if (opc == jsr_opcode) {
				other_jsrs += 1;
			}
			sign = -sign;
			if (sign == 1) window += 1;
		}
		if (other_jsrs < EEPREAD_MINJ) {
			//printf("Occurence %d @ 0x%0X : Unlikely, not enough identical 'jsr's\n", occurences, cur + window * 2);
			continue;
		}
		found_seq = 0;
		/* improve moar : there should be another call with "mov 0x7C, r4" */
		for (window = -10; window <= 10; window ++ ) {
			// cppcheck-suppress integerOverflow
			opc = reconst_16(&buf[jsr_loc + window * 2]);
			if (opc == 0xE47C) {
				found_seq = 1;
				break;
			}
		}
		if (!found_seq) {
			continue;
			//printf("Occurence %d @ 0x%0X : no 7C nearby\n", occurences, cur + window * 2);
		}

		/* last test : follow inside eep_read() to see if we access IO registers pretty soon */
		if (analyze_eepread(buf, siz, jackpot, &portreg)) {
			occurences += 1;
			real_jackpot = jackpot;
			*real_portreg = 0xFFFF0000 | portreg;
			fprintf(dbg_stream, "Occurence %d @ 0x%0X : &eep_read() = 0x%0X\n", occurences, cur + window * 2, jackpot);
		} else {
			fprintf(dbg_stream, "didn't recognize &eep_read()\n");
		}


	}	//for
	//return last occurence.
	switch (occurences) {
	case 0:
		fprintf(dbg_stream, "eep_read() not found ! Needs better heuristics\n");
		real_jackpot = 0;
		break;
	case 1:
		//normal result
		break;
	default:
		fprintf(dbg_stream, "more than one likely eep_read() found ! Needs better heuristics\n");
		real_jackpot = 0;
		break;
	}
	return real_jackpot;
}

