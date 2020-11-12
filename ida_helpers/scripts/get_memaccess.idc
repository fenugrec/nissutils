// SH : calc accessed address of current line; creates a comment + xref
// some parts from nislib
// GPLv3
// (c) fenugrec 2016

#include <idc.idc>


#define reconst_16(x) Word(x)
#define reconst_32(x) Dword(x)

////////////////////////////////////////////////////////////////
// adapted from radare2


#define IS_CLRT(x)			x == 0x0008
#define IS_NOP(x)			x == 0x0009
#define IS_RTS(x)			x == 0x000b
#define IS_SETT(x)			x == 0x0018
#define IS_DIV0U(x)			x == 0x0019
#define IS_SLEEP(x)			x == 0x001b
#define IS_CLRMAC(x)		x == 0x0028
#define IS_RTE(x)			x == 0x002b
//#define IS_CLRS(x)

#define IS_STCSR1(x)		(((x) & 0xF0CF) == 0x0002)		//mask stc Rn,{SR,GBR,VBR,SSR}
#define IS_BSRF(x)			(x & 0xf0ff) == 0x0003
#define IS_BRAF(x)			(((x) & 0xf0ff) == 0x0023)
#define IS_MOVB_REG_TO_R0REL(x)		(((x) & 0xF00F) == 0x0004)
#define IS_MOVW_REG_TO_R0REL(x)		(((x) & 0xF00F) == 0x0005)
#define IS_MOVL_REG_TO_R0REL(x)		(((x) & 0xF00F) == 0x0006)
#define IS_MULL(x)			(((x) & 0xF00F) == 0x0007)
#define IS_MOVB_R0REL_TO_REG(x)		(((x) & 0xF00F) == 0x000C)
#define IS_MOVW_R0REL_TO_REG(x)		(((x) & 0xF00F) == 0x000D)
#define IS_MOVL_R0REL_TO_REG(x)		(((x) & 0xF00F) == 0x000E)
//#define IS_MACL(x)		(((x) & 0xF00F) == 0x000F) //complicated !
#define IS_MOVT(x)			(((x) & 0xF0FF) == 0x0029)
#define IS_STSMAC(x)		(((x) & 0xF0EF) == 0x000A)		//mask sts Rn, MAC*
#define IS_STSPR(x)			(((x) & 0xF0FF) == 0x002A)
//#define IS_STSFPUL(x)		(((x) & 0xF0FF) == 0x005A)		//FP*: todo maybe someday
//#define IS_STSFPSCR(x)		(((x) & 0xF0FF) == 0x006A)

#define IS_MOVB_REG_TO_REGREF(x)	(((x) & 0xF00F) == 0x2000)
#define IS_MOVW_REG_TO_REGREF(x)	(((x) & 0xF00F) == 0x2001)
#define IS_MOVL_REG_TO_REGREF(x)	(((x) & 0xF00F) == 0x2002)
//#define invalid?(x)	(((x) & 0xF00F) == 0x2003)	//illegal on sh2e
#define IS_PUSHB(x)			(((x) & 0xF00F) == 0x2004)
#define IS_PUSHW(x)			(((x) & 0xF00F) == 0x2005)
#define IS_PUSHL(x)			(((x) & 0xF00F) == 0x2006)
#define IS_DIV0S(x)		(((x) & 0xF00F) == 0x2007)
#define IS_TSTRR(x)			(((x) & 0xF00F) == 0x2008)
#define IS_AND_REGS(x)			(((x) & 0xF00F) == 0x2009)
#define IS_XOR_REGS(x)			(((x) & 0xF00F) == 0x200A)
#define IS_OR_REGS(x)			(((x) & 0xF00F) == 0x200B)
#define IS_CMPSTR(x)			(((x) & 0xF00F) == 0x200C)
#define IS_XTRCT(x)			(((x) & 0xF00F) == 0x200D)
#define IS_MULUW(x)			(((x) & 0xF00F) == 0x200E)
#define IS_MULSW(x)			(((x) & 0xF00F) == 0x200F)


#define IS_CMPEQ(x)			(((x) & 0xF00F) == 0x3000)
//#define invalid?(x)			(((x) & 0xF00F) == 0x3001)
#define IS_CMPHS(x)			(((x) & 0xF00F) == 0x3002)
#define IS_CMPGE(x)			(((x) & 0xF00F) == 0x3003)
#define IS_CMPHI(x)			(((x) & 0xF00F) == 0x3006)
#define IS_CMPGT(x)			(((x) & 0xF00F) == 0x3007)

#define IS_DIV1(x)			(((x) & 0xF00F) == 0x3004)
#define IS_DMULU(x)			(((x) & 0xF00F) == 0x3005)
#define IS_DMULS(x)			(((x) & 0xF00F) == 0x300D)

#define IS_SUB(x)			(((x) & 0xF00F) == 0x3008)
//#define invalid?(x)			(((x) & 0xF00F) == 0x3009)
#define IS_SUBC(x)			(((x) & 0xF00F) == 0x300A)
#define IS_SUBV(x)			(((x) & 0xF00F) == 0x300B)
#define IS_ADD(x)			(((x) & 0xF00F) == 0x300C)
#define IS_ADDC(x)			(((x) & 0xF00F) == 0x300E)
#define IS_ADDV(x)			(((x) & 0xF00F) == 0x300F)

//#define IS_MACW(x)			(((x) & 0xF00F) == 0x400F)	//complex
#define IS_JSR(x)			(((x) & 0xf0ff) == 0x400b)
#define IS_JMP(x)			(((x) & 0xf0ff) == 0x402b)
#define IS_CMPPL(x)			(((x) & 0xf0ff) == 0x4015)
#define IS_CMPPZ(x)			(((x) & 0xf0ff) == 0x4011)

#define IS_LDCSR1(x)		(((x) & 0xF0CF) == 0x400E)		//mask ldc Rn,{SR,GBR,VBR,SSR}
#define IS_LDCLSR1(x)		(((x) & 0xF0CF) == 0x4007)		//mask ldc.l @Rn+,{SR,GBR,VBR,SSR}
#define IS_LDSMAC(x)		(((x) & 0xF0EF) == 0x400A)		//mask lds Rn, MAC*
#define IS_LDSLMAC(x)		(((x) & 0xF0EF) == 0x4006)		//mask lds.l @Rn+, MAC*
#define IS_LDSPR(x)			(((x) & 0xF0FF) == 0x402A)
#define IS_LDSLPR(x)		(((x) & 0xF0FF) == 0x4026)
//#define IS_LDSFPUL(x)		(((x) & 0xF0FF) == 0x405A)		//FP*: todo maybe someday
//#define IS_LDSFPSCR(x)		(((x) & 0xF0FF) == 0x406A)
//#define IS_LDSLFPUL(x)		(((x) & 0xF0FF) == 0x4066)
//#define IS_LDSLFPSCR(x)		(((x) & 0xF0FF) == 0x4056)
#define IS_ROT(x)			(((x) & 0xF0DE) == 0x4004)		//mask rot{,c}{l,r}
//not on sh2e : shad, shld

#define IS_SHIFT1(x)		(((x) & 0xF0DE) == 0x4000)	//unused (treated as switch-case)
//other shl{l,r}{,2,8,16} in switch case also.

#define IS_STSLMAC(x)		(((x) & 0xF0EF) == 0x4002)		//mask sts.l mac*, @-Rn
#define IS_STCLSR1(x)		(((x) & 0xF0CF) == 0x4003)	//mask stc.l {SR,GBR,VBR,SSR},@-Rn
//todo: other stc.l not on sh2e
#define IS_STSLPR(x)		(((x) & 0xF0FF) == 0x4022)
//#define IS_STSLFPUL(x)		(((x) & 0xF0FF) == 0x4052)
//#define IS_STSLFPSCR(x)		(((x) & 0xF0FF) == 0x4062)
#define IS_TASB(x)			(((x) & 0xF0FF) == 0x401B)
#define IS_DT(x)			(((x) & 0xF0FF) == 0x4010)


#define IS_MOVB_REGREF_TO_REG(x)	(((x) & 0xF00F) == 0x6000)
#define IS_MOVW_REGREF_TO_REG(x)	(((x) & 0xF00F) == 0x6001)
#define IS_MOVL_REGREF_TO_REG(x)	(((x) & 0xF00F) == 0x6002)
#define IS_MOV_REGS(x)			(((x) & 0xf00f) == 0x6003)
#define IS_MOVB_POP(x)			(((x) & 0xF00F) == 0x6004)
#define IS_MOVW_POP(x)			(((x) & 0xF00F) == 0x6005)
#define IS_MOVL_POP(x)			(((x) & 0xF00F) == 0x6006)
#define IS_NOT(x)			(((x) & 0xF00F) == 0x6007)
#define IS_SWAP(x)			(((x) & 0xF00E) == 0x6008)	//match swap.{b,w}
#define IS_NEG(x)			(((x) & 0xF00E) == 0x600A)	//match neg{,c}
#define IS_EXT(x)		(((x) & 0xF00C) == 0x600C)	//match ext{s,u}.{b,w}


#define IS_MOVB_R0_REGDISP(x)	(((x) & 0xFF00) == 0x8000)
#define IS_MOVW_R0_REGDISP(x)	(((x) & 0xFF00) == 0x8100)
//#define illegal?(x)		(((x) & 0xF900) == 0x8000)	//match 8{2,3,6,7}00
#define IS_MOVB_REGDISP_R0(x)		(((x) & 0xFF00) == 0x8400)
#define IS_MOVW_REGDISP_R0(x)		(((x) & 0xFF00) == 0x8500)
#define IS_CMPIMM(x)		(((x) & 0xFF00) == 0x8800)
//#define illegal?(x)		(((x) & 0xFB00) == 0x8A00)	//match 8{A,E}00
#define IS_BT(x)			(((x) & 0xff00) == 0x8900)
#define IS_BF(x)			(((x) & 0xff00) == 0x8B00)
#define IS_BTS(x)			(((x) & 0xff00) == 0x8D00)
#define IS_BFS(x)			(((x) & 0xff00) == 0x8F00)
#define IS_BT_OR_BF(x)			IS_BT(x)||IS_BTS(x)||IS_BF(x)||IS_BFS(x)

#define IS_BRA(x)		(((x) & 0xF000) == 0xA000)
#define IS_MOVB_R0_GBRREF(x)	(((x) & 0xFF00) == 0xC000)
#define IS_MOVW_R0_GBRREF(x)	(((x) & 0xFF00) == 0xC100)
#define IS_MOVL_R0_GBRREF(x)	(((x) & 0xFF00) == 0xC200)
#define IS_TRAP(x)				(((x) & 0xFF00) == 0xC300)
#define IS_MOVB_GBRREF_R0(x)	(((x) & 0xFF00) == 0xC400)
#define IS_MOVW_GBRREF_R0(x)	(((x) & 0xFF00) == 0xC500)
#define IS_MOVL_GBRREF_R0(x)	(((x) & 0xFF00) == 0xC600)
#define IS_MOVA_PCREL_R0(x)		(((x) & 0xFF00) == 0xC700)
#define IS_BINLOGIC_IMM_R0(x)	(((x) & 0xFC00) == 0xC800)	//match C{8,9,A,B}00
#define IS_BINLOGIC_IMM_GBR(x)	(((x) & 0xFC00) == 0xCC00)	//match C{C,D,E,F}00 : *.b #imm, @(R0,GBR)

/* Compute PC-relative displacement for branch instructions */
#define GET_BRA_OFFSET(x)	((x) & 0x0fff)
#define GET_BTF_OFFSET(x)	((x) & 0x00ff)

/* Compute reg nr for BRAF,BSR,BSRF,JMP,JSR */
#define GET_TARGET_REG(x)	((x >> 8) & 0x0f)
#define GET_SOURCE_REG(x)	((x >> 4) & 0x0f)

/////////////////////////////////////////////////

/** sign-extend u8 value to u32, like exts.b */
static sh_extsb(val) {
	if (val & 0x80) return 0xFFFFFF00 | val;
	return val;
}

/** Sign-extend u16 value to u32, like exts.w */
static sh_extsw(val) {
	if (val & 0x8000) return 0xFFFF0000 | val;
	return val;
}


static sh_get_PCimm(ea) {
	auto opc, new_ea;
	new_ea = ea;

	opc = Word(ea);

	if (opc & 0x4000) {
		//mov.l
		new_ea = new_ea + ((opc & 0xFF) * 4) + 4;
		// essential : align 4 !!!
		new_ea =  new_ea & ~0x03;
		//printf("retrieve &er() from 0x%0X\n", pos);
		return Dword(new_ea);
	} else {
		//mov.w
		auto lit;
		new_ea = new_ea + ((opc & 0xFF) * 2) + 4;
		//printf("retrieve &er() from 0x%0X\n", pos);
		lit = Word(new_ea);
		return sh_extsw(lit);	//sign-extend
	}
}


static sh_getopcode_dest(code) {
	code = code & 0xFFFF;

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
	return 17;
}






static sh_bt_immload(array_imm, start, min, regno) {
	auto opc, new_regno, new_bt, prevop, ic_top;
	auto imloc;

	while (start >= min) {
		opc = Word(start);

		// 1) limit search to function head. Problem : sometimes this opcode is not at the head of the function !
		//if (opc == 0x4F22) return 0;

		// 2a) if we're copying from another reg, we need to recurse. opc format :
		// mov Rm, R(regno) [6n m3]
		if ((opc & 0xFF0F) == (0x6003 | (regno << 8))) {
			start = start - 2;
			new_regno = (opc & 0xF0) >> 4;

			if (sh_bt_immload(array_imm, start, min, new_regno)) {
				//Suxxess : found literal
				return 1;
			}
			// recurse failed; probably loaded from arglist or some other shit
			return 0;
		}

		// 2b) if we had a "shlr16" into regno, recurse too and shift immediate before returning.
		if (opc == (0x4029 | (regno << 8))) {
			start = start - 2;

			if (sh_bt_immload(array_imm, start, min, regno)) {
				//Suxxess : found literal
				new_bt = GetArrayElement(AR_LONG, array_imm, 0);
				SetArrayLong(array_imm, 0, (new_bt >> 16));
				return 1;
			}
			// recurse failed; probably loaded from arglist or some other shit
			return 0;
		}

		// 2c) EXTU.B Rm,Rn 0110nnnnmmmm1100 : special case of mov R,R : also recurse
		if ((opc & 0xFF0F) == (0x600C | (regno << 8))) {
			new_regno = (opc >> 4) & 0x0F;	//follow Rm
			start = start - 2;

			if (sh_bt_immload(array_imm, start, min, new_regno)) {
				new_bt = GetArrayElement(AR_LONG, array_imm, 0);
				SetArrayLong(array_imm, 0, (new_bt & 0xFF));
				return 1;
			}
			return 0;
		}

		// 2d) shll, shll2 : recurse and shift before returning
		if ((opc & 0xFFF7)  == (0x4000 | (regno << 8))) {
			auto is_shll2;
			if (opc & 0x0008) {
				is_shll2 = 1;
			} else {
				is_shll2 = 0;
			}

			start = start - 2;
			//printf("\t\t***********shll @ %lX\n", (unsigned long) start);

			if (sh_bt_immload(array_imm, start, min, regno)) {
				new_bt = GetArrayElement(AR_LONG, array_imm, 0);
				if (is_shll2) {
					SetArrayLong(array_imm, 0, ((new_bt << 2)));
				} else {
					SetArrayLong(array_imm, 0, ((new_bt << 1)));
				}
				return 1;
			}
			return 0;
		}

		// 2e) add imm8: recurse and add before returning. b'0111nnnniiiiiiii'
		if ((opc & 0xFF00)  == (0x7000 | (regno << 8))) {
			auto add_s8;
			add_s8 = sh_extsb(opc & 0xFF);
			start = start - 2;
			//printf("\t\t***********add @ %lX\n", (unsigned long) start);

			if (sh_bt_immload(array_imm, start, min, regno)) {
				new_bt = GetArrayElement(AR_LONG, array_imm, 0);
				SetArrayLong(array_imm, 0, ((new_bt + add_s8)));
				return 1;
			}
			return 0;
		}

		// 2f) shll8: recurse and shift before returning. 0100nnnn00011000
		if (opc  == (0x4018 | (regno << 8))) {
			start = start - 2;

			if (sh_bt_immload(array_imm, start, min, regno)) {
				new_bt = GetArrayElement(AR_LONG, array_imm, 0);
				SetArrayLong(array_imm, 0, ((new_bt << 8)));
				return 1;
			}
			return 0;
		}

		// 3) no recursion : try to find load_immediate.
		// "mov #imm8, R<regno>"	[E<regno> <i>]
		// "mov.w @(disp, PC), R<regno> 	[9<regno> <disp/2>]
		// "mov.l @(disp, PC), R<regno> 	[D<regno> <disp/4>]
		// "movi20 #imm20, R<regno>	[0<regno> <i16_19> 0][i0_15]
		// test for the "movi20" variant first, because it takes up 2 opcodes
		prevop = Word(start - 2);
		if ((prevop & 0xFF0F) == (regno << 8)) {
			//movi20 match. just keep lower 16 bits sign-extended
			SetArrayLong(array_imm, 0, (sh_extsw(opc)));
			return 1;
		}
		ic_top = ((opc & 0xFF00) >> 8) & 0xFF;
		imloc = start; //location of mov instruction
		if (ic_top == (0xD0 | regno)) {
			//imm32 with possible shift16
			imloc = imloc + ((opc & 0xFF) * 4) + 4;
			// essential : align 4 !!!
			imloc = imloc & ~0x03;
			//printf("retrieve &er() from 0x%0X\n", jackpot);
			SetArrayLong(array_imm, 0, (Dword(imloc)));
			return 1;
		}
		if (ic_top == (0x90 | regno)) {
			//imm16
			imloc = imloc + ((opc & 0xFF) * 2) + 4;
			//printf("retrieve &er() from 0x%0X\n", jackpot);
			SetArrayLong(array_imm, 0, (sh_extsw(Word(imloc))));
			return 1;
		}
		if (ic_top == (0xE0 | regno)) {
			//imm8
			SetArrayLong(array_imm, 0, (sh_extsb(opc & 0xFF)));
			return 1;
		}


		//if none of the above cases, abort if regno is clobbered
		//(mem read, stack read, etc)
		if (sh_getopcode_dest(opc) == regno) {
			Message("R%d clobbered @ 0x%X, aborting\n", regno, start);
			return 0;
		}
		
		start = start - 2;

	}	//while
	return 0;
}


static report_hit(addr) {
	auto qp, comm;
	auto cur;
	cur	= ScreenEA();
	qp = form("Create comment + xref for access to %x ?\n", addr);
	if (AskYN(1,qp) == 1) {
		add_dref(cur, addr, dr_I | XREF_USER);	//type "informational"
		comm = form("0x%X", addr);
		MakeComm(cur, comm);
	}
	return;
}


//determine max backtrack address : lowest of
// * first function chunk
// * start of current func chunk (sometimes the first chunk is after the current one !)
// * (addr - fallback_delta)
static calc_maxbt(addr, fallback_delta) {
	auto first, cur, rv;

	rv = addr - fallback_delta;

	first = FirstFuncFchunk(addr);
	if (first != BADADDR) {
		if (first < rv) {
			rv = first;
		}
	}
	cur = GetFchunkAttr(addr, FUNCATTR_START);
	if (cur != -1) {
		if (cur < rv) {
			rv = cur;
		}
	}
	return rv;
}
	

//backtrack to find imm load of GBR
#define LOADGBR_MAXBT 100	//only used if we're not inside a func
static bt_loadgbr(pos) {
	auto min, opc, base;
	auto regno, gbr_imm;
	
	gbr_imm = CreateArray("gbr_imm");

	min = calc_maxbt(pos, LOADGBR_MAXBT);

	while (pos >= min) {
		opc = reconst_16(pos);
		if ((opc & 0xF0FF) == 0x401E) {
			//LDC Rm,GBR 0100mmmm00011110
			regno = (opc >> 8) & 0x0F;
			if (sh_bt_immload(gbr_imm, pos - 2, min, regno)) {
				base = GetArrayElement(AR_LONG, gbr_imm, 0);
				DeleteArray(gbr_imm);
				return base;
			}
			Message("failed to locate GBR base immload\n");
			DeleteArray(gbr_imm);
			return 0;
		}
		pos = pos - 2;
	}
	Message("failed to locate LDC Rm, GBR\n");
	DeleteArray(gbr_imm);
	return 0;
}

// test if "@(disp, GBR)", R0 form
static test_gbrref(pos) {
	auto opc, dir, mul, base, offs;
	opc = reconst_16(pos);
	dir = 0;	//0 : R. 1: W
	mul = 0;

	if (IS_MOVB_R0_GBRREF(opc) || IS_MOVW_R0_GBRREF(opc) || IS_MOVL_R0_GBRREF(opc)) {
		dir = 1;
		mul = 1 << ((opc >> 8) & 0x03);
	}
	if (IS_MOVB_GBRREF_R0(opc) || IS_MOVW_GBRREF_R0(opc) || IS_MOVL_GBRREF_R0(opc)) {
		dir = 0;
		mul = 1 << ((opc >> 8) & 0x03);
	}
	if (!mul) return;	//not a GBR opcode

	offs = (opc & 0xFF) * mul;
	base = bt_loadgbr(pos - 2);
	report_hit(base + offs);
	return;
}

#define RNREL_MAXBT 100	//only used if not inside a func

//test @(disp,Rn) forms
static test_rnrel(pos) {
	auto opc, disp, dir, regno;
	auto rndisp_imm, base;
	auto min;

	opc = reconst_16(pos);
	disp = 0;

	if ((opc & 0xF000) == 0x1000) {
			// 0001nnnnmmmmi4*4 mov.l <REG_M>,@(<disp>,<REG_N>)
		regno = ((opc >> 8) & 0x0F);	//nnnn
		disp = (opc & 0xF) * 4;
	} else if ((opc & 0xFA00) == 0x8000) {
			// 10000100mmmmi4*1 mov.b @(<disp>,<REG_M>),R0
			// 10000101mmmmi4*2 mov.w @(<disp>,<REG_M>),R0
			// 10000000mmmmi4*1 mov.b R0,@(<disp>,<REG_M>)
			// 10000001mmmmi4*2 mov.w R0,@(<disp>,<REG_M>)
		regno = ((opc >> 4) & 0x0F);	//mmmm
		if (opc & 0x0100) {
			disp = (opc & 0xF) * 2;
		} else {
			disp = (opc & 0xF) * 1;
		}
	} else if ((opc & 0xF000) == 0x5000) {
			// 0101nnnnmmmmi4*4 mov.l @(<disp>,<REG_M>),<REG_N>
		regno = ((opc >> 4) & 0x0F);	//mmmm
		disp = (opc & 0xF) * 4;
	} else {
		//invalid
		return;
	}

	//find immload for regno
	min = calc_maxbt(pos, RNREL_MAXBT);

	rndisp_imm = CreateArray("rndisp_imm");
	if (sh_bt_immload(rndisp_imm, pos - 2, min, regno)) {
		base = GetArrayElement(AR_LONG, rndisp_imm, 0);
		report_hit(base + disp);
	} else {
		Message("Rm immload not found\n");
	}
	DeleteArray(rndisp_imm);
	return;
}




// @(R0, Rn) forms
#define R0RN_MAXBT	50	//if not in a func
static test_r0rn(pos) {
	auto opc, newreg, dir;
	auto rm_imm, r0val, rmval;
	auto min;
	opc = reconst_16(pos);
	dir = 0;

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

	// need to find immload for 2 regs: R0 and <regno>
	// two cases : the correct base was either in R0, or Rx
	if (newreg == 0) {
		Message("@(R0, R0) form not supported !\n");
		return;
	}

	min = calc_maxbt(pos, R0RN_MAXBT);

	rm_imm = CreateArray("rm_imm");

	if (sh_bt_immload(rm_imm, pos - 2, min, 0)) {
		r0val = GetArrayElement(AR_LONG, rm_imm, 0);
	} else {
		DeleteArray(rm_imm);
		Message("R0 immload not found\n");
		return;
	}

	if (sh_bt_immload(rm_imm, pos - 2, min, newreg)) {
		rmval = GetArrayElement(AR_LONG, rm_imm, 0);
	} else {
		DeleteArray(rm_imm);
		Message("Rm immload not found\n");
		return;		
	}
	DeleteArray(rm_imm);

	report_hit(r0val + rmval);
	return;
}



/* test "@Rn, Rm" and "Rn, @Rm" variants (REGREF) */
#define REGREF_MAXBT	50	//if not inside a func
static test_regref(pos) {
	auto newreg, opc, offs;
	auto optop, rm_imm;
	auto min;

	opc = reconst_16(pos);

	// patterns :
	// 0010nnnnmmmm0000 mov.b <REG_M>,@<REG_N>
	// 0010nnnnmmmm0001 mov.w <REG_M>,@<REG_N>
	// 0010nnnnmmmm0010 mov.l <REG_M>,@<REG_N>
	// 0110nnnnmmmm0000 mov.b @<REG_M>,<REG_N>
	// 0110nnnnmmmm0001 mov.w @<REG_M>,<REG_N>
	// 0110nnnnmmmm0010 mov.l @<REG_M>,<REG_N>

	optop = opc & 0xB00F;	//drop bit 14 (direction)
	if  (	(optop == 0x2000) ||
			(optop == 0x2001) ||
			(optop == 0x2002) ){
		if (opc & 0x4000) {
			//@Rm, Rn
			newreg = (opc >> 4) & 0xF;
		} else {
			//Rm, @Rn
			newreg = (opc >> 8) & 0xF;
		}
		
		//find immload for regno
		min = calc_maxbt(pos, REGREF_MAXBT);
		Message("min %x\n", min);

		rm_imm = CreateArray("rm_imm");
		if (sh_bt_immload(rm_imm, pos - 2, min, newreg)) {
			offs = GetArrayElement(AR_LONG, rm_imm, 0);
			report_hit(offs);
		} else {
			Message("Rm immload not found\n");
		}
		DeleteArray(rm_imm);
	}
	return;
}


//test [logic].b  #imm, @(R0, GBR) forms
#define LOGICGBR_MAXBT	20
static test_logicgbr(pos) {
	auto opc, gbrval, r0val;
	auto min, rm_imm;

	opc = reconst_16(pos);

	// patterns:
	//AND.B #imm,@(R0,GBR) 11001101iiiiiiii
	// OR.B #imm,@(R0,GBR) 11001111iiiiiiii
	//TST.B #imm,@(R0,GBR) 11001100iiiiiiii
	//XOR.B #imm,@(R0,GBR) 11001110iiiiiiii

	if ((opc & 0xFC00) != 0xCC00) return;

	min = calc_maxbt(pos, LOGICGBR_MAXBT);

	//get R0 val:
	rm_imm = CreateArray("rm_imm");
	if (!sh_bt_immload(rm_imm, pos - 2, min, 0)) {
		Message("R0 immload not found\n");
		DeleteArray(rm_imm);
		return;
	}
	r0val = GetArrayElement(AR_LONG, rm_imm, 0);
	DeleteArray(rm_imm);

	gbrval = bt_loadgbr(pos);
	
	report_hit(gbrval + r0val);
	return;
}



//static main() {
static get_memaccess() {
	auto cur, opc, min, regno;
	//auto array_imm; //idx=0 for return value of sh_bt_immload()

	cur = ScreenEA();

	test_gbrref(cur);
	test_rnrel(cur);
	test_r0rn(cur);
	test_regref(cur);
	test_logicgbr(cur);
	return;
}
