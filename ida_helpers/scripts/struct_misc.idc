//      This file contains the user-defined type definitions.
//      To use it press F2 in IDA and enter the name of this file.
//

#define UNLOADED_FILE   1
#include <idc.idc>

static main(void) {
        Structures();           // structure types
}


static Structures_0(id) {

	id = AddStrucEx(-1,"ADC_descr1",0);
	id = AddStrucEx(-1,"ADC_vals",0);
	id = AddStrucEx(-1,"CID_descr1",0);
	id = AddStrucEx(-1,"DTCstatus",0);
	id = AddStrucEx(-1,"DTCdescr",0);
	
	id = GetStrucIdByName("ADC_vals");
	AddStrucMember(id,"field_0",	0X0,	0x10000400,	-1,	64);
	
	id = GetStrucIdByName("ADC_descr1");
	AddStrucMember(id,"pCR",	0X0,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pCSR",	0X4,	0x20500400,	0X0,	4);
	AddStrucMember(id,"mask?",	0X8,	0x20000400,	-1,	4);
	AddStrucMember(id,"pADCval",	0XC,	0x20500400,	0X0,	4);
	
	id = GetStrucIdByName("CID_descr1");
	AddStrucMember(id,"pSupmask",	0X0,	0x20500400,	0X0,	4);
	AddStrucMember(id,"pCID",	0X4,	0x20500400,	0X0,	124);
	
	id = GetStrucIdByName("DTCstatus");
	AddStrucMember(id,"field_0",	0X0,	0x000400,	-1,	1);
	SetMemberComment(id,	0X0,	"array @ ramB23E",	1);
	AddStrucMember(id,"field_1",	0X1,	0x000400,	-1,	1);
	AddStrucMember(id,"flags_2",	0X2,	0x000400,	-1,	1);
	SetMemberComment(id,	0X2,	"0x40 if DTC set + reportable?\n0x20 if ?",	0);
	
	id = GetStrucIdByName("DTCdescr");
	AddStrucMember(id,"field_0",	0X0,	0x20000400,	-1,	4);
	AddStrucMember(id,"DTCno",	0X4,	0x20000400,	-1,	4);
	AddStrucMember(id,"field_8",	0X8,	0x000400,	-1,	1);
	AddStrucMember(id,"field_9",	0X9,	0x000400,	-1,	1);
	AddStrucMember(id,"field_A",	0XA,	0x000400,	-1,	1);
	AddStrucMember(id,"field_B",	0XB,	0x000400,	-1,	1);
	return id;
}

//------------------------------------------------------------------------
// Information about structure types

static Structures(void) {
        auto id;
	id = Structures_0(id);
}

// End of file.
