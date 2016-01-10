/* collection of funcs for working with Nissan ROMs
 * (c) fenugrec 2014-2015
 * GPLv3
 */

#include <stdint.h>
#include <stdio.h>	//for printf(); probably can go away someday
#include <stdbool.h>

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

//calculate checksum & locations
// theory : real ck_sum= sum of all u32 (except ck_sum and ck_xor);
//	real ck_xor = xor of all u32 (except ck_sum et ck_xor)
//	A) we can XOR everything (including cks and ckx since they are unknown yet),
//		this gives xort=ckx ^ ckx ^ cks = cks (so we found the real ck_sum)
//	B) we can SUM everything (including cks and ckx), we get sumt=cks(real sum) + cks + ckx = 2*cks + ckx.
//	so we get ckx= sumt - 2*ckx, and then we try to locate cks and ckx in the ROM.
int checksum_std(const uint8_t *buf, long siz, long *p_cks, long *p_ckx) {
	int ckscount, ckxcount;	//count number of found instances
	long bufcur;
	uint32_t sumt,xort, cks, ckx;

	if (!buf || !p_cks || !p_ckx || (siz <= 0)) {
		return -1;
	}

	sumt=0;
	xort=0;
	for (bufcur=0; bufcur < siz; bufcur += 4) {
		//loop each uint32t, but with good endianness (need to reconstruct)
		uint32_t lw;
		lw = reconst_32(&buf[bufcur]);
		sumt += lw;
		xort ^= lw;
	}
	
	cks=xort;
	ckx= sumt - 2*xort;	//cheat !
	//printf("sumt=0x%0X; xort=cks=0x%0X; ckx=0x%0X\n",sumt, cks, ckx);
	//try to find cks et ckx in there
	ckscount=0;
	ckxcount=0;
	for (bufcur=0; bufcur < siz; bufcur += 4) {
		uint32_t lw;
		lw = reconst_32(&buf[bufcur]);
		if (lw==cks) {
			//printf("cks found @ 0x%0X\n", bufcur);
			*p_cks = bufcur;
			ckscount += 1;
		}
		if (lw==ckx) {
			//printf("ckx found @ 0x%0X\n", bufcur);
			*p_ckx = bufcur;
			ckxcount += 1;
		}
	}
	
	if (ckxcount>1 || ckscount>1)
		printf("warning : more than one set of checksums found ! the real checksums should be close to each other.\n");

	if (ckxcount==0 && ckscount==0) {
		printf("warning : no checksum found !\n");
		return -1;
	}
	
	return 0;	
}

// Steps to fix checksums :
// 1) set p_cs and p_cx to 0
// 2) calculate actual sum and xor (skipping locs p_cks and p_ckx)
// 3) determine correction values to bring actual sum and xor to the desired cks and ckx

void checksum_fix(uint8_t *buf, long siz, long p_cks, long p_ckx, long p_cs, long p_cx, long p_mang) {
	uint32_t cks, ckx;	//desired sum and xor
	uint32_t ds, dx;	//actual/delta vals
	uint32_t a, b, mang;	//correction vals
	long cur;
	
	//abort if siz not a multiple of 4, and other problems
	if (!buf || (siz <= 0) || (siz & 3) ||
		(p_cks >= siz) || (p_ckx >= siz) ||
		(p_cs >= siz) || (p_cx >= siz)) return;

	cks = reconst_32(&buf[p_cks]);
	ckx = reconst_32(&buf[p_ckx]);
	printf("desired cks=%X, ckx=%X\n", cks, ckx);
	if ((cks & 1) != (ckx &1)) {
		//Major problem, since both those bits should *always* match
		// (bit 0 of an addition is the XOR of all "bit 0"s !! )
		printf("Warning : unlikely original checksums; unmatched LSBs\n");
	}
	
	// 1) set correction vals to 0
	write_32b(0, &buf[p_cs]);
	write_32b(0, &buf[p_cx]);
	write_32b(0, &buf[p_mang]);

	// 2) calc actual sum & xor
	ds=0;
	dx=0;
	for (cur=0; cur < siz; cur += 4) {
		uint32_t tw;
		if ((cur == p_cks) || (cur == p_ckx)) continue;
		tw = reconst_32(&buf[cur]);
		ds += tw;
		dx ^= tw;
	}
	printf("actual s=%X, x=%X\n", ds, dx);
	
	//required corrections :
	ds = cks - ds;
	dx = ckx ^ dx;
	printf("corrections ds=%X, dx=%X\n", ds, dx);
	// 3) solve thus :
	//	- find 'c' (mang) such that c ^ dx == 0; easy : mang = dx.
	//	- the new sum correction is now (ds - mang)
	//	- divide the sum correction by 2 : hence,
	//		a + b == ds
	//		a ^ b == 0

	mang = dx;
	ds -= mang;
	a = b = ds / 2;
	//aaaand... that's it !?

	printf("found correction vals a=%X, b=%X, mang=%X\n", a,b,mang);
	//write correction vals
	write_32b(a, &buf[p_cs]);
	write_32b(b, &buf[p_cx]);
	write_32b(mang, &buf[p_mang]);
	//and verify, just for shits
	long ocs, ocx;
	(void) checksum_std(buf, siz, &ocs, &ocx);
	ds = reconst_32(&buf[ocs]);
	dx = reconst_32(&buf[ocx]);
	if ((ds == cks) && (dx == ckx)) {
		printf("checksum fixed !\n");
	} else {
		printf("could not fix checksum !!\n");
	}

	return;
}
