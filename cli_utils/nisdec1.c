/* nisdec1: decrypt binary file using algo_1 (NPT_DDL)
 * (c) fenugrec 2015
 * Needs the 32-bit scode to decrypt.
 * usage : nisdec1 <scode> <in_file> [<out_file>]
 * if out_file is omitted, output is written to "temp.bin"
 * scode must be in hex, such as 9851EB85 (omit the 0x prefix)
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define DEFAULT_OFILE "temp.bin"	//default output filename

uint16_t mess1(const uint16_t a, const uint16_t b, const uint16_t x) {
	//orig : a = r4= u16 *, b=r5 = u16 *, x = [ffff8416]
	//sub 15FB2 dans rom sentra
	uint16_t var2,var2b, var6;
	uint32_t var3;
	
	var2 = (x + b);	// & 0xFFFF;
	var3 = var2 << 2;
	var6 = (var3 >>16);
	
	var2b = var6 + var2 + var3 -1;
	
	return var2b ^ a;
	
}

uint16_t mess2(const uint16_t a, const uint16_t b, const uint16_t x) {
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

uint32_t prepkey(uint32_t seed, uint32_t m) {
	//m: scrambling code (hardcoded in ECU firmware)
	//seed is pseudorandom generated on SID 27 01
	uint16_t mH,mL, sH, sL;
	uint16_t kL, kH;	//temp words
	
	mL = m & 0xFFFF;
	mH= m >> 16;
	sL = seed & 0xFFFF;
	sH = seed >> 16;

	
	kL = mess1(sH, sL, mH);
	
	kH = mess2(sL, kL, mL);
	
	return (kH << 16) | kL;
}

//decrypt 4 bytes in <data> with firmware's key <scode>
uint32_t dec1(uint32_t scode, uint32_t data) {
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

uint32_t readinvb(const uint8_t *buf) {
	// ret 4 bytes at *buf with SH endianness
	// " reconst_4B"
	return buf[0] << 24 | buf[1] << 16 | buf[2] << 8 | buf[3];
}

void writeinvb(uint32_t val, uint8_t *buf) {
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

//decrypt ifh, write to ofh.
void nis_decrypt1(FILE *ifh, FILE *ofh, uint32_t scode) {
	
#define DBUFSIZ 256
	if (!ifh || !ofh) return;

	while (!feof(ifh)) {
		uint8_t ibuf[DBUFSIZ*4];	//source, encrypted
		uint8_t obuf[DBUFSIZ*4];	//decrypted
		uint8_t *icur, *ocur;
		size_t count;
		size_t realbs;	//# actually read
		
		realbs = fread(ibuf, 1, sizeof(ibuf), ifh);	//try to fill buf
		count = realbs;
		icur = ibuf;
		ocur = obuf;
		for (;count >= 4; count -= 4) {
			uint32_t block;
			uint32_t data;	//decrypted

			block = readinvb(icur);
			data = dec1(scode, block);
			writeinvb(data, ocur);
			icur += 4;
			ocur += 4;
		}
		//if the source file didn't have a multiple of 4 bytes, we may have leftovers.
		if (count) {
			printf("warning : block size is not multiple of 4; ");
			uint32_t tb=0;
			for (size_t i=0; i < count; i++) {
				tb |= *icur;
				tb <<= 8;
				icur++;
			}
			tb <<= 8 * (4 - count);	//left-justify in dword
			printf("tb : %#x\n", tb);
			writeinvb(tb, ocur);
		}
		// obuf is filled with decrypted data; write that block to output file. Round <count> up to nearest multiple of 4.
		count = (realbs + 3) & ~(0x03);
		if (fwrite(obuf, 1, count, ofh) != count) {
			perror("fwrite error !?: ");
			return;
		}
	}
}

int main(int argc, char * argv[]) {
	uint32_t scode;
	const char *ofn;	//output file name
	FILE *i_file, *o_file;
	
	if (argc < 3) {
		printf("%s <scode> <in_file> [<out_file>]\n\tscode is uint32. Uses NPT_DDL algo"
			"\n\tIf out_file is omitted, output is written to %s"
			"\n\tExample: %s 55AA00FF test.bin\n", argv[0], DEFAULT_OFILE, argv[0]);
		return 0;
	}
	
	// arg 1 : scode
	if (sscanf(argv[1], "%x", &scode) != 1) {
		printf("did not understand %s\n", argv[1]);
		return 0;
	}
	
	//2 : input file
	if ((i_file=fopen(argv[2],"rb"))==NULL) {
		printf("error opening %s.\n", argv[2]);
		return 0;
	}

	//3 : output file
	if (argc >= 4) {
		ofn = argv[3];
	} else {
		ofn = DEFAULT_OFILE;
	}
	//open it
	if ((o_file=fopen(ofn,"wb"))==NULL) {
		printf("error opening %s.\n", ofn);
		fclose(i_file);
		return 0;
	}

	rewind(i_file);

	nis_decrypt1(i_file,o_file,scode);
	fclose(i_file);
	fclose(o_file);

	return 0;
}

