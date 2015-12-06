// (c) fenugrec 2014
// nissan ECU checksum finder. Seems to work for at least a few ROMs (23710-8U92A, -EQ910), but not with a 23710-EB310 diesel ROM... reason unknown.
// works only with 512k or 1M ROMs (hardcoded, are there other ROM sizes ?)

// RE from xtrail rom @ sub 209C !
// theory : real ck_sum= sum of all u32 (except ck_sum and ck_xor);
//	real ck_xor = xor of all u32 (except ck_sum et ck_xor)
//	A) we can XOR everything (including cks and ckx since they are unknown yet),
//		to get xort=ckx ^ ckx ^ cks = cks (so we found the real ck_sum)
//	B) we can SUM everything (including cks and ckx), we get sumt=cks(real sum) + cks + ckx = 2*cks + ckx.
//	so we get ckx= sumt - 2*ckx, and then we try to locate cks and ckx in the ROM.
//	I'm such awesome.



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFSIZE 1024*1024

int main(int argc, char *argv[])
{
	FILE *fbin;
	uint8_t buf[BUFSIZE];	//pour loader un ROM au complet
	size_t readsize;
	size_t bufcur;
	int ckscount, ckxcount;	//count number of found instances
	
	uint32_t sumt,xort, cks, ckx;
	

	printf("Calc + find checkums:\n");
	if (argc !=2) {
		printf("%s <ROMFILE> : calc + locate checksums in 512k or 1M ROM.\n",argv[0]);
		return 0;
	}
	if ((fbin=fopen(argv[1],"rb"))==NULL) {
		printf("error opening %s.\n", argv[1]);
		return 0;
	}	
	
	readsize=fread(buf,1,BUFSIZE,fbin);	/* load ROM au complet*/
	fclose(fbin);
	if ((readsize != 1024*1024) && (readsize !=512*1024)) {
		printf("not a 512k or 1M ROM !\n");
		return 0;
	}
	printf("looking in %dk ROM...\n", readsize/1024);
	
	sumt=0;
	xort=0;
	for (bufcur=0; bufcur < readsize; bufcur += 4) {
		//loop each uint32t, but with good endianness (need to reconstruct)
		uint32_t lw;
		lw=(buf[bufcur]<<24 | buf[bufcur+1]<<16 | buf[bufcur+2]<<8 | buf[bufcur+3]);
		sumt += lw;
		xort ^= lw;
	}
	
	cks=xort;
	ckx= sumt - 2*xort;	//cheat !
	printf("sumt=0x%0X; xort=cks=0x%0X; ckx=0x%0X\n",sumt, cks, ckx);
	//try to find cks et ckx in there
	ckscount=0;
	ckxcount=0;
	for (bufcur=0; bufcur < readsize; bufcur += 4) {
		uint32_t lw;
		lw=(buf[bufcur]<<24 | buf[bufcur+1]<<16 | buf[bufcur+2]<<8 | buf[bufcur+3]);
		if (lw==cks) {
			printf("cks found @ 0x%0X\n", bufcur);
			ckscount += 1;
		}
		if (lw==ckx) {
			printf("ckx found @ 0x%0X\n", bufcur);
			ckxcount += 1;
		}
	}
	
	if (ckxcount>1 || ckscount>1)
		printf("warning : more than one occurence of checksums found ! the real checksums should be close to each other.\n");

	if (ckxcount==0 && ckscount==0)
		printf("warning : no checksum found !\n");
	
	return 0;
}
