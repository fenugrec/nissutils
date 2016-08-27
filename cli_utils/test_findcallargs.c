/* find where a given function is called with a certain r4 argument
 *
 * The way this works is:
 *
 * 1- there's a cool function, maybe "set_DTC(dtc_index)".
 *   - We know the func address
 *   - the interesting argument is passed in r4
 * 2- the cool function is called from many many places
 * 3- we want to find the place(s) where the func is called with a certain argument,
 *   ex. set_DTC(0xB0)
 *
 * easy : run this utility, with
 *    <tgt> = function address
 *    <r4val> = argument value
 * Example: test_findcallargs.exe 0x56738 0xB0 rom.bin
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


static void report_hit(u32 pos) {
	printf("\t\t**** @ 0x%06lX\n", (unsigned long) pos);
}

/**** RECURSIV HELL ****/

int recurselevel;

u32 glob_base;
u32 glob_arg;	//fugly shit to have access throughout all levels

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


/* test for "jsr @regno" */
#define JSR_R4_MAXBT	10	//how far back to search for r4 loadage
void test_goodcall(u8 *buf, u32 pos, int regno) {
	u16 code = reconst_16(&buf[pos]);

	if (regno == 4) return;	//r4 would defeat the purpose !

	if (!IS_JSR(code)) return;
	if (regno != GET_TARGET_REG(code)) return;

	//cool, now we need to find what the value of r4 was. Start at pos + 2 because of delay slot !
	u32 r4val = sh_bt_immload(buf, pos - JSR_R4_MAXBT, pos + 2, 4, 0);
	if (r4val == glob_arg) report_hit(pos);
	return;
}


// siz : size of buf
// recursively track usage of register <regno>
void track_reg(u8 *buf, u32 pos, u32 siz, int regno, u8 *visited) {

	recurselevel += 1;
	pos += 2;

	for (; pos < siz; pos += 2) {
		if (visited[pos]) {
			return;
		}

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
			goto mark_visited;
		}

		//TODO  : how to deal with jsr / bsr ?

		// And finally, check if we have a hit.
		if (regno == GBR) {
			//can't jump to GBR
			//continue;
		} else {
			test_goodcall(buf, pos, regno);
		}
mark_visited:
		visited[pos] = 1;

	}

endrec:
	recurselevel -= 1;
	return;
}


struct bsrcb_data {
	u32 expected_r4val;
	};

//called every time a "bsr tgt" is found. *data is a struct with required data to do the r4 search
#define BSR_R4_MAXBT	JSR_R4_MAXBT	//how far back to search for r4 loadage
void bsr_callback(const u8 *buf, u32 pos, void *data) {
	struct bsrcb_data *bcbd = data;

	//cool, now we need to find what the value of r4 was. Start at pos + 2 because of delay slot !
	u32 r4val = sh_bt_immload(buf, pos - BSR_R4_MAXBT, pos + 2, 4, 0);
	if (r4val == bcbd->expected_r4val) {
		report_hit(pos);
	}
	return;
}

/*
 * core function. 2 strategies are required:
 *
 * **** 1 : for "jsr @reg" form
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
 *
 * **** 2 : for "bsr &FUNC" form :
 */

void findcalls(FILE *i_file, u32 base, u32 arg) {
	uint8_t *src;
	u8 *visited;	//array of bytes, set to 1 when a certain area is "visited"

	long file_len;

	glob_base = base;
	glob_arg = arg;

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
	for (; romcurs < file_len; romcurs += 2) {
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
				track_reg(src, romcurs, file_len, regno, visited);
			}
		}

	}

	// 2 : find BSR occurences
	struct bsrcb_data bcbd;
	bcbd.expected_r4val = arg;
	find_bsr(src, base, bsr_callback, &bcbd);


	free(src);
}



int main(int argc, char * argv[]) {
	unsigned long tgt, r4val;
	FILE *i_file;

	dbg_stream = stdout;

	if (argc != 4) {
		printf("%s <tgt> <r4val> <in_file>"
			"\n\tExample: %s 0x56738 0x66 rom.bin\n", argv[0], argv[0]);
		return 0;
	}

	// arg 1,2 : orig checksum locations
	if (sscanf(argv[1], "%lx", &tgt) != 1) {
		printf("did not understand %s\n", argv[1]);
		return 0;
	}
	if (sscanf(argv[2], "%lx", &r4val) != 1) {
		printf("did not understand %s\n", argv[2]);
		return 0;
	}

	//input file
	if ((i_file=fopen(argv[3],"rb"))==NULL) {
		printf("error opening %s.\n", argv[3]);
		return 0;
	}

	rewind(i_file);
	findcalls(i_file, tgt, r4val);

	fclose(i_file);

	return 0;
}

