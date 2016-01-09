/* general information about Nissan ROMs
 * (c) fenugrec 2014-2015
 * GPLv3
 *
 */

#include <stdint.h>

//#define PACK __attribute__((aligned(1),packed))

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


/* large firmware metadata struct. for some 705822, 705823, */
struct fid_t {
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
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t field_72[4];
	uint8_t field_76[4];
	uint8_t field_7A[4];
	uint8_t field_7E[4];
	uint8_t field_82[4];
	uint8_t field_86[4];
	uint8_t pRAMinit[4];	//?
	uint8_t pRAM_unk2[4][4];
	uint8_t pISR_IMI3A[4];
	uint8_t pTHIS[4];
	uint8_t pIVECT2[4];
} ;

/* large firmware metadata struct; short version (when cpu=705513, 705520, ) */
struct fidshort_t {
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
	uint8_t pRAM1[4];		//rxbuf?
	uint8_t pRAMexec2[4];	//RAMexec?
	uint8_t pRAM_unk1[4];
	uint8_t pRAM_unk1b[4];		//unk1....unk1b = zone
	uint8_t pRAM_28a4_1[4];
	uint8_t pRAM_28a4_2[4];		//another zone
	uint8_t pRAMjump[4];
	uint8_t pRAM_DLAmax[4];	//end of RAM dl area ? ex ffff8438...DLAmax
	uint8_t field_72[4];
	uint8_t field_76[4];
	uint8_t pRAMinit[4];	//?
	uint8_t pRAM_unk2[4][4];
	uint8_t pISR_IMI3A[4];
	uint8_t pTHIS[4];
	uint8_t pIVECT2[4];
} ;
