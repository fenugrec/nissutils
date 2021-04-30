/* generate all possible 16bit opcodes */
/* Lots of them will be invalid, this doesn't do any filtering */
/* fenugrec 2018 */

#define OFNAME "sh_allops.bin"

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE *hfil;
	unsigned oph, opl;

	hfil=fopen(OFNAME, "wb");
	if (!hfil) {
		printf("fopen err\n");
		return 1;
	}

	for (oph = 0; oph <= 0xFF; oph++) {
		uint8_t lbuf[256*2];
		memset(lbuf, oph, sizeof(lbuf));
		for (opl = 0; opl <= 0xFF; opl++) {
			lbuf[1 + (opl * 2)] = opl;
		}
		if (sizeof(lbuf) != fwrite(lbuf, 1, sizeof(lbuf), hfil)) {
			printf("fwrite err\n");
			goto badexit;
		}
	}
	fclose(hfil);
	return 0;
badexit:
	fclose(hfil);
	return 1;
}

