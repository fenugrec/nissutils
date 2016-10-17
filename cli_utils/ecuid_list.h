#ifndef _ECUID_LIST_H
#define _ECUID_LIST_H

#include <stdint.h>

struct ecuid_klist_t {
	const char *ecuid;
	uint32_t s27k;
	};

extern const struct ecuid_klist_t ecuid_list[];


/** Fill list with best key match candidates
Caller must provide
	u32 key_candidates[candidates];	//for the best N keys found
	int keyc_dists[candidates];
*/
void ecuid_getkeys(const char *ECUID, uint32_t *key_candidates, int *keyc_dists, unsigned candidates);

#endif
