/* general information about Nissan ROMs
 * (c) fenugrec 2014-2015
 * GPLv3
 *
 */

#include <stdint.h>

//#define PACK __attribute__((aligned(1),packed))

/* LOADER versions */
/* 07 is not a "LOADER" but applies to old "sh705507" FIDs. */
enum loadvers_t {L_UNK=0, L07=07, L10=10, L40=40, L50=50, L60=60, L80=80};

/* struct LOADER -- this must be packed, i.e. no padding between members */
struct loader_t {
	uint8_t loader[17];	//LOADERxx, padded with 0
	uint8_t database[9];	//just "DATABASE", ASCIIz
	uint8_t field_1C;
	uint8_t field_1D;
	uint8_t YN;
	uint8_t pad2;
	uint8_t cpu[10];	//like "SH705822N", ASCIIz
	uint8_t field_28[1];	//0x0F
	uint8_t field_29[14];
	uint8_t field_39[7];
	uint8_t foot_FFFF[2];
} ;

#define FID_MAXSIZE		0x100	//just for bounds checking

/* basic firmware metadata struct; everything except LOADER80 ?*/
struct fid_base1_t {
	uint8_t FFtag[2];
	uint8_t FID[17];	//firmware ID
	uint8_t database[9];	//just "DATABASE", ASCIIz
	uint8_t field_1C;
	uint8_t field_1D;
	uint8_t YN;
	uint8_t pad2;
	uint8_t cpu[10];	//like "SH705822N", ASCIIz
	uint8_t field_2A[1];	//0x0F
	uint8_t field_2B[14];
	uint8_t field_39[9];
	uint8_t pNOP[4];		//&nullfunc
	uint8_t pF1[4];		//&f1()
	uint8_t pF2[4];		//&f2()
	uint8_t MSTCR_1[2];
	uint8_t MSTCR_2[2];
} ;

/* large firmware metadata struct. for LOADER80 */
struct fid_base2_t {
	uint8_t FFtag[2];
	uint8_t FID[17];	//firmware ID
	uint8_t database[9];	//just "DATABASE", ASCIIz
	uint8_t field_1C;
	uint8_t field_1D;
	uint8_t YN;
	uint8_t pad2;
	uint8_t cpu[10];	//like "SH705822N", ASCIIz
	uint8_t field_2A[1];	//0x0F
	uint8_t field_2B[14];
	uint8_t field_39[9];
	uint8_t pNOP[4];		//&nullfunc
	uint8_t pF1[4];		//&f1()
	uint8_t pF2[4];		//&f2()
	uint8_t MSTCR_1[2];
	uint8_t MSTCR_2[2];
	uint8_t wtf[4];
} ;



/***********
* different verions of "struct RAMF", always found after struct FID.
* Apparently every LOADERxx version has a slightly different format for this
*/

//version for loader-less ROMs, with FIDCPU=705507, checked on
//AM604
// Note : most members are probably invalid, except altcks start/end and pIVECT2
struct ramf_07 {
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t field_20[4];
	uint8_t field_24[4];
	uint8_t pRAMinit[4];	//array of data for ram initialization ? see 8U92A
	uint8_t pRAM_unk2[4][4];	//4x same, sometimes first member is different
	uint8_t altcks_start[4];
	uint8_t altcks_end[4];
	uint8_t pIVECT2[4];
};

//LOADER10, checked on
//CD002, 8U92A, AC011
struct ramf_10 {
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t field_20[4];
	uint8_t field_24[4];
	uint8_t pRAMinit[4];	//array of data for ram initialization ? see 8U92A
	uint8_t pRAM_unk2[4][4];	//4x same, sometimes first member is different
	uint8_t altcks_start[4];
	uint8_t altcks_end[4];
	uint8_t pIVECT2[4];
};

//LOADER40, checked on
//EC87A, EC82A, EC80A
struct ramf_40 {
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t field_20[4];
	uint8_t field_24[4];
	uint8_t field_28[4];
	uint8_t field_2C[4];
	uint8_t pRAMinit[4];	//array of data for ram initialization ?
	uint8_t pRAM_unk2[4][4];	//4x same, sometimes first member is different
	uint8_t altcks_start[4];
	uint8_t altcks_end[4];
	uint8_t pIVECT2[4];
};

//LOADER50, checked on
//6Z68A, AC401
struct ramf_50 {
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t field_20[4];
	uint8_t field_24[4];
	uint8_t field_28[4];
	uint8_t field_2C[4];
	uint8_t field_30[4];
	uint8_t field_34[4];
	uint8_t pRAMinit[4];	//array of data for ram initialization ?
	uint8_t pRAM_unk2[4][4];	//4x same, sometimes first member is different
	uint8_t altcks_start[4];
	uint8_t altcks_end[4];
	uint8_t pIVECT2[4];
};

//LOADER60, checked on
//ZD89A, CF43D
//LOADER50 and LOADER60 are identical so far.
struct ramf_60 {
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t field_20[4];
	uint8_t field_24[4];
	uint8_t field_28[4];
	uint8_t field_2C[4];
	uint8_t field_30[4];
	uint8_t field_34[4];
	uint8_t pRAMinit[4];	//array of data for ram initialization ?
	uint8_t pRAM_unk2[4][4];	//4x same, sometimes first member is different
	uint8_t altcks_start[4];
	uint8_t altcks_end[4];
	uint8_t pIVECT2[4];
};

//LOADER80, checked on
//1KA6A, 9HA7D
struct ramf_80 {
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t field_20[4];
	uint8_t field_24[4];
	uint8_t field_28[4];
	uint8_t field_2C[4];
	uint8_t field_30[4];
	uint8_t field_34[4];
	uint8_t field_38[4];
	uint8_t field_3C[4];
	uint8_t pRAMinit[4];	//array of data for ram initialization ?
	uint8_t pRAM_unk2[4][4];	//4x same, sometimes first member is different
	uint8_t altcks_start[4];
	uint8_t altcks_end[4];
	uint8_t pECUREC[4];
	uint8_t romend[4];		// == ROMSIZE - 1
	uint8_t pIVECT2[4];
};


/* hold data in a single format once the specific structure is parsed,
 * this is not found in any ROM but is useful for comparing metadata
 */
struct ramf_unified {
	uint32_t pRAMjump;
	uint32_t pRAM_DLAmax;
};

/**** "preload" info struct filled before calling RAMjump *****/
struct rj_preload {
	uint16_t flag0;	// ?
	uint16_t wdt_pin;	//  pin # mask for PxDR
	uint16_t s36k2_H;
	uint16_t s36k2_L;
	uint16_t wdt_portH;	//&PxDR>>16
	uint16_t wdt_portL;	//&PxDR & 0xFFFF
};
