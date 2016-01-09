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

/** calculate checksums and find their location
 *
 * @param p_cks : sum location (file offset)
 * @param p_ckx : xor location (file offset)
 * @return 0 if ok
 *
 * Uses "standard" algo
 */
int checksum_std(const uint8_t *buf, long siz, long *p_cks, long *p_ckx);
