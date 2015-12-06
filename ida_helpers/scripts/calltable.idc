// calltable.idc
// (c) fenugrec 2014
// posted on www.romraider.com forums somewhere

// this will parse through a calltable, starting at current cursor, marking each entry as code
// and defining a function at each location.
// it starts at the current cursor location and parses N consecutive calls.

// typical use:
// some code somewhere looks like this :
//	r2=&calltable_start;
//	for (i=0; i<=N; i++) { call @r2; r2+=4;}
// and you have
//calltable_start:
//	.data.l unk_1234
//	.data.l unk_4567
//	... (N lines of offsets or garbage, a real pain to parse manually)
//
// just set the cursor at the ".data.l unk_1234" line and run this script. BOOM !
// now it should look like:
//calltable_start:
//	.data.l sub_1234
//	.data.l sub_4567
//	...


#include <idc.idc>
static main() {
	auto x,prevea,curea;
		
	auto nbelems;
	nbelems=AskLong(0,"nb de calls");
	
	if (nbelems<=0) {
		Warning("invalide");
		return;
	}
	for (x=1; x<=nbelems; x=x+1) {
		prevea=ScreenEA();
		MakeUnknown(prevea,4,DOUNK_SIMPLE);		//current item may not already be an offset
		OpOff(prevea,0,0);		//make offset
		Jump(Dword(prevea));		//jump (follow) current call element
		curea=ScreenEA();
		MakeUnkn(curea, DOUNK_EXPAND);		//un-define first
		if (!MakeCode(curea)) {
			Warning("MakeCode failed!");		//fataaal
			return;
		}
		if (!MakeFunction(curea,-1)){	//param de -1 => trouver fin auto
			Message("MakeFunction failed @ %08x\n",curea);
			//not a critical error usually so no reason to stop here.
			//usually a failure indicates the analyzer "ran into" some already-defined junk (like two-character strings, etc) while marking bytes as Code.
			//They'll have to be parsed manually afterwards; I haven't found a way to safely automate this.
		}
		Wait();	//let auto-analysis finish before continuing
		Jump(prevea+4);		//could probably wrap this up in a single "Jump(Dword(intial_addr + (i*4))); " but why bother
	}
}
