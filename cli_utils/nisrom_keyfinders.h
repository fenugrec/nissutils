/* collection of funcs for working with Nissan ROMs
 * (c) fenugrec 2022
 * GPLv3
 */

#ifndef NISROM_KEYFINDERS_H
#define NISROM_KEYFINDERS_H

#include <stdint.h>
#include <stdbool.h>

#include "stypes.h"

/* key stuff */


enum key_quality {
	KEYQ_UNK = 0,	// totally inconclusive
	KEYQ_STRAT_1NEW,	// code analysis found one new key : unusable but useful for further analysis
	KEYQ_STRAT_2NEW,	// code analysis found two new keys, s27 vs s36 not necessarily differentiated.
	KEYQ_BRUTE_1,	// found one known key literal by exhaustive search
	KEYQ_BRUTE_BOTH,	//  found known s27+s36 key literals
	KEYQ_STRAT_1,	// code an. found 1 known key
	KEYQ_STRAT_BOTH,	// code an. found known s27+s36 keys
};

/** try to find sid27 key through code analysis
 * @param s27k : output
 * @param s36k : output
 *
 * @return quality > KEYQ_UNK if anything found
 */
enum key_quality find_s27_hardcore(const uint8_t *buf, uint32_t siz, uint32_t *s27k, uint32_t *s36k);



/** find literal sid27 and/or sid36 key
 *
 * @param[out]  keyq : quality of key match
 * @param thorough continue search for multiple occurences
 *
 * @return keyset if found and sets *keyq > KEYQ_UNK.
 *
 * this does no code analysis, only looking for two halfkeys stored nearby.
 */
const struct keyset_t *find_keys_bruteforce(const u8 *buf, u32 siz, enum key_quality *keyq, bool thorough);

#endif
