/* general information about Nissan ROMs
 * (c) fenugrec 2014-2015
 * GPLv3
 *
 * TODO : merge in nislib.h ?
 *
 */

#include <stdint.h>

//#define PACK __attribute__((aligned(1),packed))

/* LOADER versions
 * 07 is not a "LOADER" but applies to old "sh705507" FIDs ;
 * L81 is for an alternate (more recent?) variant of LOADER80.
 * Actually the correlation between loader version and type of FID struct
 * is tenuous at best.  Maybe the FID IC string ("705519" etc)
 * would be more reliable, but LOADER80 ROMs don't follow a clear pattern.
 */
enum loadvers_t {L_UNK=-1, L10=10, L40=40, L50=50, L60=60, L80=80, L81=81, L00=0};

/* struct LOADER -- this must be packed, i.e. no padding between members */
struct loader_t {
	uint8_t loader[17];	//LOADERxx, padded with 0
	uint8_t database[9];	//just "DATABASE", ASCIIz
	uint8_t field_1C;
	uint8_t field_1D;
	uint8_t YN;
	uint8_t pad2;
	uint8_t cpu[10];	//like "SH705822N" or "S725332N"; ASCIIz
	uint8_t field_28[1];	//0x0F
	uint8_t field_29[14];
	uint8_t field_39[7];
	uint8_t foot_FFFF[2];
} ;

#define FID_MAXSIZE		0x100	//just for bounds checking

/* basic firmware metadata struct; everything except LOADER80 ?*/
/* Also some weird 705507 ROMs lack the MSTCR_* fields... */
struct fid_base1_t {
	uint8_t FID[17];	//firmware ID
	uint8_t database[9];	//just "DATABASE", ASCIIz
	uint8_t field_1C;
	uint8_t field_1D;
	uint8_t YN;
	uint8_t pad2;
	uint8_t cpu[10];	//like "SH705822N" or "S725332N"; ASCIIz
	uint8_t field_2A[1];	//0x0F
	uint8_t field_2B[14];
	uint8_t field_39[9];
	uint8_t pNOP[4];		//&nullfunc
	uint8_t pF1[4];		//&f1()
	uint8_t pF2[4];		//&f2()
	uint8_t MSTCR_1[2];
	uint8_t MSTCR_2[2];
} ;

/* large firmware metadata struct. for certain LOADER80 */
struct fid_base2_t {
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
	uint8_t wtf[4];		//not in EM62B !
} ;



/***********
* different verions of "struct RAMF", always found after struct FID.
* Apparently every LOADERxx version has a slightly different format for this
*/

//version for loader-less ROMs, with FIDCPU=705507, checked on
//AM604
// Note : most members are probably invalid, except altcks start/end
struct ramf_705507 {
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
	uint8_t field_20[4];
	uint8_t field_24[4];
	uint8_t pRAMinit[4];	//array of data for ram initialization ? see 8U92A
	uint8_t pRAM_unk2[4][4];	//4x same, sometimes first member is different
	uint8_t altcks_start[4];
	uint8_t altcks_end[4];
};

//FID IC 705513  + LOADER10, checked on
//CD002, 8U92A, AC011
struct ramf_705513 {
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
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
struct ramf_705520 {
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
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
struct ramf_705821 {
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
struct ramf_705823 {
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
// BUT invalid on EM62B and others... wtf
struct ramf_705828 {
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

//LOADER80 for EM62B and other oddballs... wtf
struct ramf_705519 {
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t field_18[4];
	uint8_t field_1C[4];
	uint8_t field_20[4];
	uint8_t field_24[4];
	uint8_t field_28[4];
	uint8_t field_2C[4];
	uint8_t pRAMinit[4];	//array of data for ram initialization ?
	uint8_t pRAM_unk2[4][4];	//4x same, sometimes first member is different
	uint8_t altcks_start[4];
	uint8_t altcks_end[4];
	uint8_t pECUREC[4];
	uint8_t romend[4];		// == ROMSIZE - 1
	uint8_t pIVECT2[4];
};



/******** new technique for analyzing the RAMF struct
 * every FID type (705507 etc) fills a struct fidtype_t, values are offsets inside the struct ramf of the ROM.
 * Some FID types don't define all these fields; a value of 0 (like fidtype.pIVT2 = 0) means the value is undefined.
 *
 * the "enum fidtype_ic" will be used to index in an array of all known fid types.
 */
enum fidtype_ic {FID705101,
		FID705507,
		FID705513,
		FID705519,
		FID705520,
		FID705821,
		FID705822,
		FID705823,
		FID705828,
		FID7253331,
		FID7253332,
		FID_UNK
};

struct fidtype_t {
	enum fidtype_ic fti;
	uint8_t FIDIC[8];	//such as "SH705507"
	int	pRAMF_maxdist;	//for some ROMs where the RAMF struct is super far from the FID
	uint32_t	RAMF_header;	//first member to identify RAMF struct
	int	pRAMjump;
	int	pRAM_DLAmax;	//end of RAM dl area ? ex ffff8438...DLAmax
	int	pRAMinit;	//array of data for ram initialization ? see 8U92A
	int	packs_start;
	int	packs_end;	//alt cks bounds
	int	pIVT2;		//secondary vector table
	int	pROMend;	// == ROMSIZE - 1
	int	pECUREC;
};

extern const struct fidtype_t fidtypes[];


/* hold data in a single format once the specific structure is parsed,
 * this is not found in any ROM but is useful for comparing metadata
 */
struct ramf_unified {
	uint32_t pRAMjump;
	uint32_t pRAM_DLAmax;
};

/**** "preload" info struct filled before calling RAMjump *****/
/** TODO : check against a few different FID types !
 * i.e. VD70A (7055 + 7051) seems to have extra fields at the end
 */
struct rj_preload {
	uint16_t flag0;	// ?
	uint16_t wdt_pin;	//  pin # mask for PxDR
	uint16_t s36k2_H;
	uint16_t s36k2_L;
	uint16_t wdt_portH;	//&PxDR>>16
	uint16_t wdt_portL;	//&PxDR & 0xFFFF
};
