//
//      This file contains the user-defined type definitions.
//      To use it press F2 in IDA and enter the name of this file.
//
// second part of the bigger previous "struct FID" definition (ID3).
// holds stuff for checksum, reflash, etc

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

	id = AddStrucEx(-1,"RAMF",0);

	id = GetStrucIdByName("RAMF");
	AddStrucMember(id,"pRAM1?",	0x00,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAMexec2?",	0x04,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_unk1",	0x08,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_unk1b",	0x0c,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0x08,	"unk1...unk1b = zone",	0);
	AddStrucMember(id,"pRAM_28a4_1",	0x10,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_28a4_2",	0x14,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0x14,	"delimit zone",	0);
	AddStrucMember(id,"pRAMjump?",	0x18,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_DLAmax",	0x1c,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0x1c,	"end of RAM download area? ex ffff8438...DLAmax",	0);
	AddStrucMember(id,"field_20",	0x20,	0x20500400,	0X0,	8);
	//AddStrucMember(id,"field_24",	0x24,	0x20500400,	0X0,	4);
	AddStrucMember(id,"field_28",	0x28,	0x20500400,	0X0,	4);
	AddStrucMember(id,"field_2c",	0x2c,	0x20500400,	0X0,	4);
	AddStrucMember(id,"field_30",	0x30,	0x20500400,	0X0,	4);
	AddStrucMember(id,"field_34",	0x34,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAMinit?",	0X34,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_unk2",	0x38,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_unk3",	0X3c,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_unk4",	0X40,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_unk5",	0X44,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pRAM_unk6",	0X48,	0x20500400,	0X0,	4);
	AddStrucMember(id,"altcks_start",	0x4c,	0x20500400,	0X0,	4);
	AddStrucMember(id,"altcks_end",	0x50,	0x20500400,	0X0,	4);
//	AddStrucMember(id,"pECUID?",	0x54,	0x20500400,	0X0,	4);
//	AddStrucMember(id,"pad_B2",	0x4c,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pIVECT2",	0x54,	0x20500400,	0X0,	4);
	return id;
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
	id = Structures_0(id);
}

// End of file.
