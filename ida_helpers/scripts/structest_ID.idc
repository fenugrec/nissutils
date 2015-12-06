//
//
//      This file contains the user-defined type definitions.
//      To use it press F2 in IDA and enter the name of this file.
//
// metadata struct starting with FFFF tag, including firmare UID and "DATABASE" string.

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

	id = AddStrucEx(-1,"ID1",0);
	
	id = GetStrucIdByName("ID1");
	AddStrucMember(id,"FFtag",	0X0,	0x10000400,	-1,	2);
	AddStrucMember(id,"UID",	0X2,	0x50000400,	0x0,	17);
	AddStrucMember(id,"DATABASE_str",	0X13,	0x50000400,	0x0,	9);
	AddStrucMember(id,"field_1C",	0X1C,	0x000400,	-1,	2);
	AddStrucMember(id,"YN",	0X1E,	0x300400,	-1,	1);
	AddStrucMember(id,"pad2",	0X1F,	0x000400,	-1,	1);
	AddStrucMember(id,"CPU",	0X20,	0x50000400,	0x0,	10);
	return id;
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
	id = Structures_0(id);
}

// End of file.
