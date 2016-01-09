/* collection of funcs for working with Nissan ROMs
 * (c) fenugrec 2014-2015
 * GPLv3
 */

#include <stdint.h>
#include <stdio.h>	//for printf(); probably can go away someday

uint32_t reconst_32(const uint8_t *buf) {
	// ret 4 bytes at *buf with SH endianness
	// " reconst_4B"
	return buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3];
}

uint16_t reconst_16(const uint8_t *buf) {
	return buf[0] << 8 | buf[1];
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
