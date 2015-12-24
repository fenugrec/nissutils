//
//      This file contains the user-defined type definitions.
//      To use it press F2 in IDA and enter the name of this file.
//
// Third expansion of the FID metadata struct (DATABASE string)

#define UNLOADED_FILE   1
#include <idc.idc>

static main(void) {
        Enums();                // enumerations
        Structures();           // structure types
	LowVoids(0x20);
	HighVoids(0xFFFF6001);
}

//------------------------------------------------------------------------
// Information about enum types

static Enums(void) {
        auto id;
}

static Structures_0(id) {

	id = AddStrucEx(-1,"ID3",0);
	
	id = GetStrucIdByName("ID3");
	AddStrucMember(id,"FFtag",	0X0,	0x10000400,	-1,	2);
	AddStrucMember(id,"UID",	0X2,	0x50000400,	0x0,	17);
	AddStrucMember(id,"DATABASE_str",	0X13,	0x50000400,	0x0,	9);
	AddStrucMember(id,"field_1C",	0X1C,	0x000400,	-1,	1);
	AddStrucMember(id,"field_1D",	0X1D,	0x000400,	-1,	1);
	AddStrucMember(id,"YN",	0X1E,	0x300400,	-1,	1);
	AddStrucMember(id,"pad2",	0X1F,	0x000400,	-1,	1);
	AddStrucMember(id,"CPU",	0X20,	0x50000400,	0x0,	8);
	AddStrucMember(id,"field_28",	0X28,	0x300400,	-1,	1);
	AddStrucMember(id,"field_29",	0X29,	0x000400,	-1,	16);
	AddStrucMember(id,"field_39",	0X39,	0x000400,	-1,	9);
	AddStrucMember(id,"pNOP",	0X42,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0X42,	"&nullfunc",	1);
	AddStrucMember(id,"pF1",	0X46,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0X46,	"&f1()",	1);
	AddStrucMember(id,"pF2",	0X4A,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0X4A,	"&f2()",	1);
	AddStrucMember(id,"MSTCR_1",	0X4E,	0x10000400,	-1,	2);
	AddStrucMember(id,"MSTCR_2",	0X50,	0x10000400,	-1,	2);
	AddStrucMember(id,"pRAM1?",	0X52,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0X52,	"rxbuf?",	1);
	AddStrucMember(id,"pRAMexec2?",	0X56,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0X56,	"RAMexec?",	1);
	AddStrucMember(id,"pRAM_unk1",	0X5A,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_unk1b",	0X5E,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0X5E,	"unk1...unk1b = zone",	0);
	AddStrucMember(id,"pRAM_28a4_1",	0X62,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_28a4_2",	0X66,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0X66,	"delimit zone",	0);
	AddStrucMember(id,"pRAMjump?",	0X6A,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_DLAmax",	0X6E,	0x20500400,	0X0,	4);
	SetMemberComment(id, 0x6E,	"end of RAM download area? ex ffff8438...DLAmax",	0);
	AddStrucMember(id,"field_72",	0X72,	0x20500400,	0X0,	4);
	AddStrucMember(id,"field_76",	0X76,	0x20500400,	0X0,	4);
	AddStrucMember(id,"field_7A",	0X7A,	0x20500400,	0X0,	4);
	AddStrucMember(id,"field_7E",	0X7E,	0x20500400,	0X0,	4);
	AddStrucMember(id,"field_82",	0X82,	0x20500400,	0X0,	4);
	AddStrucMember(id,"field_86",	0X86,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAMinit?",	0X8A,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_unk2",	0X8E,	0x20500400,	0X0,	16);
	AddStrucMember(id,"pISR_IMI3A",	0X9E,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pTHIS",	0XA2,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pIVECT2",	0XA6,	0x20500400,	0X0,	4);
	
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
	id = Structures_0(id);
}

// End of file.
