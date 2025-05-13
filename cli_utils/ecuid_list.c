/* Functionality for matching ECUIDs to most likely keyset.
 *
 * Copyright (c) fenugrec 2016
 * Licensed under GPLv3
 */


#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>	//for sortage

#include "ecuid_list.h"
#include "stypes.h"


struct ecuid_klist_t {
	const char *ecuid;
	uint32_t s27k;
};

/* export from master list : */

const struct ecuid_klist_t ecuid_list[] = {
	{"1A10A", 0x9CC487FA},
	{"1A30D", 0x917B43A8},
	{"1EA1A", 0x917B43A8},
	{"1EA3A", 0x917B43A8},
	{"1FC6A", 0xC6E19CF0},
	{"1KA6A", 0xE5D097FC},
	{"1KE9C", 0xE5D097FC},
	{"1KN0B", 0x412CF359},
	{"1MG3.", 0x0EF7BF25},
	{"1MX6D", 0x9E8950B5},
	{"1NA0A", 0x8FFD3C82},
	{"1NA8C", 0x8FFD3C82},
	{"1NH3A", 0xC93775BB},
	{"1TV1B", 0x412CF359},
	{"1YZ5A", 0x1C07CD33},
	{"2Y967", 0xE21D9C79},
	{"3UF0.", 0xC6E19CF0},
	{"3JV9B", 0xD2BD85E9},
	{"4EF2A", 0x6D581F84},
	{"4M860", 0x0371AEF4},
	{"4ME6B", 0xE5D097FC},
	{"5M316", 0xD0BB83E7},
	{"5S575", 0x917C44A8},
	{"5WH7B", 0x6D571F84},
	{"5Y006", 0x88733BA0},
	{"5Y7..", 0x5414CDA6},
	{"6GE2C", 0x1C07CD33},
	{"6W5..", 0x0DF7BF25},
	{"6Y3..", 0x5414CDA6},
	{"6Z68A", 0x93B645A1},
	{"7S...", 0xAD12D93F},
	{"7Y001", 0x7B472BD1},
	{"7Y210", 0xEED9A107},
	{"8J160", 0x5414CDA6},
	{"8N878", 0x9369D7EB},
	{"8N881", 0x9369D7EB},
	{"8U0..", 0xE091912E},
	{"8U320", 0x7C2300FA},
	{"8U42D", 0xCD7BB660},
	{"8U51B", 0xE091912E},
	{"8U523", 0xE091912E},
	{"8U90.", 0x9851EB85},
	{"8U92A", 0x9851EB85},
	{"8W81A", 0xC6E19CF0},
	{"8Y20.", 0xC6E19CF0},
	{"8Y22.", 0xC6E19CF0},
	{"8Y50.", 0xC6E19CF0},
	{"8Y51B", 0xC6E19CF0},
	{"8Y52B", 0xC6E19CF0},
	{"8Y106", 0x7B472BD1},
	{"8Y72A", 0x422DF45A},
	{"9HA7.", 0xE5D097FC},
	{"9HP7B", 0x816C3398},
	{"9J00.", 0xE091912E},
	{"9J074", 0x5414CDA6},
	{"9J081", 0x5414CDA6},
	{"9J411", 0x3C24EB50},
	{"9J416", 0x3C24EB50},
	{"9U03.", 0xC6E19CF0},
	{"9U05A", 0xC6E19CF0},
	{"9U10A", 0xC6E19CF0},
	{"9U12A", 0xC6E19CF0},
	{"9U13A", 0xC6E19CF0},
	{"9W73A", 0x98EBB319},
	{"9W73B", 0xC7B27ADF},
	{"9W85A", 0xB5A068CD},
	{"9Y412", 0xED19DF45},
	{"AC010", 0x705A2287},
	{"AC011", 0x705A2287},
	{"AC200", 0x705A2287},
	{"AC3..", 0xEED9A107},
	{"AC4..", 0xEED9A107},
	{"AC700", 0xEED9A107},
	{"AC710", 0xEC5B98DE},
	{"AC800", 0xEED9A107},
	{"AC810", 0xEC5B98DE},
	{"AC815", 0xEED9A107},
	{"AG920", 0x6BD9175D},
	{"AJ401", 0x6BD9175D},
	{"AJ411", 0x6BD9175D},
	{"AL500", 0x3E29F056},
	{"AM603", 0x5414CDA6},
	{"AM604", 0x5414CDA6},
	{"AM607", 0x705A2287},
	{"AM702", 0x705A2287},
	{"AM703", 0x705A2287},
	{"AM90.", 0xED19DF45},
	{"AMKN1", 0x3722E94F},
	{"AQ001", 0x3E29F056},
	{"AQ806", 0x75B4C26D},
	{"AQ860", 0x75B4C26D},
	{"AS700", 0x99C740B0},
	{"AU40B", 0xBE8298AC},
	{"AV722", 0xBAA56CD1},
	{"AY301", 0xFB518698},
	{"BH32.", 0xC6E19CF0},
	{"BH33.", 0xC6E19CF0},
	{"BH34.", 0xC6E19CF0},
	{"BH4.C", 0xC6E19CF0},
	{"BH50C", 0xC6E19CF0},
	{"BH51.", 0xC6E19CF0},
	{"BN915", 0xBAA56CD1},
	{"BT47A", 0xC6E19CF0},
	{"BT67A", 0xC6E19CF0},
	{"CC0..", 0x624D157A},
	{"CD0..", 0x705A2287},
	{"CD1..", 0x705A2287},
	{"CD4..", 0xED19DF45},
	{"CD700", 0x7B472BD1},
	{"CD800", 0x7B472BD1},
	{"CE400", 0x705A2287},
	{"CE405", 0x705A2287},
	{"CE81.", 0xEED9A107},
	{"CE821", 0xEED9A107},
	{"CE860", 0x7B472BD1},
	{"CE865", 0x7B472BD1},
	{"CE8..", 0xEED9A107},
	{"CF0..", 0xEED9A107},
	{"CF170", 0x7B472BD1},
	{"CF180", 0x7B472BD1},
	{"CF1..", 0xEED9A107},
	{"CF205", 0xEC5B98DE},
	{"CF210", 0xEC5B98DE},
	{"CF2..", 0xEC5B98DE},
	{"CF40C", 0x634D157A},
	{"CF40D", 0x3722E94F},
	{"CF41B", 0x634D157A},
	{"CF41E", 0x634D157A},
	{"CF42.", 0x3722E94F},
	{"CF43D", 0x634D157A},
	{"CF44A", 0x634D157A},
	{"CF44D", 0x3722E94F},
	{"CF48D", 0x3722E94F},
	{"CF90A", 0x422DF45A},
	{"CF91A", 0x422DF45A},
	{"CG060", 0x705A2287},
	{"CG767", 0x0E7D44A9},
	{"CL1..", 0xEED9A107},
	{"CL70A", 0x3722E94F},
	{"CL81A", 0x3B26EC52},
	{"CM30B", 0x3722E94F},
	{"CM31C", 0x634D157A},
	{"CM32.", 0x3722E94F},
	{"CM37A", 0x3722E94F},
	{"CM41C", 0x634D157A},
	{"CM4..", 0x3722E94F},
	{"CR861", 0x99C740B0},
	{"CS500", 0x0FF9C026},
	{"CX800", 0x7374BC6A},
	{"EA...", 0xEED9A107},
	{"EC80A", 0xC6E19CF0},
	{"EC82A", 0xC6E19CF0},
	{"EC87A", 0xC6E19CF0},
	{"ED09B", 0xC6E19CF0},
	{"EG03E", 0xEED9A107},
	{"EH010", 0x7C672F93},
	{"EH115", 0xEED9A107},
	{"EJ30A", 0xCAB57DE1},
	{"EJ90A", 0xAE9961C5},
	{"EL19A", 0xC6E19CF0},
	{"EL52D", 0xC6E19CF0},
	{"EM62B", 0xC6E19CF0},
	{"EM63A", 0xC6E19CF0},
	{"EQ910", 0xBAA56CD1},
	{"ET81A", 0xE5D097FC},
	{"EV...", 0x8FFD3C82},
	{"EZ11D", 0xE7D29AFF},
	{"JA90C", 0xE5D097FC},
	{"JB10D", 0x9F8A52B7},
	{"JB11D", 0x9F8A52B7},
	{"JF30C", 0x78632B8F},
	{"JK6..", 0x8FFD3C82},
	{"JK75E", 0x9E8950B5},
	{"JK77D", 0x9E8950B5},
	{"JK80C", 0x8FFD3C82},
	{"JK91B", 0x9E8950B5},
	{"JK92B", 0x9E8950B5},
	{"JU0.A", 0xC6E19CF0},
	{"M5113", 0x75B4C26D},
	{"TK405", 0xED19DF45},
	{"VC261", 0xC9DCA40A},
	{"VC262", 0xC9DCA40A},
	{"VC263", 0xC9DCA40A},
	{"VC264", 0xC9DCA40A},
	{"VC265", 0x211CE348},
	{"VC266", 0x211CE348},
	{"VC267", 0x211CE348},
	{"VC268", 0x211CE348},
	{"VC269", 0x211CE348},
	{"VC628", 0x211CE348},
	{"VC85A", 0x211CE348},
	{"VD70A", 0x211CE348},
	{"VG310", 0x432EF55B},
	{"WE85C", 0x7374BC6A},
	{"WL00C", 0xED19DF45},
	{"WL90B", 0x71DE1D63},
	{"Z31M2", 0xED19DF45},
	{"ZB010", 0x3C24EB50},
	{"ZB060", 0x9F8A52B7},
	{"ZB075", 0x624D157A},
	{"ZB605", 0x3C24EB50},
	{"ZC...", 0x7C672F93},
	{"ZD89A", 0x93B645A1},
	{"ZE05B", 0x7F6A3297},
	{"ZE97B", 0xE5D097FC},
	{"ZH0..", 0x8CF9387E},
	{"ZH1..", 0x7C672F93},
	{"ZH20A", 0x7C672F93},
	{"ZH3..", 0x4D38FE64},
	{"ZH5..", 0x3B26EC52},
	{"ZH99A", 0x3722E94F},
	{"ZJ0..", 0x3823EA50},
	{"ZJ5..", 0x7F6A3297},
	{"ZK01B", 0x3722E94F},
	{"ZN30A", 0x9F8A52B7},
	{"ZN31A", 0x9F8A52B7},
	{"ZP1..", 0x3722E94F},
	{"ZP3..", 0x3722E94F},
	{"ZP5..", 0xC02E6CB2},
	{"ZQ03E", 0xF0DBA309},
	{"ZQ05B", 0xD3BE86EA},
	{"ZQ11E", 0xF0DBA309},
	{"ZR00B", 0xF0DBA309},
	{"ZR00E", 0xF0DBA309},
	{"ZR02E", 0xF0DBA309},
	{"ZR05E", 0xF0DBA309},
	{"ZR11B", 0xD3BE86EA},
	{"ZR12B", 0xD3BE86EA},
	{"ZR15B", 0xD3BE86EA},
	{"ZR16B", 0xD3BE86EA},
	{"ZR26B", 0xF0DBA309},
	{"ZR32B", 0xD3BE86EA},
	{"ZR35B", 0xD3BE86EA},
	{"ZS08A", 0x3621E84E},
	{"ZT09C", 0x1701C82E},
	{"ZT28B", 0x1701C82E},
	{"ZT28D", 0x1701C82E},
	{"ZX56A", 0xE5D097FC},
	{"ZX71C", 0x9F8A52B7},
	{"ZY7..", 0x968148AD},
	{"", 0}
	};


/* calculate difference between 2 ECUIDs ; 0 is identical , 1 is almost identical etc */

static int ecuid_calcdiff(const char *ecuid, const char *item) {
	int diff = 5;
	int idx;
#if 0
	/* algo 1 : stop at first different char, left-to-right. */
	for (idx=0; idx <= 4; idx += 1) {
		if (ecuid[idx] != item[idx]) break;
		diff -= 1;
	}
	return diff;
#endif
#if 0
	/* algo 2 : count different chars */
	/* matching only the last chars gives a good score here but doesn't correlate well with keys */
	for (idx=0; idx <= 4; idx += 1) {
		if (ecuid[idx] == item[idx]) diff -= 1;
	}
	return diff;
#endif
#if 0
	/* algo 3 : weighted algo 2, index=0 is more important */
	/* interesting, but no wildcards */
	diff = 0;
	int weight = 5;
	for (idx=0; idx <= 4; idx += 1, weight -= 1) {
		if (ecuid[idx] != item[idx]) diff += weight;
	}
	return diff / 3;
#endif
#if 0
	/* algo 4 : find first diff left-to-right, wildcards count as identical */
	for (idx=0; idx <= 4; idx += 1) {
		if (	(ecuid[idx] != item[idx]) &&
			(ecuid[idx] != '.')) {
			break;
		}
		diff -= 1;
	}
	return diff;
#endif
#if 1
	/* algo 5 : weighted comparison, index=0 is more important, wildcards count for less than identical chars */
	diff = 0;
	int weight = 5;
	for (idx=0; idx <= 4; idx += 1, weight -= 1) {
		if (ecuid[idx] == '.') {
			diff += (weight / 2);
			continue;
		}
		if (ecuid[idx] != item[idx]) diff += weight;
	}
	return diff;
#endif
}


//gadget to use qsort()
static int bs_compar(const void *a, const void *b) {
	const struct ecuid_keymatch_t *ka, *kb;
	ka = a;
	kb = b;
	return ka->dist - kb->dist;
}

void ecuid_getkeys(const char *ECUID, struct ecuid_keymatch_t *kclist, unsigned candidates) {
	
	#define MAXDIST 100
	unsigned i;

	for (i = 0; i < candidates; i++) {
		kclist[i].key = 0;
		kclist[i].kidx = 0;
		kclist[i].dist = MAXDIST;
	}



	//const char spacing[]="      ";
	for (i=0; ecuid_list[i].s27k != 0; i++) {
		int dist = ecuid_calcdiff(ECUID, ecuid_list[i].ecuid);
		//printf("%s\t%.*s%d\n", ecuid_list[i].ecuid, dist, spacing, dist);


		//find the first slot with the same key and a worse distance
		//check if key already in the candidate list
		bool already_there = 0;
		unsigned loopc;
		for (loopc = 0; loopc < candidates; loopc += 1) {
			unsigned idxmod = loopc;

			if (kclist[idxmod].key == ecuid_list[i].s27k) {
				already_there = 1;
				//already in list: better distance?
				if (dist < kclist[idxmod].dist) {
					kclist[idxmod].dist = dist;
				}
				break;
			}
		}
		//else, replace the slot with the worse distance
		if (!already_there) {
			int maxdist = 0;
			int maxdist_idx = 0;
			//find worse distance
			for (loopc = 0; loopc < candidates; loopc += 1) {
				int idxmod = loopc;
	
				if (kclist[idxmod].dist > maxdist) {
					maxdist = kclist[idxmod].dist;
					maxdist_idx = idxmod;
				}
			}
			
			kclist[maxdist_idx].key = ecuid_list[i].s27k;
			kclist[maxdist_idx].kidx = i;
			kclist[maxdist_idx].dist = dist;
		}
	}
	qsort(kclist, candidates, sizeof(struct ecuid_keymatch_t), bs_compar);
	return;
}
