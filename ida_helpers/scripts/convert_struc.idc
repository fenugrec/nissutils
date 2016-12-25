// Undefine the currently-selected struct, and automatically
// name each member based on a given struct.
//
// Sucks, but necessary because xrefs don't work well with structs
//
// copyright (c) fenugrec 2016
//
// IDA 5 doesn't seem to provide a way to get struct ID of current selection ? wtf


#include <idc.idc>

static conv(ea, sid, root) {
	auto mname, mflags, msize, last, cur, skip;

	MakeUnkn(ea, DOUNK_SIMPLE);

	cur = GetFirstMember(sid);
	last = GetLastMember(sid);
	if ((cur == -1) || (last == -1)) {
		Message("Bad members?\n");
		return;
	}

	while (cur <= last) {
		skip = 0;
		mname = GetMemberName(sid, cur);
		mflags = GetMemberFlag(sid, cur);
		msize = GetMemberSize(sid, cur);
		if ((mflags == -1) || (msize == -1)) {
			Message("offs 0x%X: undefined, skipping\n", cur);
			cur = cur + 1;
			continue;
		}
		if (!isData(mflags) || isStruct(mflags)) {
			Message("offs 0x%X: unsupported member type, skipping\n", cur);
			skip = 1;
		}
		
		if (!skip) {
			auto newname;
			newname = form("%s_%s", root, mname);
			Message("offs 0x%X: %s, flags 0x%08X\n", cur, newname, mflags);
			
			//) MakeData to take define byte, word, string, etc. members.
			MakeData(ea + cur, mflags & DT_TYPE, msize, -1);
			
			//) Name members
			if (cur == 0) {
				//Offs 0 is special
				MakeNameEx(ea + cur, newname, SN_CHECK | SN_NOWARN);
			} else {
				MakeNameEx(ea + cur, newname, SN_CHECK | SN_NOLIST | SN_NOWARN);
			}

			//) mark special members as char or offset. Other types possible, not implemented
			if (isOff0(mflags)) {
				OpOff(ea + cur, 0, 0);
			}
			if (isChar0(mflags)) {
				OpChr(ea + cur, 0);
			}
		}

		cur = cur + msize;
	}
	return;
}

static main() {
	auto ea, sid, sidx, num_mem, sprompt, rootname;
	
	ea = ScreenEA();

	if (!isStruct(GetFlags(ea))) {
		Warning("Current selection not a struct!\n");
	}

	sprompt = form("Converting \"%s\" to individual members. Enter struct idx:", GetTrueName(ea));
	sidx = AskLong(-1, sprompt);

	if ((sidx < 0) || (sidx >= GetStrucQty())) {
		Message("Bad struct index\n");
		return;
	}

	sid = GetStrucId(sidx);
	if (sid == -1) {
		Message("bad struc ID\n");
		return;
	}

	sprompt = form("Create with sid ID 0x%X, struc type \"%s\"?\n", sid, GetStrucName(sid));

	if (AskYN(-1, sprompt) != 1) {
		Message("Aborting.\n");
		return;
	}

	rootname = AskStr(GetStrucName(sid), "prefix member names with :");
	conv(ea, sid, rootname);
	
	return;
}
