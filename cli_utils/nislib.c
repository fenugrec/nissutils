/* collection of funcs for working with Nissan ROMs
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


uint32_t reconst_32(const uint8_t *buf) {
	// ret 4 bytes at *buf with SH endianness
	// " reconst_4B"
	return buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3];
}

uint16_t reconst_16(const uint8_t *buf) {
	return buf[0] << 8 | buf[1];
}

void write_32b(uint32_t val, uint8_t *buf) {
	//write 4 bytes at *buf with SH endianness
	// "decomp_4B"
	buf += 3;	//start at end
	*(buf--) = val & 0xFF;
	val >>= 8;
	*(buf--) = val & 0xFF;
	val >>= 8;
	*(buf--) = val & 0xFF;
	val >>= 8;
	*(buf--) = val & 0xFF;

	return;
}


// used only in enc1(), dec1()
static inline uint16_t mess1(const uint16_t a, const uint16_t b, const uint16_t x) {
	//orig : a = r4= u16 *, b=r5 = u16 *, x = [ffff8416]
	//sub 15FB2 in 8U92A
	uint16_t var2,var2b, var6;
	uint32_t var3;

	var2 = (x + b);	// & 0xFFFF;
	var3 = var2 << 2;
	var6 = (var3 >>16);

	var2b = var6 + var2 + var3 -1;

	return var2b ^ a;

}
// used only in enc1(), dec1()
static inline uint16_t mess2(const uint16_t a, const uint16_t b, const uint16_t x) {
	//orig : sub 15FDE
	uint16_t var0,var2, var3;
	uint32_t var1, var2b;

	var0 = (x + b) ;
	var1 = var0 << 1;

	var2 = (var1 >>16) + var0 + var1 -1;
	var2b = var2 << 4;
	var3 = var2b + (var2b >>16);
	return a ^ var3 ^ var2;

}

// "encode" u32 data with key 'scode'
uint32_t enc1(uint32_t data, uint32_t scode) {
	//m: scrambling code (hardcoded in ECU firmware)
	uint16_t mH,mL, sH, sL;
	uint16_t kL, kH;	//temp words

	mL = scode & 0xFFFF;
	mH= scode >> 16;
	sL = data & 0xFFFF;
	sH = data >> 16;


	kL = mess1(sH, sL, mH);

	kH = mess2(sL, kL, mL);

	return (kH << 16) | kL;
}

//decrypt 4 bytes in <data> with firmware's key <scode>
uint32_t dec1(uint32_t data, uint32_t scode) {
	//based on sub 15F18, ugly rewrite
	uint16_t scH, scL;
	uint16_t dH, dL;
	uint16_t t0, t1, tx; //temp vars

	//split in 16b words
	scH = scode >> 16;
	scL = scode;
	dH = data >> 16;
	dL = data;

	t0 = dH;
	t1 = dL;
	t0 = mess2(t0, t1, scL);
	//printf("mess1 returns %0#x\n", t0);
	tx=t0;
	t0=t1;	//swap t0,t1
	t1=tx;

	t0 = mess1(t0, t1, scH);
	//printf("mess2 returns %0#x\n", t0);
	//printf("local_0: %0#X\tlocal_1: %0#X\n", t0, t1);
	return (t0 << 16) | t1;
}


//Painfully unoptimized, because it's easy to get it wrong
const uint8_t *u8memstr(const uint8_t *buf, uint32_t buflen, const uint8_t *needle, unsigned nlen) {
	uint32_t hcur;
	assert(buf && needle && buflen && nlen && (nlen <= buflen));

	for (hcur=0; hcur < (buflen - nlen); hcur++) {
		if (memcmp(buf + hcur, needle, nlen)==0) {
			return &buf[hcur];
		}
	}

	return NULL;
}

/* manual, aligned search for u16 val */
const uint8_t *u16memstr(const uint8_t *buf, uint32_t buflen, const uint16_t needle) {
	assert(buf && (buflen >= 2));

	//hack , to help compiler : pretend we're searching for a host-endian (usually LE) value that
	//happens to have the same representation as the BE needle we're looking for.
	//e.g. (testval != needle) on a LE host, but now inside the loop we're comparing testval with a
	// u16 with host endianness. This saves a few opcodes in the short loop; about 11% faster
	u16 testval;
	*((u8 *) &testval + 0) = (u8) (needle >> 8);
	*((u8 *) &testval + 1) = (u8) (needle & 0xFF);
	uint32_t cur;
	for (cur = 0; cur <= (buflen - 2); cur += 2) {
		u16 tmp;
		memcpy(&tmp, &buf[cur], 2);	//gets optimized out
		if (tmp == testval) return &buf[cur];
		//if (reconst_16(&buf[cur]) == needle) return &buf[cur];
	}
	return NULL;
}

/* reversed, aligned search for u16 val */
const uint8_t *u16memstr_rev(const uint8_t *buf, uint32_t start_pos, const uint16_t needle) {
	start_pos &= ~1;
	assert(buf && start_pos);

	uint32_t cur = start_pos;
	for (; cur; cur -= 2) {
		if (reconst_16(&buf[cur]) == needle) return &buf[cur];
	}
	return NULL;
}

/* manual, aligned search instead of calling u8memstr; should be faster */
const uint8_t *u32memstr(const uint8_t *buf, uint32_t buflen, const uint32_t needle) {
	assert(buf && (buflen >= 4));

	uint32_t cur;
	for (cur = 0; cur <= (buflen - 4); cur += 4) {
		if (reconst_32(&buf[cur]) == needle) return &buf[cur];
	}
	return NULL;
}


// hax, get file length but restore position
u32 flen(FILE *hf) {
	long siz;
	long orig;

	assert(hf);

	orig = ftell(hf);
	if (orig < 0) return 0;

	if (fseek(hf, 0, SEEK_END)) return 0;

	siz = ftell(hf);
	if (siz < 0) siz=0;
		//the rest of the code just won't work if siz = UINT32_MAX
	#if (LONG_MAX >= UINT32_MAX)
		if ((long long) siz == (long long) UINT32_MAX) siz = 0;
	#endif

	if (fseek(hf, orig, SEEK_SET)) return 0;
	return (u32) siz;
}



const struct keyset_t known_keys[] = {
	{0x0371AEF4, 0x9AEFAABE, 0x0},
	{0x0DF7BF25, 0xF4C70C3F, 0xE9E8A966},
	{0x0E7D44A9, 0x7A4D91C3, 0x0},
	{0x0FF9C026, 0xF6C90E40, 0x0},
	{0x1701C82E, 0xFED01648, 0x0},
	{0x1C07CD33, 0x04D61B4D, 0xF8F6B875},
	{0x211CE348, 0x19EB3063, 0x0E0CCD8A},
	{0x3621E84E, 0x1FF03568, 0x0},
	{0x3722E94F, 0x1FF13669, 0x1413D390},
	{0x3823EA50, 0x20F2376A, 0x0},
	{0x3B26EC52, 0x23F53A6C, 0x1816D794},
	{0x3C24EB50, 0x21F3386B, 0x0},
	{0x3E29F056, 0x27F83D70, 0x1C1ADA97},
	{0x412CF359, 0x2AFB4073, 0x1F1DDD9A},
	{0x422DF45A, 0x2AFC4174, 0x0},
	{0x432EF55B, 0x2BFD4275, 0x0},
	{0x4D38FE64, 0x35084C7E, 0x2A28E9A6},
	{0x5414CDA6, 0xE303BF23, 0x3B17724A},
	{0x624D157A, 0x4B1D6194, 0x0},
	{0x634D157A, 0x4B1D6294, 0x403EFEBB},
	{0x6BD9175D, 0x02581327, 0x0},
	{0x6D571F84, 0x55276C9E, 0x0},
	{0x6D581F84, 0x55286C9E, 0x0},
	{0x705A2287, 0x582A6FA1, 0x4D4B0DC8},
	{0x71DE1D63, 0x085E192D, 0x0},
	{0x7374BC6A, 0x624DD2F1, 0x0},
	{0x75B4C26D, 0x419E9A48, 0x0},
	{0x78632B8F, 0x603377AA, 0xAAACEA2E},
	{0x7B472BD1, 0x8F7577FC, 0x0},
	{0x7C2300FA, 0xFF728824, 0x0},
	{0x7C672F93, 0x64377BAE, 0x595819D5},
	{0x7F6A3297, 0x673A7EB1, 0x0},
	{0x816C3398, 0x693C80B2, 0x5E5C1EDA},
	{0x88733BA0, 0x704387BA, 0x0},
	{0x8CF9387E, 0x23793448, 0xC78C8062},
	{0x8FFD3C82, 0x277C374B, 0x0},
	{0x917B43A8, 0x794C90C2, 0x0},
	{0x917C44A8, 0x794C90C3, 0x0},
	{0x9369D7EB, 0x1DABC222, 0x0},
	{0x93B645A1, 0x46A7EF9D, 0x5E353F7D},
	{0x968148AD, 0x7E5195C7, 0x737133EF},
	{0x9851EB85, 0xB4395810, 0x32F1A9FB},
	{0x98EBB319, 0xE8BBFF33, 0x0},
	{0x99C740B0, 0x3B3AD5ED, 0x0},
	{0x9CC487FA, 0xF194F820, 0x0},
	{0x9E8950B5, 0x86599DCF, 0x0},
	{0x9F8A52B7, 0x875A9ED1, 0x7C7B3CF8},
	{0xAD12D93F, 0x10E12659, 0x0503C380},
	{0xAE9961C5, 0x9669ADE0, 0x0},
	{0xB5A068CD, 0x9D70B4E7, 0x0},
	{0xBAA56CD1, 0xA275B9EB, 0x97955714},
	{0xBE8298AC, 0x560F4925, 0x0},
	{0xC02E6CB2, 0x57AC677B, 0x0},
	{0xC6E19CF0, 0x685BFBBA, 0x124DCA1B},
	{0xC7B27ADF, 0xAF82C6F9, 0x0},
	{0xC93775BB, 0x60B57084, 0x04C9BD9F},
	{0xC9DCA40A, 0xD9ACF024, 0xCECD8E4B},
	{0xCAB57DE1, 0xB285C9FC, 0x0},
	{0xCD7BB660, 0xA61BC014, 0xC5A5C5FE},
	{0xD0BB83E7, 0xB88BCF03, 0x0},
	{0xD2BD85E9, 0xBA8DD105, 0xAFAE6F2C},
	{0xD3BE86EA, 0xBB8ED206, 0x0},
	{0xE091912E, 0xF04F0066, 0x817EDC9C},
	{0xE21D9C79, 0x39DCC885, 0x0},
	{0xE5D097FC, 0xCDA0E417, 0xC2C0823F},
	{0xE7D29AFF, 0xC5C38441, 0x0},
	{0xEC5B98DE, 0x83D994A8, 0x28EDE0C2},
	{0xED19DF45, 0x16E82D5F, 0x0B09CA87},
	{0xEED9A107, 0xD6A9ED21, 0xCBCA8B48},
	{0xF0DBA309, 0xD9ABEF23, 0x0},
	{0xFB518698, 0x0BB956D3, 0x0},
	{0,0,0}
	};

const struct keyset_t *find_knownkey(enum key_type ktype, u32 candidate) {
	if ((ktype >= KEY_INVALID) || !candidate) {
		return NULL;
	}
	unsigned idx;
	for (idx = 0; known_keys[idx].s27k; idx++) {
		switch (ktype) {
		case KEY_S27:
			if (known_keys[idx].s27k == candidate) {
				return &known_keys[idx];
			}
			break;
		case KEY_S36K1:
			if (known_keys[idx].s36k1 == candidate) {
				return &known_keys[idx];
			}
			break;
		case KEY_S36K2:
			if (known_keys[idx].s36k2 == candidate) {
				return &known_keys[idx];
			}
			break;
		default:
			assert(0);
			break;
		}
	}
	return NULL;
}


/* sum and xor all u32 values in *buf, read with SH endianness */
void sum32(const uint8_t *buf, u32 siz, uint32_t *sum, uint32_t *xor) {
	u32 bufcur;
	uint32_t sumt, xort;

	assert(buf && siz && sum && xor && (siz <= MAX_ROMSIZE));

	sumt=0;
	xort=0;
	for (bufcur=0; bufcur < siz; bufcur += 4) {
		//loop each uint32, but with good endianness (need to reconstruct)
		uint32_t lw;
		lw = reconst_32(&buf[bufcur]);
		sumt += lw;
		xort ^= lw;
	}
	*sum = sumt;
	*xor = xort;
	return;
}

//calculate checksum & locations
// theory : real ck_sum= sum of all u32 (except ck_sum and ck_xor);
//	real ck_xor = xor of all u32 (except ck_sum et ck_xor)
//	A) we can XOR everything (including cks and ckx since they are unknown yet),
//		this gives xort=ckx ^ ckx ^ cks = cks (so we found the real ck_sum)
//	B) we can SUM everything (including cks and ckx), we get sumt=cks(real sum) + cks + ckx = 2*cks + ckx.
//	so we get ckx= sumt - 2*ckx, and then we try to locate cks and ckx in the ROM.
int checksum_alt2(const uint8_t *buf, uint32_t siz, uint32_t *p_ack_s, uint32_t *p_ack_x,
				uint32_t p_skip1, uint32_t p_skip2) {
	uint32_t sumt,xort, cks, ckx;

	siz &= ~3;
	assert(buf && siz && (siz <= MAX_ROMSIZE) &&
			p_ack_s && p_ack_x);

	if (p_skip1 != UINT32_MAX) {
		assert(p_skip1 < (siz - 4));
	}
	if (p_skip2 != UINT32_MAX) {
		assert(p_skip2 < (siz - 4));
	}

	sumt = xort = 0;
	sum32(buf, siz, &sumt, &xort);
	/* Optionally skip 2 extra locations by compensating sumt and xort */
	if (p_skip1 != UINT32_MAX) {
		sumt -= reconst_32(buf + p_skip1);
		xort ^= reconst_32(buf + p_skip1);
	}
	if (p_skip2 != UINT32_MAX) {
		sumt -= reconst_32(buf + p_skip2);
		xort ^= reconst_32(buf + p_skip2);
	}


	cks=xort;
	ckx= sumt - 2*xort;	//cheat !
	fprintf(dbg_stream, "alt2 sum=0x%0X; xor=0x%0X\n", cks, ckx);
	//try to find cks et ckx in there
	*p_ack_s = 0;
	*p_ack_x = 0;

	const uint8_t *tp = u32memstr(buf, siz, cks);
	if (tp) *p_ack_s = tp - buf;	//convert to offset-in-buf
	tp = u32memstr(buf, siz, ckx);
	if (tp) *p_ack_x = tp - buf;
	//do we really need to look for > 1 instance ?

	if (*p_ack_s==0 || p_ack_x==0) {
//		printf("warning : no checksum found !\n");
		return -1;
	}

	return 0;
}

//Thin wrapper around more generic checksum_alt2
int checksum_std(const uint8_t *buf, uint32_t siz, uint32_t *p_cks, uint32_t *p_ckx) {
	return checksum_alt2(buf, siz, p_cks, p_ckx, UINT32_MAX, UINT32_MAX);
}


// Steps to fix checksums :
// 1) set a,b,c to 0
// 2) calculate actual sum and xor (skipping locs p_cks and p_ckx)
// 3) determine correction values to bring actual sum and xor to the desired cks and ckx
void checksum_fix(uint8_t *buf, uint32_t siz, uint32_t p_cks, uint32_t p_ckx,
				uint32_t p_a, uint32_t p_b, uint32_t p_c) {
	uint32_t cks, ckx;	//desired sum and xor
	uint32_t ds, dx;	//actual/delta vals
	uint32_t a, b, c;	//correction vals

	siz &= ~0x03;

	//abort if siz not a multiple of 4, and other problems
	assert(buf && siz &&
		(siz <= MAX_ROMSIZE) &&
		(p_cks <= (siz - 4)) && (p_ckx <= (siz - 4)) &&
		(p_a < siz) && (p_b < siz));

	cks = reconst_32(&buf[p_cks]);
	ckx = reconst_32(&buf[p_ckx]);
	fprintf(dbg_stream, "desired cks=%X, ckx=%X\n", cks, ckx);
	if ((cks & 1) != (ckx &1)) {
		//Major problem, since both those bits should *always* match
		// (bit 0 of an addition is the XOR of all "bit 0"s !! )
		fprintf(dbg_stream, "Warning : unlikely original checksums; unmatched LSBs\n");
	}

	// 1) set correction vals to 0
	write_32b(0, &buf[p_a]);
	write_32b(0, &buf[p_b]);
	write_32b(0, &buf[p_c]);

	// 2) calc actual sum & xor
	ds=0;
	dx=0;
	sum32(buf, siz, &ds, &dx);
	// do not count orig cks and ckx
	ds = ds - (cks + ckx);
	dx = dx ^ cks ^ ckx;
	fprintf(dbg_stream, "actual s=%X, x=%X\n", ds, dx);

	//required corrections :
	ds = cks - ds;
	dx = ckx ^ dx;
	fprintf(dbg_stream, "corrections ds=%X, dx=%X\n", ds, dx);
	// 3) solve thus :
	//	- find 'c' such that c ^ dx == 0; easy : c = dx.
	//	- the new sum correction is now (ds - c)
	//	- divide the sum correction by 2 : hence,
	//		a + b == ds
	//		a ^ b == 0

	c = dx;
	ds -= c;
	a = b = ds / 2;
	//aaaand... that's it !?

	fprintf(dbg_stream, "Correction vals a=%X, b=%X, c=%X\n", a,b,c);
	//write correction vals
	write_32b(a, &buf[p_a]);
	write_32b(b, &buf[p_b]);
	write_32b(c, &buf[p_c]);
	//and verify, just for shits
	sum32(buf, siz, &ds, &dx);
	// do not count orig cks and ckx
	ds = ds - (cks + ckx);
	dx = dx ^ cks ^ ckx;
	if ((ds == cks) && (dx == ckx)) {
		fprintf(dbg_stream, "checksum fixed !\n");
	} else {
		fprintf(dbg_stream, "could not fix checksum !!\n");
	}

	return;
}


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

static bool analyze_eepread(const uint8_t *buf, uint32_t siz, uint32_t func, uint32_t *portreg) {
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

