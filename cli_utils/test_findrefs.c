/* find base+offset xrefs
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



/**** RECURSIV HELL ****/

int recurselevel;

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
void test_gbrref(u8 *buf, u32 pos, u32 offs) {
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
		if (dir) {
			printf("\t\t**** W @ 0x%06lX\n", (unsigned long) pos);
		} else {
			printf("\t\t**** R @ 0x%06lX\n", (unsigned long) pos);
		}
	}
}

u32 glob_offs;	//fugly shit to have access throughout all levels

// siz : size of buf
// recursively track usage of register <regno>
void track_reg(u8 *buf, u32 pos, u32 siz, int regno, u8 *visited) {

	recurselevel += 1;
	pos += 2;

	while (pos < siz) {
		//end recursion if already visited
		if (visited[pos]) {
			goto endrec;
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
				printf("Entering %4d.%6lX reg copy\n", recurselevel, (unsigned long) pos);
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

		//new recurse if bt/bf/bra
		if (IS_BT_OR_BF(opc)) {
			u32 newpos = disarm_8bit_offset(pos, GET_BTF_OFFSET(opc));
			printf("Branch %4d.%6lX BT/BF\n", recurselevel, (unsigned long) pos);
			track_reg(buf, newpos, siz, regno, visited);
		}
		if (IS_BRA(opc)) {
			u32 newpos = disarm_12bit_offset(pos, GET_BRA_OFFSET(opc));
			printf("Branch %4d.%6lX BRA\n", recurselevel, (unsigned long) pos);
			track_reg(buf, newpos, siz, regno, visited);
		}

		//TODO  : how to deal with jsr / bsr ?

		// And finally, check if we have a hit.
		if (regno == GBR) {
			test_gbrref(buf, pos, glob_offs);
		} else {

		}
		pos += 2;

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

void findrefs(FILE *i_file, u32 base, u32 offs) {
	uint8_t *src;
	u8 *visited;	//array of bytes, set to 1 when a certain area is "visited"

	long file_len;

	glob_offs = offs;

	file_len = flen(i_file);
	if ((file_len <= 0) || (file_len > 3*1024*1024L)) {
		printf("huge file (length %ld)\n", file_len);
	}

	src = malloc(file_len * 2);	//cheat : allocate both bufs
	if (!src) {
		printf("malloc choke\n");
		return;
	}
	visited = src + file_len;	//use second half of alloc

	/* load whole ROM */
	if (fread(src,1,file_len,i_file) != file_len) {
		printf("trouble reading\n");
		free(src);
		return;
	}

	memset(visited, 0, file_len);


	recurselevel = 0;
	u32 romcurs = 0;
	while (romcurs < file_len) {
		u16 opc;

		opc = reconst_16(&src[romcurs]);
		visited[romcurs] = 1;

		//2 possible opcodes : -  mov.w @(i, pc), Rn  : (0x1001nnnn 0xii) , or
		//  mov.l @(i, pc), Rn : (0x1101nnnn 0xii)
		uint8_t optop = (opc & 0xBF00) >> 8;
		if (optop == 0x90) {
			u32 imm = sh_get_PCimm(src, romcurs);
			if (imm == base) {
				// match ! start recursion.
				int regno = sh_getopcode_dest(opc);
				printf("Entering 00.%6lX.R%d\n", (unsigned long) romcurs, regno);
				track_reg(src, romcurs, file_len, regno, visited);
			}
		}

		romcurs += 2;
	}


	free(src);
}



int main(int argc, char * argv[]) {
	unsigned long base, offs;
	FILE *i_file;

	dbg_stream = stdout;

	if (argc != 4) {
		printf("%s <base> <offset> <in_file>"
			"\n\tExample: %s 0xffff400f 0xf0 rom.bin\n", argv[0], argv[0]);
		return 0;
	}

	// arg 1,2 : orig checksum locations
	if (sscanf(argv[1], "%lx", &base) != 1) {
		printf("did not understand %s\n", argv[1]);
		return 0;
	}
	if (sscanf(argv[2], "%lx", &offs) != 1) {
		printf("did not understand %s\n", argv[2]);
		return 0;
	}

	//input file
	if ((i_file=fopen(argv[3],"rb"))==NULL) {
		printf("error opening %s.\n", argv[3]);
		return 0;
	}

	rewind(i_file);

	findrefs(i_file, base, offs);

	fclose(i_file);

	return 0;
}

