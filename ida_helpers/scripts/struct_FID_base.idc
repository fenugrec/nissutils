//
//      This file contains the user-defined type definitions.
//      To use it press F2 in IDA and enter the name of this file.
//
// More probable version of "struct FID", that stops after MSTCR/SYSCR.
// the second half of the orig ID3 struct is moved to "struct RAMF"

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

	id = AddStrucEx(-1,"FID_base",0);

	id = GetStrucIdByName("FID_base");
	AddStrucMember(id,"FID",	0X0,	0x50000400,	0x0,	17);
	AddStrucMember(id,"DATABASE_str",	0X11,	0x50000400,	0x0,	9);
	AddStrucMember(id,"field_1C",	0X1A,	0x000400,	-1,	1);
	AddStrucMember(id,"field_1D",	0X1B,	0x000400,	-1,	1);
	AddStrucMember(id,"YN",	0X1C,	0x300400,	-1,	1);
	AddStrucMember(id,"pad2",	0X1D,	0x000400,	-1,	1);
	AddStrucMember(id,"CPU",	0X1E,	0x50000400,	0x0,	10);
	AddStrucMember(id,"field_2A",	0X28,	0x000400,	-1,	1);
	AddStrucMember(id,"field_2B",	0X29,	0x000400,	-1,	14);
	AddStrucMember(id,"field_39",	0X37,	0x000400,	-1,	9);
	AddStrucMember(id,"pNOP",	0X40,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0X40,	"&nullfunc",	1);
	AddStrucMember(id,"pF1",	0X44,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0X44,	"&f1()",	1);
	AddStrucMember(id,"pF2",	0X48,	0x20500400,	0X0,	4);
	SetMemberComment(id,	0X48,	"&f2()",	1);
	AddStrucMember(id,"MSTCR_1",	0X4C,	0x10000400,	-1,	2);
	AddStrucMember(id,"MSTCR_2",	0X4E,	0x10000400,	-1,	2);
	return id;
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
	id = Structures_0(id);
}

// End of file.
