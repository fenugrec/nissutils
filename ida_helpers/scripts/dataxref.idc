//Manually create a data xref from the current line to a user-specified address
// (typically a RAM location that IDA didn't recognize, and that getmemaccess couldnm't figure out)
// (c) fenugrec 2016

#include <idc.idc>
static main() {

	auto cur, ramaddr, sprompt;
	cur = ScreenEA();
	sprompt = form("Create data xref from here (%a) to :", cur);
	ramaddr = AskAddr(0, sprompt);
	//Message("xref to %a\n", ramaddr);
	add_dref(cur, ramaddr, dr_I | XREF_USER);	//type "informational"
	//DnextB(0x391d2,0x390ec));
}
