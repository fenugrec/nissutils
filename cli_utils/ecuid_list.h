#ifndef _ECUID_LIST_H
#define _ECUID_LIST_H

#include <stdint.h>

struct ecuid_klist_t {
	const char *ecuid;
	uint32_t s27k;
	};

extern const struct ecuid_klist_t ecuid_list[];


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
