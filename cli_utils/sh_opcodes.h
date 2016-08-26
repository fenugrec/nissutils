#ifndef _SH_OPCODES_H
#define _SH_OPCODES_H

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


#endif
