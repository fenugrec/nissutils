//
//
//      This file contains the user-defined type definitions.
//      To use it press F2 in IDA and enter the name of this file.
//
// Metadata struct that starts with the "LOADER" string.

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

	id = AddStrucEx(-1,"struc_loader",0);
	
	id = GetStrucIdByName("struc_loader");
	AddStrucMember(id,"LOADER_str",	0X0,	0x50000400,	0xffffffff,	17);
	AddStrucMember(id,"DATABASE_str",	0X11,	0x50000400,	0x0,	9);
	AddStrucMember(id,"field_1C",	0X1A,	0x000400,	-1,	1);
	AddStrucMember(id,"field_1D",	0X1B,	0x000400,	-1,	1);
	AddStrucMember(id,"YN",	0X1C,	0x300400,	-1,	1);
	AddStrucMember(id,"pad2",	0X1D,	0x000400,	-1,	1);
	AddStrucMember(id,"CPU",	0X1E,	0x50000400,	0x0,	9);
	AddStrucMember(id,"field_27",	0X27,	0x10000400,	-1,	2);
	AddStrucMember(id,"field_29",	0X29,	0x000400,	-1,	14);
	AddStrucMember(id,"field_39",	0X37,	0x000400,	-1,	7);
	AddStrucMember(id,"foot_FFFF",	0X3E,	0x10000400,	-1,	2);
	return id;
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
	id = Structures_0(id);
}

// End of file.
