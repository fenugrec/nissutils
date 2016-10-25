#ifndef _ECUID_LIST_H
#define _ECUID_LIST_H

/* Functionality for matching ECUIDs to most likely keyset.
 *
 * Copyright (c) fenugrec 2016
 * Licensed under GPLv3
 */

#include <stdint.h>

struct ecuid_keymatch_t {
	uint32_t key;
	int dist;
};

/** Fill list with best key match candidates
Caller must provide this array:
	struct ecuid_keymatch_t k_candidates[candidates];	//for the best N keys found
*/
void ecuid_getkeys(const char *ECUID, struct ecuid_keymatch_t *k, const unsigned candidates);

#endif
