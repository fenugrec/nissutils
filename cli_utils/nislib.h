/* collection of funcs for working with Nissan ROMs
 * (c) fenugrec 2014-2015
 * GPLv3
 */

#include <stdint.h>

/** Read uint32 at *buf with SH endianness
*/
uint32_t reconst_32(const uint8_t *buf);

/** Read uint16 at *buf with SH endianness
*/
uint16_t reconst_16(const uint8_t *buf);

/** write uint32 at *buf with SH endianness
*/
void write_32b(uint32_t val, uint8_t *buf);

/** calculate checksums and find their location
 *
 * @param p_cks : sum location (file offset)
 * @param p_ckx : xor location (file offset)
 * @return 0 if ok
 *
 * Uses "standard" algo
 */
int checksum_std(const uint8_t *buf, long siz, long *p_cks, long *p_ckx);

/** Calculate correction values to give a known checksum
 *
 * @param siz length of *buf, in bytes
 * @param p_cks location of original sum that is to be matched
 * @param p_ckx location of original xor that is to be matched
 * @param p_a location, in *buf, of first correction value
 * @param p_b location, in *buf, of second correction value
 * @param p_c location, in *buf, of third correction value
 *
 */
void checksum_fix(uint8_t *buf, long siz, long p_cks, long p_ckx,
		long p_a, long p_b, long p_c);