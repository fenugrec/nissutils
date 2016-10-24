/* find where a given function is called with a certain r4 argument
 *
 * The way this works is:
 *
 * 1- there's a cool function, maybe "set_DTC(dtc_index)".
 *   - We know that func's address
 *   - the interesting argument is passed in r4
 * 2- the cool func is called from many many places
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


static void report_hit(u32 pos) {
	printf("\t\t**** @ 0x%06lX\n", (unsigned long) pos);
}

/**** RECURSIV HELL ****/


u32 glob_base;
u32 glob_arg;	//fugly shit to have access throughout all levels


/* test for "jsr @regno" */
#define JSR_R4_MAXBT	10	//how far back to search for r4 loadage
void test_goodcall(const u8 *buf, u32 pos, unsigned regno, void *data) {
	(void) data;	//unused
	u16 code = reconst_16(&buf[pos]);

	if (regno == 4) return;	//r4 would defeat the purpose !

	if (!IS_JSR(code)) return;
	if (regno != GET_TARGET_REG(code)) return;

	//cool, now we need to find what the value of r4 was. Start at pos + 2 because of delay slot !
	u32 r4val;
	if (sh_bt_immload(&r4val, buf, pos - JSR_R4_MAXBT, pos + 2, 4)) {
		if (r4val == glob_arg) report_hit(pos);
	}
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
	u32 r4val;
	if (sh_bt_immload(&r4val, buf, pos - BSR_R4_MAXBT, pos + 2, 4)) {
		if (r4val == bcbd->expected_r4val) {
			report_hit(pos);
		}
	}
	return;
}

/*
 * core function. 2 strategies are required:
 *
 * **** 1 : for "jsr @reg" form
 *
 * - locate mov.w or mov.l instructions that load the specified <base> value
 * - follow code recursively with tracked register (sh_track_reg()). Ending conditions:
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

	u32 file_len;

	glob_base = base;
	glob_arg = arg;

	file_len = flen(i_file);
	if ((!file_len) || (file_len > 3*1024*1024UL)) {
		printf("huge file (length %lu)\n", (unsigned long) file_len);
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


	u32 romcurs = 0;
	for (; romcurs < file_len; romcurs += 2) {
		u16 opc;

		opc = reconst_16(&src[romcurs]);

		//2 possible opcodes : -  mov.w @(i, pc), Rn  : (0x1001nnnn 0xii) , or
		//  mov.l @(i, pc), Rn : (0x1101nnnn 0xii)
		uint8_t optop = (opc & 0xB000) >> 8;
		if (optop == 0x90) {
			u32 imm = sh_get_PCimm(src, romcurs);
			if (imm == base) {
				// match ! start recursion.
				unsigned regno = sh_getopcode_dest(opc);
				memset(visited, 0, file_len);
				printf("Entering 00.%6lX.R%d\n", (unsigned long) romcurs, regno);
				sh_track_reg(src, romcurs, file_len, regno, visited, test_goodcall, NULL);
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

