// struct preload
// filled in SID34_prep just before jumping in BL kernel ?

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

	id = AddStrucEx(-1,"preload",0);

	id = GetStrucIdByName("preload");
	AddStrucMember(id,"flag0",	0X0,	0x10000400,	-1,	2);
	AddStrucMember(id,"wdt_pin",	0X2,	0x10000400,	-1,	2);
	SetMemberComment(id,	0X2,	"PL5 mask for PLDR",	1);
	AddStrucMember(id,"sid36k2_H",	0X4,	0x10000400,	-1,	2);
	AddStrucMember(id,"sid36k2_L",	0X6,	0x10000400,	-1,	2);
	AddStrucMember(id,"wdt_portH",	0X8,	0x10000400,	-1,	2);
	SetMemberComment(id,	0X8,	"&PLDR>>16",	1);
	AddStrucMember(id,"wdt_portL",	0XA,	0x10000400,	-1,	2);
	SetMemberComment(id,	0XA,	"&PLDR & FFFF",	1);
	return id;
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
	id = Structures_0(id);
}

// End of file.
