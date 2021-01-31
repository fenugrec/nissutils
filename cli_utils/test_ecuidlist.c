/* test matching algos for ECUID to key list */

#include "ecuid_list.h"
#include "stypes.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	int i;
	#define NUM_CANDIDATES 3
	struct ecuid_keymatch_t key_candidates[NUM_CANDIDATES];	//for the best N keys found

	if (argc != 2) {
		printf("%s <ECUID>"
			"\n\tCase-sensitive; Example: %s 6Z68A\n", argv[0], argv[0]);
		return 0;
	}

	ecuid_getkeys(argv[1], key_candidates, NUM_CANDIDATES);

	for (i = 0; i < NUM_CANDIDATES; i++) {
		printf("%d\t0x%08lX\t%d\n",i, (unsigned long) key_candidates[i].key, key_candidates[i].dist);
	}


	return 0;
}
