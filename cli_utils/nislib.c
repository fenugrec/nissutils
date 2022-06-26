/* collection of funcs for working with Nissan ROMs
 * (c) fenugrec 2014-2015
 * GPLv3
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>	//for printf(); probably can go away someday
#include <string.h>
#include <stdbool.h>
#include "nislib.h"
#include "nissan_romdefs.h"
#include "sh_opcodes.h"
#include "stypes.h"

/****** fwd decls */
u32 sh_extsb(u8 val);
u32 sh_extsw(u16 val);


/****** misc stuff */
#define MIN(_a_, _b_) (((_a_) < (_b_) ? (_a_) : (_b_)))
#define MAX(_a_, _b_) (((_a_) > (_b_) ? (_a_) : (_b_)))


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
	buflen &= ~1;
	assert(buf && buflen);

	uint32_t cur;
	for (cur = 0; cur < buflen; cur += 2) {
		if (reconst_16(&buf[cur]) == needle) return &buf[cur];
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
	buflen &= ~3;
	assert(buf && buflen);

	uint32_t cur;
	for (cur = 0; cur < buflen; cur += 4) {
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


const struct fidtype_t fidtypes[] = {
	[FID705101] = {	.fti = FID705101,
			.FIDIC = "SH705101",
			.ROMsize = 256*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),
			.pRAMF_maxdist = 0x380,
			.RAMF_header = 0xFFFFD800,
			.features = ROM_HAS_STDCKS | ROM_HAS_LOADERLESS,
			.pRAMjump = 0x10,
			.pRAM_DLAmax = 0,
			.pRAMinit = 0,
			},
	[FID705415] = {	.fti = FID705415,
			.FIDIC = "SH705415",
			.ROMsize = 384*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),
			.pRAMF_maxdist = 0x0c,
			.RAMF_header = 0xFFFF8000,
			.features = ROM_HAS_STDCKS | ROM_HAS_ALTCKS | ROM_HAS_IVT2,
			.pRAMjump = 0x10,
			.pRAM_DLAmax = 0x14,
			.pRAMinit = 0x28,
			.packs_start = 0x3c,
			.packs_end = 0x40,
			.pIVT2 = 0x44,
			.IVT2_expected = 0x1000
			},
	[FID705507] = {	.fti = FID705507,
			.FIDIC = "SH705507",
			.ROMsize = 512*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),
			.pRAMF_maxdist = 0x300,
			.RAMF_header = 0xFFFF8000,
			.features = ROM_HAS_STDCKS | ROM_HAS_ALTCKS | ROM_HAS_LOADERLESS,	//for some reason, some 705507 ROMs don't have ALTCKS (like 4M860), for no obvious reason.
			.pRAMjump = 0x10,
			.pRAM_DLAmax = 0x14,
			.pRAMinit = 0x28,
			.packs_start = 0x3c,
			.packs_end = 0x40,
			},
	[FID705513] = {	.fti = FID705513,
			.FIDIC = "SH705513",
			.ROMsize = 512*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),
			.pRAMF_maxdist = 0x0c,
			.RAMF_header = 0xFFFF8000,
			.features = ROM_HAS_STDCKS | ROM_HAS_ALTCKS | ROM_HAS_IVT2,
			.pRAMjump = 0x10,
			.pRAM_DLAmax = 0x14,
			.pRAMinit = 0x28,
			.packs_start = 0x3c,
			.packs_end = 0x40,
			.pIVT2 = 0x44,
			.IVT2_expected = 0x1000,
			},
	[FID705519] = {	.fti = FID705519,
			.FIDIC = "SH705519",
			.ROMsize = 512*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),
			.features = ROM_HAS_ALTCKS | ROM_HAS_ALT2CKS | ROM_HAS_IVT2 | ROM_HAS_ECUREC,
			.packs_start = -8,
			.packs_end = -4,
			.pECUREC = 0,
			.pROMend = 4,
			.pIVT2 = 8,
			.IVT2_expected = 0x10004,
			},
	[FID705520] = {	.fti = FID705520,
			.FIDIC = "SH705520",
			.ROMsize = 512*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),
			.pRAMF_maxdist = 0x0c,
			.RAMF_header = 0xFFFF8000,
			.features = ROM_HAS_STDCKS | ROM_HAS_ALTCKS | ROM_HAS_IVT2,
			.pRAMjump = 0x10,
			.pRAM_DLAmax = 0x14,
			.pRAMinit = 0x30,
			.packs_start = 0x44,
			.packs_end = 0x48,
			.pIVT2 = 0x4c,
			.IVT2_expected = 0x1000,
			},
	[FID705821] = {	.fti = FID705821,
			.FIDIC = "SH705821",
			.ROMsize = 1024*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),
			.pRAMF_maxdist = 0x0c,
			.RAMF_header = 0xFFFF8000,
			.features = ROM_HAS_STDCKS | ROM_HAS_ALTCKS | ROM_HAS_IVT2,
			.pRAMjump = 0x18,
			.pRAM_DLAmax = 0x1c,
			.pRAMinit = 0x38,
			.packs_start = 0x4c,
			.packs_end = 0x50,
			.pIVT2 = 0x54,
			.IVT2_expected = 0x1000,
			},
	[FID705822] = {	.fti = FID705822,
			.FIDIC = "SH705822",
			.ROMsize = 1024*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),	/* some have 8 extra bytes */
			/* this could almost have ROM_HAS_ECUREC, but that would fail on ZB060 for no clear reason */
			.pRAMF_maxdist = 0x0c,
			.RAMF_header = 0xFFFF8000,
			.features = ROM_HAS_ALTCKS | ROM_HAS_ALT2CKS | ROM_HAS_IVT2,
			.pRAMjump = 0x18,
			.pRAM_DLAmax = 0x1c,
			.pRAMinit = 0x40,
			.packs_start = 0x54,
			.packs_end = 0x58,
			.pIVT2 = 0x64,
 			.IVT2_expected = 0x20004,
			.pROMend = 0x60,
			.pECUREC = 0x5c,
			},
	[FID705823] = {	.fti = FID705823,
			.FIDIC = "SH705823",
			.ROMsize = 1024*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),
			.pRAMF_maxdist = 0x0c,
			.RAMF_header = 0xFFFF8000,
			.features = ROM_HAS_STDCKS | ROM_HAS_ALTCKS | ROM_HAS_IVT2,
			.pRAMjump = 0x18,
			.pRAM_DLAmax = 0x1c,
			.pRAMinit = 0x38,
			.packs_start = 0x4c,
			.packs_end = 0x50,
			.pIVT2 = 0x54,
			.IVT2_expected = 0x2000,
			},
	[FID705828] = {	.fti = FID705828,
			.FIDIC = "SH705828",
			.ROMsize = 1024*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t) + 4,	/* some would need +8 here */
			.features = ROM_HAS_ALTCKS | ROM_HAS_ALT2CKS | ROM_HAS_IVT2 | ROM_HAS_ECUREC,
			.packs_start = -8,
			.packs_end = -4,
			.pECUREC = 0,
			.pROMend = 4,
			.pIVT2 = 8,
			.IVT2_expected = 0x20004,
			},
	[FID705927] = {	.fti = FID705927,
			.FIDIC = "SH705927",		/** tentative values here. */
			.ROMsize = 1536*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t) + 8,
			.features = ROM_HAS_ALTCKS | ROM_HAS_ALT2CKS | ROM_HAS_IVT2 | ROM_HAS_ECUREC,
			.packs_start = -8,
			.packs_end = -4,
			.pECUREC = 0,
			.pROMend = 4,
			.pIVT2 = 8,
			.IVT2_expected = 0x20004,

			},
	[FID7253331] = {	.fti = FID7253331,
			.FIDIC = "S7253331",		/** tentative values here. See 4EF2A, 4CE1A */
			.ROMsize = 2048*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),	//not really; no MSTCR fields ?
			.features = ROM_HAS_ALTCKS | ROM_HAS_ALT2CKS | ROM_HAS_IVT2 | ROM_HAS_ECUREC,
			.packs_start = -8,
			.packs_end = -4,
			.pECUREC = 0,
			.pROMend = 4,
			.pIVT2 = 8,
			.IVT2_expected = 0x70004,
			},
	[FID7253332] = {	.fti = FID7253332,
			.FIDIC = "S7253332",		/** very tentative values here */
			.ROMsize = 2048*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),	//not really; no MSTCR fields ?
			.features = ROM_HAS_ALTCKS | ROM_HAS_ALT2CKS | ROM_HAS_IVT2 | ROM_HAS_ECUREC,
			.packs_start = -8,
			.packs_end = -4,
			.pECUREC = 0,
			.pROMend = 4,
			.pIVT2 = 8,
			.IVT2_expected = 0x70004,
			},
	[FID7254332] = {	.fti = FID7254332,
			.FIDIC = "S7254332",		/** some tentative values here */
			.ROMsize = 2048*1024U,
			.FIDbase_size = sizeof(struct fid_base1_t),	//not really; no MSTCR fields ?
			.features = ROM_HAS_ALTCKS | ROM_HAS_ALT2CKS | ROM_HAS_IVT2 | ROM_HAS_ECUREC,
			.packs_start = -8,
			.packs_end = -4,
			.pECUREC = 0,
			.pROMend = 4,
			.pIVT2 = 8,
			.IVT2_expected = 0x70004,
			},
	[FID_UNK] = {	.fti = FID_UNK,
			},
};	//fidtypes[]


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
bool check_ivt(const uint8_t *buf) {
	uint32_t por_pc, por_sp;
	uint32_t mr_pc, mr_sp;

	assert(buf);

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
	for (offs = 0; siz > 0; siz -= 4, offs += 4) {
		if (check_ivt(buf + offs)) return offs;
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


uint32_t sh_get_PCimm(const uint8_t *buf, uint32_t pos) {
	uint16_t opc;

	assert(buf);

	opc = reconst_16(&buf[pos]);

	if (opc & 0x4000) {
		//mov.l
		pos += ((opc & 0xFF) * 4) + 4;
		/* essential : align 4 !!! */
		pos &= ~0x03;
		//printf("retrieve &er() from 0x%0X\n", pos);
		pos = reconst_32(&buf[pos]);
	} else {
		//mov.w
		u16 lit;
		pos += ((opc & 0xFF) * 2) + 4;
		//printf("retrieve &er() from 0x%0X\n", pos);
		lit = reconst_16(&buf[pos]);
		pos = sh_extsw(lit);	//sign-extend
	}
	return pos;
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
			if ((opc & 0xF0FF) != 0x400B) continue;
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

/** Find opcode pattern... bleh
 * "patlen" is # of opcodes
 */
uint32_t find_pattern(const uint8_t *buf, uint32_t siz, unsigned patlen,
			const uint16_t *pat, const uint16_t *mask) {
	uint32_t bcur = 0;	//base cursor for start of pattern
	uint32_t hcur = 0;	//iterating cursor
	unsigned patcur = 0;	//cursor within pattern

	assert(buf && siz && patlen && pat && mask &&
		(siz <= MAX_ROMSIZE));

	while (hcur < (siz - patlen * 2)) {
		uint16_t val;
		val = reconst_16(&buf[hcur + patcur * 2]);
		if ((val & mask[patcur]) == (pat[patcur] & mask[patcur])) {
			if (patcur == 0) bcur = hcur;
			patcur += 1;
			if (patcur == patlen) {
				//complete match !
				return bcur;
			}
			continue;
		}
		//no match : continue where we started
		patcur = 0;
		//hcur = bcur;
		hcur += 2;
	}
	//no match : ret -1 (illegal val)
	return -1;
}


/** sign-extend u8 value to u32, like exts.b */
u32 sh_extsb(u8 val) {
	if (val & 0x80) return 0xFFFFFF00 | val;
	return val;
}

/** Sign-extend u16 value to u32, like exts.w */
u32 sh_extsw(u16 val) {
	if (val & 0x8000) return 0xFFFF0000 | val;
	return val;
}




int sh_bt_immload(u32 *imm, const uint8_t *buf, uint32_t min, uint32_t start,
				unsigned regno) {


	assert(imm && buf && (regno <= 0x0F));

	while (start >= min) {
		unsigned new_regno;
		uint16_t opc = reconst_16(&buf[start]);

		// 1) limit search to function head. Problem : sometimes this opcode is not at the head of the function !
		//if (opc == 0x4F22) return 0;

		// 2a) if we're copying from another reg, we need to recurse. opc format :
		// mov Rm, R(regno) [6n m3]
		if ((opc & 0xFF0F) == (0x6003 | (regno << 8))) {
			start -= 2;
			new_regno = (opc & 0xF0) >> 4;

			if (sh_bt_immload(imm, buf, min, start, new_regno)) {
				//Suxxess : found literal
				return 1;
			}
			// recurse failed; probably loaded from arglist or some other shit
			return 0;
		}

		// 2b) if we had a "shlr16" into regno, recurse too and shift immediate before returning.
		if (opc == (0x4029 | (regno << 8))) {
			u32 new_bt;
			start -= 2;

			if (sh_bt_immload(&new_bt, buf, min, start, regno)) {
				//Suxxess : found literal
				*imm = new_bt >> 16;
				return 1;
			}
			// recurse failed; probably loaded from arglist or some other shit
			return 0;
		}

		// 2c) EXTU.B Rm,Rn 0110nnnnmmmm1100 : special case of mov R,R : also recurse
		if ((opc & 0xFF0F) == (0x600C | (regno << 8))) {
			u32 new_bt;
			new_regno = (opc >> 4) & 0x0F;	//follow Rm
			start -= 2;

			if (sh_bt_immload(&new_bt, buf, min, start, new_regno)) {
				*imm = new_bt & 0xFF;
				return 1;
			}
			return 0;
		}

		// 2d) shll, shll2 : recurse and shift before returning
		if ((opc & 0xFFF7) == (0x4000 | (regno << 8))) {
			u32 new_bt;
			bool is_shll2 = (opc & 0x0008);

			start -= 2;
			//printf("\t\t***********shll @ %lX\n", (unsigned long) start);

			if (sh_bt_immload(&new_bt, buf, min, start, regno)) {
				if (is_shll2) {
					*imm = (new_bt << 2);
				} else {
					*imm = (new_bt << 1);
				}
				return 1;
			}
			return 0;
		}

		// 2e) add imm8: recurse and add before returning. b'0111nnnniiiiiiii'
		if ((opc & 0xFF00) == (0x7000 | (regno << 8))) {
			u32 add_s8;
			u32 new_bt;
			add_s8 = sh_extsb(opc & 0xFF);
			start -= 2;
			//printf("\t\t***********add @ %lX\n", (unsigned long) start);

			if (sh_bt_immload(&new_bt, buf, min, start, regno)) {
				*imm = (new_bt + add_s8);
				return 1;
			}
			return 0;
		}

		// 2f) add Rm, R<regno>: recurse for Rm and regno again; add before ret
		//ADD Rm,Rn 0011nnnnmmmm1100 Rn + Rm => Rn
		if ((opc & 0xFF0F) == (0x300C | (regno << 8))) {
			u32 add_src, add_src2;

			start -= 2;
			//printf("add rm, regno : recurs @ %X\n", start);
			new_regno = (opc >> 4) & 0x0F;
			if (sh_bt_immload(&add_src, buf, min, start, new_regno)) {
				//found Rm
				if (sh_bt_immload(&add_src2, buf, min, start, regno)) {
					//found Rn too
					*imm = (add_src + add_src2);
					return 1;
				}
			}
			return 0;
		}

		// 3) no recursion : try to find load_immediate.
		// "mov #imm8, R<regno>"	[E<regno> <i>]
		// "mov.w @(disp, PC), R<regno> 	[9<regno> <disp/2>]
		// "mov.l @(disp, PC), R<regno> 	[D<regno> <disp/4>]
		// "movi20 #imm20, R<regno>	[0<regno> <i16_19> 0][i0_15]
		// test for the "movi20" variant first, because it takes up 2 opcodes
		uint16_t prevop = reconst_16(&buf[start - 2]);
		if ((prevop & 0xFF0F) == (regno << 8)) {
			//movi20 match. just keep lower 16 bits sign-extended
			*imm = sh_extsw(opc);
			return 1;
		}
		uint8_t ic_top = (opc & 0xFF00) >> 8;
		uint32_t imloc = start; //location of mov instruction
		if (ic_top == (0xD0 | regno)) {
			//imm32 with possible shift16
			imloc += ((opc & 0xFF) * 4) + 4;
			/* essential : align 4 !!! */
			imloc &= ~0x03;
			//printf("retrieve &er() from 0x%0X\n", jackpot);
			*imm = reconst_32(&buf[imloc]);
			return 1;
		}
		if (ic_top == (0x90 | regno)) {
			//imm16
			imloc += ((opc & 0xFF) * 2) + 4;
			//printf("retrieve &er() from 0x%0X\n", jackpot);
			*imm = sh_extsw(reconst_16(&buf[imloc]));
			return 1;
		}
		if (ic_top == (0xE0 | regno)) {
			//imm8
			*imm = sh_extsb(opc & 0xFF);
			return 1;
		}

		if (sh_getopcode_dest(opc) == regno) {
			//Rn clobbered
			return 0;
		}

		start -= 2;

	}	//while
	return 0;
}

/* backtrack inside function (the one with "bsr swapf") to find key constant store-to-mem;
 * this will match
 *	mov.w R0, @(disp, gbr)	[C1 <dd>]
 *	mov.w R0, @(disp, Rn)	[81 <nd>]
 *	mov.w Rm, @Rn	[<2n> <m1>]
 *
 * For each occurence, backtrack recursively (until function header) to find what immediate value is stored to mem.
 * this assumes that the lower 16bit half-key gets loaded at a higher RAM address than the other half
 *
 * @return the key if found, 0 otherwise
 */
#define S27_IMM_MAXBT	0x70	//max # of bytes to backtrack
static uint32_t fs27_bt_stmem(const uint8_t *buf, uint32_t bsr_offs) {
	const uint32_t min = bsr_offs - S27_IMM_MAXBT;
	int occ = 0;
	int occ_dist[2] = {0,0}; //find out which 16-bit key half is loaded at a lower RAM address
	uint32_t key = 0;
	uint16_t h[2];	//halfkeys

	assert(buf && (bsr_offs < MAX_ROMSIZE));

	uint32_t cur = bsr_offs;
	while ((cur >= min) && (occ < 2)) {
		uint16_t opc;
		unsigned regno;
		opc = reconst_16(&buf[cur]);

		if (	IS_MOVW_R0_GBRREF(opc) ||
			IS_MOVW_R0_REGDISP(opc)) {
			// but skip any "r0, @(disp + r15) ops
			if ((opc & 0xFFF0) == 0x81F0) goto next;
			regno = 0;
			u32 rv;
			if (sh_bt_immload(&rv, buf, min, cur - 2, regno)) {
				//printf("imm->mem(gbr) store %d : %X\n", occ, rv);
				occ_dist[occ] = opc & 0xFF;
				h[occ] = (u16) rv;
				occ += 1;
			}
		}
		if (IS_MOVW_REG_TO_REGREF(opc)) {
			//"mov.w Rm, @Rn" form. skip if @r15
			if ((opc & 0xFF00) == 0x2F00) goto next;
			regno = (opc & 0xF0) >> 4;
			u32 rv;
			if (sh_bt_immload(&rv, buf, min, cur - 2, regno)) {
				//printf("imm->mem(Rn) store #%d : %X\n", occ, rv);
				occ_dist[occ] = 0;
				h[occ] = (u16) rv;
				occ += 1;
			}
		}
	next:
		cur -= 2;
	}
	if (occ != 2) {
		fprintf(dbg_stream, "couldn't find two imm->mem stores ?\n");
		return 0;
	}
	/* rebuild key from halves : */
	if (occ_dist[0] < occ_dist[1]) {
		key = h[1] | (h[0] << 16);
	} else {
		key = h[0] | (h[1] << 16);
	}
	fprintf(dbg_stream, "key : %lX\n", (unsigned long) key);
	return key;
}




/* Find all "bsr N" occurences that call the function at <tgt>.
 * for every hit, calls <callback>(<data>), a generic proto
 */
void find_bsr(const u8 *buf, u32 tgt, void (*found_bsr_cb)(const u8 *buf, u32 pos, void *data), void *cbdata) {

	/*
	 * bsr opcode : 1011 dddd dddd dddd
	 * displacement range = 2*disp == [-4096, +4094] + PC
	 *
	 */
	int sign = 1;
	int disp = 0;

	assert(buf && (tgt < MAX_ROMSIZE) && found_bsr_cb);

	/* iterate, starting at the position where the opcode "B0 00" would jump to "swapf". */
	while ((sign * disp) != -4096) {
		uint16_t opc;
		uint32_t bsr_offs = tgt - 4 - (sign * disp);
		opc = reconst_16(&buf[bsr_offs]);
		// is it a "bsr" with the correct offset ?
		if (opc == (0xB000 | ((sign * disp / 2) & 0xFFF))) {
			found_bsr_cb(buf, bsr_offs, cbdata);
		}
		sign = -sign;
		if (sign == 1) disp +=2 ;
	}
	return;

}


struct s27_keyfinding {
	int swapf_xrefs;	//# of occurences
	bool s27_found;
	bool s36_found;
	u32 s27k_pos;	//position in ROM
	u32 s36k_pos;
	uint32_t *s27k;
	uint32_t *s36k;		//where to store the keys found
};

/* callback for every "bsr swapf" hit */
static void found_strat1_bsr(const u8 *buf, u32 pos, void *data) {
	struct s27_keyfinding *skf;

	assert(buf && (pos < MAX_ROMSIZE) && data);

	fprintf(dbg_stream, "found bsr swapf at %lX\n", (unsigned long) pos);
	skf = data;
	skf->swapf_xrefs += 1;
	/* now, backtrack to find constants */
	/* TODO : determine if the key is for sid27 or sid36; this just assumes that the first key we find
	 * is the s36 one. This has been true for a lot of ROMs, but is just lucky. */
	uint32_t key;
	key = fs27_bt_stmem(buf, pos);
	if (key && skf->s36_found) {
		*skf->s27k = key;
		skf->s27k_pos = pos;
		skf->s27_found = 1;
	} else if (key) {
		*skf->s36k = key;
		skf->s36k_pos = pos;
		skf->s36_found = 1;
	}
	return;
}


/** backtrack, starting at &buf[starpos], trying to find a MOV.W R0, @(disp, Rn)
*
* @param min : lower bounds of search at &buf[min]
* @param found_pos : if found, position of hit
* @param reg_dest : if found, Rn number
* @param disp : if found, displacement (in bytes)
*
* @return 1 if ok
*/
static bool bt_MOVW_R0_REGDISP(const u8 *buf, u32 startpos, u32 min, u32 *found_pos, enum opcode_dest *reg_dest, unsigned *disp) {
	assert(buf && found_pos && reg_dest && disp);

	startpos += 2;	//cheat
	while (startpos && (startpos > min)) {
		startpos -= 2;
		u16 test = reconst_16(&buf[startpos]);

		if (!IS_MOVW_R0_REGDISP(test)) {
			continue;
		}
		*found_pos = startpos;
		*reg_dest = (test >> 4) & 0x0F;
		*disp = (test & 0x0F) * 2;
		return 1;
	}
	return 0;
}

/** callback for every bsr encrypt() for second sid27 strategy.
 *
 * could be either in sid27 or sid36 function, but what seems to be common
 * (6GE2C, EZ11D) is to write both halfkeys to consecutive RAM locations,
 * with a MOV.W R0, @(disp, Rn)
 *
 * Can't directly use fs27_bt_stmem() since that is too permissive
 */
static void found_strat2_bsr(const u8 *buf, u32 pos, void *data) {
#define S27_STRAT2_MOVW_MAXDIST	30
	assert(buf && data);

	// backtrack and search for a MOV.W R0, @(disp, Rn) 10000001nnnndddd
	u32 movw_pos;
	u32 min_pos = pos - MIN(pos, S27_STRAT2_MOVW_MAXDIST);

	enum opcode_dest reg_dest;
	unsigned mem_disp = 0;

	bool found = bt_MOVW_R0_REGDISP(buf, pos, min_pos, &movw_pos, &reg_dest, &mem_disp);
	if (!found) {
		fprintf(dbg_stream, "found a weird strat2 bsr @ %lX. Look here for sid27 / sid36 keys !\n", (unsigned long) pos);
		return;
	}
	fprintf(dbg_stream, "found a strat2 bsr @ %lX. Look here for sid27 / sid36 keys !\n", (unsigned long) pos);

	// next : find value loaded into R0 , this is KEY_L
	u16 key_l, key_h;
	u32 imm_temp;
	if (sh_bt_immload(&imm_temp, buf, movw_pos - MIN(movw_pos, S27_STRAT2_MOVW_MAXDIST), movw_pos, 0)) {
		//probably found a halfkey
		key_l = (u16) imm_temp & 0xFFFF;
		fprintf(dbg_stream, "halfkey 0x%04X\n", (unsigned) key_l);
	} else {
		//can't continue
		return;
	}

	//continue movw search but keep only hits that write to mem_disp +/- 2
	unsigned original_memdisp = mem_disp;	//displacement where key_l was stored
	enum opcode_dest original_regdest = reg_dest;
	found = 0;
	min_pos = movw_pos - MIN(movw_pos, S27_STRAT2_MOVW_MAXDIST);
	movw_pos = movw_pos - MIN(movw_pos, 2);	//go back 1 opcode
	while (!found) {
		if (!bt_MOVW_R0_REGDISP(buf, movw_pos, min_pos, &movw_pos, &reg_dest, &mem_disp)) {
			// no hit in window : can't continue.
			return;
		}
		if ((((mem_disp + 2) != original_memdisp) &&
			(mem_disp - 2) != original_memdisp) &&
			(reg_dest != original_regdest)) {
			// found a movw but wrong destination or wrong base reg : keep looking
			continue;
		}
		if (sh_bt_immload(&imm_temp, buf, movw_pos - MIN(movw_pos, S27_STRAT2_MOVW_MAXDIST), movw_pos, 0)) {
			key_h = (u16) imm_temp & 0xFFFF;
			fprintf(dbg_stream, "halfkey 0x%04X\n", (unsigned) key_h);
			found = 1;
		}
		break;
	}

	if (!found) {
		fprintf(dbg_stream, "strat2 couldn't find other halfkey\n");
		return;
	}
	u32 key_candidate = (key_h << 16) + key_l;
	// not sure if we found a s27 or s36 key. Best scenario is finding it in known keysets
	struct s27_keyfinding *skf = data;

	unsigned keyset = 0;
	while (known_keys[keyset].s27k != 0) {
		uint32_t curkey;
		curkey = known_keys[keyset].s27k;

		if (curkey == key_candidate) {
			skf->s27_found = 1;
			*skf->s27k = key_candidate;
			skf->s27k_pos = movw_pos;
		}
		curkey = known_keys[keyset].s36k1;
		if (curkey == key_candidate) {
			skf->s36_found = 1;
			*skf->s36k = key_candidate;
			skf->s36k_pos = movw_pos;
		}
		curkey = known_keys[keyset].s36k2;
		fprintf(dbg_stream, "strat2 indirectly found a known SID36k2 : 0x%08lX\n", (unsigned long) key_candidate);
		keyset++;
	}
	return;
}

/* Second strategy (designed for SH705927) :
 - find sequence of shlr and xor opcodes targeting the same reg. Example from 6GE2C:
	0004398c 45 29           shlr16     r5
	0004398e 35 1c           add        r1,r5
	00043990 25 7a           xor        r7,r5
	00043992 25 2a           xor        r2,r5
	00043994 00 0b           rts
 * this is part of a short encrypt() function that uses the lower halfkey.
 */

#define S27_STRAT2_PATLEN 3
static const uint16_t spf2_pattern[]={0x4529, 0x351c, 0x257a, 0x252a, 0x000b};
static const uint16_t spf2_mask[]={0xf0ff, 0xf00f, 0xf00f, 0xf00f, 0xffff};
#define S27_STRAT2_MAX_FUNCLEN 0x30	// max distance between function entry and start of pattern. Typically around 0x22

bool find_s27_strat2(const uint8_t *buf, uint32_t siz, uint32_t *s27k, uint32_t *s36k) {
	assert(buf && siz && (siz <= MAX_ROMSIZE) && s27k && s36k);

	struct s27_keyfinding skf={0};
	skf.s27k = s27k;
	skf.s27_found = 0;
	skf.s36k = s36k;
	skf.s36_found = 0;
	skf.swapf_xrefs = 0;	//xrefs to "encrypt" func ; should be 2, one from each S27 and S36 func

	rom_offset swapf_cur = 0;

	while ( swapf_cur < (siz - S27_STRAT2_MAX_FUNCLEN)) {
		u32 patpos;
		patpos = find_pattern(&buf[swapf_cur], siz - swapf_cur,
			S27_STRAT2_PATLEN, spf2_pattern, spf2_mask);
		if (patpos == UINT32_MAX) break;
		assert((patpos & 1) == 0);

		patpos += swapf_cur;	//re-adjust to a rom_offset !
		swapf_cur = patpos + 2;

		// backtrack to guess function entry , by looking for previous RTS opcode.
		u32 searchlength = MIN(patpos, S27_STRAT2_MAX_FUNCLEN);	//safe clamp
		rom_offset startpos = patpos - searchlength;
		const u8 *maybe_entry = u16memstr_rev(&buf[startpos], searchlength, 0x000b);

		if (!maybe_entry) {
			fprintf(dbg_stream, "found a weird encrypt() pattern @ %lX\n", (unsigned long) patpos);
			continue;
		}
		rom_offset func_entry = (rom_offset) (maybe_entry - buf) + 4;	//skip over RTS and slot opcode

		fprintf(dbg_stream, "found a likely encrypt() func @ %lX\n", (unsigned long) func_entry);

		/* Find xrefs (bsr) to this possible encrypt() instance. */
		find_bsr(buf, func_entry, found_strat2_bsr, &skf);
	}

	if (skf.s27_found && skf.s36_found) {
		fprintf(dbg_stream, "keys guessed: s27k @ 0x%06lX, s36k1 @ 0x%06lX\n",
				(unsigned long) skf.s27k_pos, (unsigned long) skf.s36k_pos);
		return 1;
	}
	return 0;
}


/* First strategy to find SID 27 keys :
 - find "swapf" function used by both encr / decryption
 - find xrefs to "swapf" (exactly 2)
 - follow xref
 */

#define S27_SPF_PATLEN 5
static const uint16_t spf_pattern[]={0x6001, 0x6001, 0x2001, 0x000b, 0x2001};
static const uint16_t spf_mask[]={0xf00f, 0xf00f, 0xf00f, 0xffff, 0xf00f};

bool find_s27_strat1(const uint8_t *buf, uint32_t siz, uint32_t *s27k, uint32_t *s36k) {
	uint32_t swapf_cur = 0;
	//int swapf_instances = 0;

	assert(buf && siz && (siz <= MAX_ROMSIZE) && s27k && s36k);

	struct s27_keyfinding skf={0};
	skf.s27k = s27k;
	skf.s27_found = 0;
	skf.s36k = s36k;
	skf.s36_found = 0;
	skf.swapf_xrefs = 0;


	while ( swapf_cur < siz ) {
		uint32_t patpos;
		patpos = find_pattern(&buf[swapf_cur], siz - swapf_cur,
			S27_SPF_PATLEN, spf_pattern, spf_mask);
		if (patpos == (u32) -1) break;
		patpos += swapf_cur;	//re-adjust !
		//swapf_instances +=1 ;
		//printf("got 1 swapf @ %0lX;\n", patpos + 0UL);

		/* Find xrefs (bsr) to this swapf instance. */
		find_bsr(buf, patpos, found_strat1_bsr, &skf);

		swapf_cur = patpos + 2;

	}
	if (skf.s27_found && skf.s36_found) {
		fprintf(dbg_stream, "keys guessed: s27k @ 0x%06lX, s36k1 @ 0x%06lX\n",
				(unsigned long) skf.s27k_pos, (unsigned long) skf.s36k_pos);
		return 1;
	}
	return 0;

}

/** try to guess SID27 keys using cleverness and gnarly heuristics
*/
bool find_s27_hardcore(const uint8_t *buf, uint32_t siz, uint32_t *s27k, uint32_t *s36k) {
	assert(buf && siz && (siz <= MAX_ROMSIZE) && s27k && s36k);

	bool found;

	found = find_s27_strat1(buf, siz, s27k, s36k);
	if (found) {
		return 1;
	}

	found = find_s27_strat2(buf, siz, s27k, s36k);
	if (found) {
		return 1;
	}

	return 0;
}


/* unreliable - check if opcode at *buf could be a valid func prologue.
 * for now, accepts :
 * "2F <Rn>6" (mov.l Rn, @-r15)
 * "4F 22 (sts.l pr, @-r15)
 */
static bool sh_isprologue(const uint8_t *buf) {
	uint16_t opc;
	assert(buf);

	opc = reconst_16(buf);
	if (	((opc & 0xFF0F) == 0x2F06) ||
		(opc == 0x4F22)) {
		return 1;
	}
	return 0;
}


#define FCALLTABLE_MINLENGTH 50	//typically > 100 function pointers though
#define FCALLTABLE_IVTSKIP 0x400	//skip any IVT found
#define FCALLTABLE_PROLOGS 10		//ugly hack to recognize function prologues
#define FCALLTABLE_MAXDUPS 10		//discard table if too many duplicate ptrs (like in IVTs)

uint32_t find_calltable(const uint8_t *buf, uint32_t skip, uint32_t siz, unsigned *ctlen) {
	uint32_t cur;
	unsigned consec = 0;
	unsigned good_prologs = 0;
	uint32_t table_start;
	uint32_t dupcheck = 0;
	unsigned dupcount = 0;

	siz &= ~3;
	assert(buf && siz && (siz <= MAX_ROMSIZE) && ctlen && (skip < siz));

	cur = skip & ~3;
	table_start = cur;
	for (; cur < siz; cur += 4) {
		uint32_t tv;

		//skip IVTs if applicable
		if ((siz - cur) > FCALLTABLE_IVTSKIP) {
			if (check_ivt(&buf[cur])) {
				cur += FCALLTABLE_IVTSKIP;
				table_start = cur + 4;
				consec = 0;
				good_prologs = 0;
				dupcount = 0;
				continue;
			}
		}

		tv = reconst_32(&buf[cur]);
		if (!consec) {
			//just started : save first val
			dupcheck = tv;
		} else {
			//check if duplicated
			if (dupcheck == tv) dupcount += 1;
			if (dupcount >= FCALLTABLE_MAXDUPS) {
				//reset
				table_start = cur + 4;
				consec = 0;
				good_prologs = 0;
				dupcount = 0;
				continue;
			}
		}

		if ((tv >= (uint32_t) siz) ||
			(tv & 1)) {
			//invalid / unaligned func ptr. Maybe end of valid table :
			if (	(consec >= FCALLTABLE_MINLENGTH) &&
				(good_prologs >= FCALLTABLE_PROLOGS)) goto goodexit;
			//else Reset.
			table_start = cur + 4;
			consec = 0;
			good_prologs = 0;
			dupcount = 0;
			continue;
		}
		//valid func ptr; check if it points to valid code (not rigorous)
		if (sh_isprologue(&buf[tv])) {
			good_prologs += 1;
		}

		consec += 1;
	}
	return -1;
goodexit:
	*ctlen = consec;
	return table_start;
}




/* for bt,bf sign-extended offsets : return PC+4+ (exts.b offset)<<1 */
u32 disarm_8bit_offset (u32 pos, u32 offs) {
	/* sign extend if higher bit is 1 (0x08) */
	if ((offs & 0x80) == 0x80)
		offs |= ~0xFF;
	return (offs<<1) + pos + 4;
}

/* for {bra,bsr} only: (sign-extend 12bit offset)<<1 + PC +4 */
u32 disarm_12bit_offset (u32 pos, u32 insoff) {
	u32 off = insoff;
	/* sign extend if higher bit is 1 (0x0800) */
	if ((off & 0x0800) == 0x0800)
		off |= ~0xFFF;
	return (pos) + (off<<1) + 4;
}

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


#define SH_TRACK_REG_MAXRECURSE 2000	//Hitting this limit is definitely abnormal and possibly indicates a bug
/* recursive reg tracker.
 * The visited[] cells are bitfielsd : when a certain location has been parsed
 * while tracking a certain reg, the corresponding bit (1 << regno) is set.
 * To fit inside a u16 value, gbr is aliased to r15 since r15 is normally only
 * used as a stack ptr. */
void sh_track_reg(const u8 *buf, u32 pos, u32 siz, unsigned regno, u16 *visited,
			void (*tracker_cb)(const uint8_t *buf, uint32_t pos, unsigned regno, void *data), void *cbdata) {

	static int recurselevel = 0;
	recurselevel += 1;

	assert(buf && siz && (siz <= MAX_ROMSIZE) && (pos < siz) &&
				(regno <= 0x0F) && visited && tracker_cb);

	if (recurselevel >= SH_TRACK_REG_MAXRECURSE) {
		printf("Warning : hit maximum recursion depth @ %lX!!\n", (unsigned long) pos);
		goto endrec;
	}

	for (; pos < siz; pos += 2) {
		unsigned aliased_regno = regno;
		if (aliased_regno > 15) aliased_regno = 15;

		if (visited[pos] & (1 << aliased_regno)) {
			//deja vu with this reg
			goto endrec;
		}
		visited[pos] |= (1 << aliased_regno);

		u16 opc = reconst_16(&buf[pos]);

		//end recursion if we hit RTS
		if (IS_RTS(opc) || IS_RTE(opc)) {
			//go check next opcode for delay slot
			tracker_cb(buf, pos + 2, regno, cbdata);
			goto endrec;
		}

		if (regno < 16) {
			//new recurse if match mov Rm, Rn
			if ((opc & 0xF0FF) == ((regno << 4) | 0x6003)) {
				//regno is copied to a new one.
				int newreg = (opc & 0xF00) >> 8;
				fprintf(dbg_stream, "Entering %4d.%6lX MOV\n", recurselevel, (unsigned long) pos + 2);
				sh_track_reg(buf, pos + 2, siz, newreg, visited, tracker_cb, cbdata);
			}

			//new recurse if we copy to gbr ( LDC Rm,GBR 0100mmmm00011110 )
			if (opc == (0x401E | (regno << 8))) {
				fprintf(dbg_stream, "Entering %4d.%6lX LDC GBR\n", recurselevel, (unsigned long) pos + 2);
				sh_track_reg(buf, pos + 2, siz, GBR, visited, tracker_cb, cbdata);
			}
		}

		if (regno == GBR) {
			//new recurse if we STC gbr, Rn
			if ((opc & 0xF0FF) == 0x0012) {
				int newreg = (opc >> 8) & 0xF;
				fprintf(dbg_stream, "Entering %4d.%6lX STC GBR\n", recurselevel, (unsigned long) pos + 2);
				sh_track_reg(buf, pos + 2, siz, newreg, visited, tracker_cb, cbdata);
			}
		}

		//new recurse if bt/bf. TODO : split case with a delay slot, since
		//there is a corner case where it copies/alters the reg before jumping
		if (IS_BT_OR_BF(opc)) {
			u32 newpos = disarm_8bit_offset(pos, GET_BTF_OFFSET(opc));
			fprintf(dbg_stream, "Branch %4d.%6lX BT/BF to %6lX\n", recurselevel, (unsigned long) pos, (unsigned long) newpos);
			sh_track_reg(buf, newpos, siz, regno, visited, tracker_cb, cbdata);
		}

		bool isbra = 0;
		u32 bra_newpos = pos + 2;
		//bra : don't recurse, just alter path
		if (IS_BRA(opc)) {
			bra_newpos = disarm_12bit_offset(pos, GET_BRA_OFFSET(opc));
			fprintf(dbg_stream, "Branch %4d.%6lX BRA to %6lX\n", recurselevel, (unsigned long) pos, (unsigned long) bra_newpos);
			isbra = 1;
		}

		//TODO : how to deal with jsr / bsr ?

		// almost done: check if we have a hit
		if (isbra) {
				//go check next opcode for delay slot
			tracker_cb(buf, pos + 2, regno, cbdata);
			pos = bra_newpos -2;	//alter path
			continue;
		}
		tracker_cb(buf, pos, regno, cbdata);

		//end recursion if reg is clobbered
		if (sh_getopcode_dest(opc) == regno) {
			goto endrec;
		}
	}	//for

endrec:
	recurselevel -= 1;
	return;
}
