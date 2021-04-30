// del_0refs.idc
// (c) fenugrec 2021
//
// experimental, WIP, backup your db before running !

// this is used to clean up stupid automatic references to "IVT0" every time an opcode does "mov 0, X" and IDA thinks 0 is a pointer.
// This makes "display xref chart to current identifier" pretty much useless, as the graph inevitably leads up to Poweron_reset ,
// and from there, every function that ever does a mov 0.
//
// this will mark all operands xreffing to 0, as a hex humber instead of an offset.

#include <idc.idc>
static main() {
	auto sauce, x;
	sauce = get_first_dref_to(0);
	while (sauce != BADADDR) {
		x = x + 1;
		op_hex(sauce, 0);	// this changes the list of xrefs, so we can keep on calling "get_first.." instead of get_next..
		Wait();
		sauce = get_first_dref_to(0);
	}
	print("%l garbage xrefs removed !\n", x);
}
