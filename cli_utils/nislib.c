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

