/* find base+offset xrefs. Not nearly an exhaustive search, but
 * it saves about 1-2h of manual IDA search *every time* !
 *
 * The way this works is:
 * 1- you have a certain location (typically in RAM), say 0xffff40ff that you're interested in.
 * 2- you notice the code often accesses it by devious ways such as
 *   D6 0B mov.l   @(h'2C,pc), r6 ; r6 = 0xFFFF40E7
 *   E0 18 mov     #h'18, r0
 *   00 6C mov.b   @(r0,r6), r0	;r0 = [0xffff40ff] !
 * i.e. there's a base address (FFFF40E7) and an offset (+18) to reach the target addr.
 * Sometimes (often, actually) more than one combination of base + offset is used for the same target.
 * For the example above, the other frequent occurence is 0xFFFF400F + 0xF0 == 0xFFFF40FF.
 *
 * 3- run this utility, with "tgt" being the location you want to track,
 * and "minbase" the smallest likely base address. All the possible base addresses will be
 * tested. In the above case, I could specify minbase = 0xFFFF4000 and the utility will
 * test a total of 255 base + offset permutations.
 *
 * This should really be compiled at -O2
 *
 *
 * (c) fenugrec 2016
 * GPLv3
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "nislib.h"
#include "stypes.h"
#include "sh_opcodes.h"


FILE *dbg_stream;

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


static void report_hit(bool is_write, u32 pos, u32 base, u32 offs) {
	if (is_write) {
		printf("\t\t**** W @ 0x%06lX : 0x%08lX + 0x%lX\n", (unsigned long) pos,
				(unsigned long) base, (unsigned long) offs);
	} else {
		printf("\t\t**** R @ 0x%06lX : 0x%08lX + 0x%lX\n", (unsigned long) pos,
				(unsigned long) base, (unsigned long) offs);
	}
}


/**** RECURSIV HELL ****/

int recurselevel;

u32 glob_base;
u32 glob_offs;	//fugly shit to have access throughout all levels

enum opcode_dest {
	R0 = 0, R15 = 15, GBR, OPC_DEST_OTHER};

/** determine what register is modified by a given opcode */
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

/* for bt,bf sign-extended offsets : return PC+4+ (exts.b offset)<<1 */
static u32 disarm_8bit_offset (u32 pos, u32 offs) {
	/* sign extend if higher bit is 1 (0x08) */
	if ((offs & 0x80) == 0x80)
		offs |= ~0xFF;
	return (offs<<1) + pos + 4;
}

/* for {bra,bsr} only: (sign-extend 12bit offset)<<1  + PC +4 */
static u32 disarm_12bit_offset (u32 pos, u32 insoff) {
	u32 off = insoff;
	/* sign extend if higher bit is 1 (0x0800) */
	if ((off & 0x0800) == 0x0800)
		off |= ~0xFFF;
	return (pos) + (off<<1) + 4;
}



//check and report if hit (GBR already == base)
void test_gbrref(const u8 *buf, u32 pos, u32 offs) {
	u16 opc = reconst_16(&buf[pos]);
	int dir = 0;	//0 : R. 1: W
	int mul = 0;

	if (IS_MOVB_R0_GBRREF(opc) || IS_MOVW_R0_GBRREF(opc) || IS_MOVL_R0_GBRREF(opc)) {
		dir = 1;
		mul = 1 << ((opc >> 8) & 0x03);
	}
	if (IS_MOVB_GBRREF_R0(opc) || IS_MOVW_GBRREF_R0(opc) || IS_MOVL_GBRREF_R0(opc)) {
		dir = 0;
		mul = 1 << ((opc >> 8) & 0x03);
	}
	if (!mul) return;	//not a GBR opcode

	if (offs == (opc & 0xFF) * mul) {
		//match !
		report_hit(dir, pos, glob_base, offs);
	}
}

//test @(disp,Rn) forms
void test_rnrel(const u8 *buf, u32 pos, u32 offs, int regno) {
	u16 opc = reconst_16(&buf[pos]);
	u32 disp = 0;
	int dir = 0;	//0 : R. 1: W


	if ((opc & 0xF000) == 0x1000) {
			// 0001nnnnmmmmi4*4 mov.l <REG_M>,@(<disp>,<REG_N>)
		if (((opc >> 8) & 0x0F) != regno) return;	//nnnn must match
		dir = 1;
		disp = (opc & 0xF) * 4;
	} else if ((opc & 0xF600) == 0x8000) {
			// 10000100mmmmi4*1 mov.b @(<disp>,<REG_M>),R0
			// 10000101mmmmi4*2 mov.w @(<disp>,<REG_M>),R0
			// 10000000mmmmi4*1 mov.b R0,@(<disp>,<REG_M>)
			// 10000001mmmmi4*2 mov.w R0,@(<disp>,<REG_M>)
		if (((opc >> 4) & 0x0F) != regno) return;	//mmmm must match
		dir = ! (bool)(opc & 0x0400);
		disp = (opc & 0xF) * (1 + (bool) (opc & 0x0100));
	} else if ((opc & 0xF000) == 0x5000) {
			// 0101nnnnmmmmi4*4 mov.l @(<disp>,<REG_M>),<REG_N>
		if (((opc >> 4) & 0x0F) != regno) return;	//mmmm must match
		dir = 0;
		disp = (opc & 0xF) * 4;
	} else {
		//invalid
		return;
	}

	if (offs == disp) {
		//match !
		report_hit(dir, pos, glob_base, offs);
	}
}



// @(R0, Rn) forms
#define R0RN_MAXBT	10	//how far back to search for an immediate load for the offset
void test_r0rn(const u8 *buf, u32 pos, u32 offs, int regno) {
	u16 opc = reconst_16(&buf[pos]);
	int dir = 0;	//0 : R. 1: W
	int newreg;
	u32 disp = 0;

	//0000nnnnmmmm0100 mov.b <REG_M>,@(R0,<REG_N>)
	//0000nnnnmmmm0101 mov.w <REG_M>,@(R0,<REG_N>)
	//0000nnnnmmmm0110 mov.l <REG_M>,@(R0,<REG_N>)
	//0000nnnnmmmm1100 mov.b @(R0,<REG_M>),<REG_N>
	//0000nnnnmmmm1101 mov.w @(R0,<REG_M>),<REG_N>
	//0000nnnnmmmm1110 mov.l @(R0,<REG_M>),<REG_N>

	if (((opc & 0xF00F) == 0x0007) ||
		((opc & 0xF00F) == 0x000F) ||
		((opc & 0xF004) != 0x0004)) return;	//bad opcode

	//select either nnnn or mmmm according to direction
	if (opc & 0x0008) {
		//need to check mmmm field, maybe.
		dir = 0;
		newreg = (opc >> 4) & 0x0F;	//mmmm
	} else {
		dir = 1;
		newreg = (opc >> 8) & 0x0F;	//nnnn
	}

	// two cases : the correct base was either in R0, or Rx
	if (regno == 0) {
		disp = sh_bt_immload(buf, pos - R0RN_MAXBT, pos, newreg);
	} else {
		//then mmmm needs to match regno
		if (newreg != regno) return;
		disp = sh_bt_immload(buf, pos - R0RN_MAXBT, pos, R0);
	}

	if (offs == disp) {
		//match !
		report_hit(dir, pos, glob_base, offs);
	}
}

/* test "@Rn, Rm" and "Rn, @Rm" variants (REGREF) */
void test_regref(const u8 *buf, u32 pos, u32 offs, int regno) {
	int dir = 0;
	int newreg;
	u16 opc=reconst_16(&buf[pos]);

	// offset must be 0 for these to work
	if (offs) return;

	// patterns :
	// 0010nnnnmmmm0000 mov.b <REG_M>,@<REG_N>
	// 0010nnnnmmmm0001 mov.w <REG_M>,@<REG_N>
	// 0010nnnnmmmm0010 mov.l <REG_M>,@<REG_N>
	// 0110nnnnmmmm0000 mov.b @<REG_M>,<REG_N>
	// 0110nnnnmmmm0001 mov.w @<REG_M>,<REG_N>
	// 0110nnnnmmmm0010 mov.l @<REG_M>,<REG_N>

	u16 optop = opc & 0xB00F;	//drop bit 14 (direction)
	if  (	(optop == 0x2000) ||
			(optop == 0x2001) ||
			(optop == 0x2002) ){
		if (opc & 0x4000) {
			//@Rm, Rn
			newreg = (opc >> 4) & 0xF;
			dir = 0;
		} else {
			//Rm, @Rn
			newreg = (opc >> 8) & 0xF;
			dir = 1;
		}
		if (newreg != regno) return;	//mismatch
		report_hit(dir, pos, glob_base, 0);
	}
	return;
}

// siz : size of buf
// recursively track usage of register <regno>
void track_reg(const u8 *buf, u32 pos, u32 siz, int regno, u8 *visited) {

	recurselevel += 1;
	pos += 2;

	for (; pos < siz; pos += 2) {
		if (visited[pos]) {
			return;
		}
		visited[pos] = 1;

		u16 opc = reconst_16(&buf[pos]);

		//end recursion if we hit RTS
		if (IS_RTS(opc) || IS_RTE(opc)) {
			goto endrec;
		}

		//end recursion if reg is clobbered
		if (sh_getopcode_dest(opc) == regno) {
			goto endrec;
		}

		if (regno < 16) {
			//new recurse if match mov Rm, Rn
			if ((opc & 0xF0FF) == ((regno << 4) | 0x6003)) {
				//regno is copied to a new one.
				int newreg = (opc & 0xF00) >> 8;
				printf("Entering %4d.%6lX MOV\n", recurselevel, (unsigned long) pos);
				track_reg(buf, pos, siz, newreg, visited);
			}

			//new recurse if we copy to gbr
			if ((opc & 0xF0FF) == (0x401E | (regno << 8))) {
				printf("Entering %4d.%6lX LDC GBR\n", recurselevel, (unsigned long) pos);
				track_reg(buf, pos, siz, GBR, visited);
			}
		}

		if (regno == GBR) {
			//new recurse if we STC gbr, Rn
			if ((opc & 0xF0FF) == 0x0012) {
				int newreg = (opc >> 8) & 0xF;
				printf("Entering %4d.%6lX STC GBR\n", recurselevel, (unsigned long) pos);
				track_reg(buf, pos, siz, newreg, visited);
			}
		}

		//new recurse if bt/bf
		if (IS_BT_OR_BF(opc)) {
			u32 newpos = disarm_8bit_offset(pos, GET_BTF_OFFSET(opc));
			printf("Branch %4d.%6lX BT/BF\n", recurselevel, (unsigned long) pos);
			track_reg(buf, newpos, siz, regno, visited);
		}
		//bra : don't recurse, just alter path
		if (IS_BRA(opc)) {
			u32 newpos = disarm_12bit_offset(pos, GET_BRA_OFFSET(opc));
			printf("Branch %4d.%6lX BRA\n", recurselevel, (unsigned long) pos);
			pos = newpos - 2;
			//TODO : delay slut ? fuuuuu
			continue;
		}

		//TODO  : how to deal with jsr / bsr ?

		// And finally, check if we have a hit.
		if (regno == GBR) {
			test_gbrref(buf, pos, glob_offs);
		} else {
			test_rnrel(buf, pos, glob_offs, regno);	//test naive @(disp+Rn) forms
			test_r0rn(buf, pos, glob_offs, regno);	//test @(R0,Rn) forms
			test_regref(buf, pos, glob_offs, regno);	//test @R, R forms
		}

	}

endrec:
	recurselevel -= 1;
	return;
}

/*
 * core function. strategy:
 *
 * - locate mov.w or mov.l instructions that load the specified <base> value
 * - follow code recursively with tracked register (track_reg()). Ending conditions:
 *  - register clobbered (non exhaustive)
 *  - rts opcode
 *  - bt / bf / bra to visited areas
 *  - absolute max recurse depth ?
 * - recurse for every:
 *  - base register copy with "mov"
 *  - bt /bf / bra
 *
 * of course, print any base+offset matches, whether reading or writing.
 */

void findrefs(const u8 *src, u32 siz, u32 base, u32 offs) {
	u8 *visited;	//array of bytes, set to 1 when a certain area is "visited"

	glob_base = base;
	glob_offs = offs;

	visited = calloc(1, siz);	//this also does memset(0)
	if (!visited) {
		printf("malloc choke\n");
		return;
	}


	recurselevel = 0;
	u32 romcurs = 0;
	for (; romcurs < siz; romcurs += 2) {
		u16 opc;

		if (visited[romcurs]) continue;

		opc = reconst_16(&src[romcurs]);
		visited[romcurs] = 1;

		//2 possible opcodes : -  mov.w @(i, pc), Rn  : (0x1001nnnn 0xii) , or
		//  mov.l @(i, pc), Rn : (0x1101nnnn 0xii)
		uint8_t optop = (opc & 0xB000) >> 8;
		if (optop == 0x90) {
			u32 imm = sh_get_PCimm(src, romcurs);
			if (imm == base) {
				// match ! start recursion.
				int regno = sh_getopcode_dest(opc);
				printf("Entering 00.%6lX.R%d\n", (unsigned long) romcurs, regno);
				track_reg(src, romcurs, siz, regno, visited);
			}
		}

	}

	free(visited);
}



int main(int argc, char * argv[]) {
	unsigned long tgt, minbase, base, offs;
	FILE *i_file;

	dbg_stream = stdout;

	if (argc != 4) {
		printf("%s <tgt> <minbase> <in_file>"
			"\n\tExample: %s 0xffff40ff 0xffff4000 rom.bin\n", argv[0], argv[0]);
		return 0;
	}

	// arg 1,2 : orig checksum locations
	if (sscanf(argv[1], "%lx", &tgt) != 1) {
		printf("did not understand %s\n", argv[1]);
		return 0;
	}
	if (sscanf(argv[2], "%lx", &minbase) != 1) {
		printf("did not understand %s\n", argv[2]);
		return 0;
	}

	//input file
	if ((i_file=fopen(argv[3],"rb"))==NULL) {
		printf("error opening %s.\n", argv[3]);
		return 0;
	}

	long file_len;

	rewind(i_file);
	file_len = flen(i_file);
	if ((file_len <= 0) || (file_len > 3*1024*1024L)) {
		printf("huge file (length %ld)\n", file_len);
	}

	u8 *src = malloc(file_len);
	if (!src) {
		printf("malloc choke\n");
		return 0;
	}

	/* load whole ROM */
	if (fread(src,1,file_len,i_file) != file_len) {
		printf("trouble reading\n");
		free(src);
		return 0;
	}
	fclose(i_file);

	for (base=tgt; base >= minbase; base -= 1) {
		offs = tgt - base;
		findrefs(src, (u32) file_len, base, offs);
	}

	free(src);

	return 0;
}

