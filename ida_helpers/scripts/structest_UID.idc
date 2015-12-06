//
//
//      This file contains the user-defined type definitions.
//      To use it press F2 in IDA and enter the name of this file.
//
//struct UID1 : ressemble bcp a ID1, moins le dw 0xFFFF au debut. Les strucs LOADERxx ont jamais le FFFF je crois.

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

	id = AddStrucEx(-1,"UID1",0);
	
	id = GetStrucIdByName("UID1");
	AddStrucMember(id,"UID",	0X0,	0x50000400,	-1,	17);
	AddStrucMember(id,"DATABASE_str",	0X11,	0x50000400,	0x0,	9);
	AddStrucMember(id,"field_1C",	0X1A,	0x000400,	-1,	1);
	AddStrucMember(id,"field_1D",	0X1B,	0x000400,	-1,	1);
	AddStrucMember(id,"YN",	0X1C,	0x300400,	-1,	1);
	AddStrucMember(id,"pad2",	0X1D,	0x000400,	-1,	1);
	AddStrucMember(id,"CPU",	0X1E,	0x50000400,	0x0,	8);
	AddStrucMember(id,"field_28",	0X26,	0x300400,	-1,	1);
	AddStrucMember(id,"field_29",	0X27,	0x000400,	-1,	16);
	AddStrucMember(id,"field_39",	0X37,	0x000400,	-1,	9);
	return id;
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
	id = Structures_0(id);
}

// End of file.
