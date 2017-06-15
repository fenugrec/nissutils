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



/******** new technique for analyzing the RAMF struct
 * every FID type (705507 etc) fills a struct fidtype_t, values are offsets inside the struct ramf of the ROM.
 * Some FID types don't define all these fields; a value of 0 (like fidtype.pIVT2 = 0) means the value is undefined.
 *
 * the "enum fidtype_ic" will be used to index in an array of all known fid types.
 */
enum fidtype_ic {
		FID705101,
		FID705415,
		FID705507,
		FID705513,
		FID705519,
		FID705520,
		FID705821,
		FID705822,
		FID705823,
		FID705828,
		FID705927,
		FID7253331,
		FID7253332,
		FID_UNK
};

struct fidtype_t {
	enum fidtype_ic fti;
	uint8_t FIDIC[8];	//such as "SH705507"
	uint32_t ROMsize;	//in units of 1024B
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
