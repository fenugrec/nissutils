/* collection of funcs for working with Nissan ROMs
 * (c) fenugrec 2014-2015
 * GPLv3
 */

#include <stdint.h>
#include <stdbool.h>

#define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))

/* this needs to be valid; debugging output is written to this.*/
extern FILE *dbg_stream;	//such as as stdout or stderr

/** Read uint32 at *buf with SH endianness
*/
uint32_t reconst_32(const uint8_t *buf);

/** Read uint16 at *buf with SH endianness
*/
uint16_t reconst_16(const uint8_t *buf);

/** write uint32 at *buf with SH endianness
*/
void write_32b(uint32_t val, uint8_t *buf);

/** search a <buflen> u8 buffer for a <len>-byte long sequence.
 *
 * @param buflen size in bytes of *buf
 * @param needle pattern to search
 * @param nlen size of "needle" pattern
 * @return NULL if not found
 *
 * Painfully unoptimized, because it's easy to get it wrong
 */
const uint8_t *u8memstr(const uint8_t *buf, long buflen, const uint8_t *needle, long nlen);

/** search a <buflen> u8 buffer for a 32-bit aligned u32 value, in SH endianness
 *
 */
const uint8_t *u32memstr(const uint8_t *buf, long buflen, const uint32_t needle);

/* "security" algorithms */

/** Encode u32 data, algo 1
 * @param data u32 value to encode
 * @param scode key to use
 */
uint32_t enc1(uint32_t data, uint32_t scode);

/** Decode u32 data, algo 1
 * @param data u32 value to decode
 * @param scode key to use
 */
uint32_t dec1(uint32_t data, uint32_t scode);

/* key stuff */
struct keyset_t {
	uint32_t s27k;
	uint32_t s36k1;
	uint32_t s36k2;
	};

extern const struct keyset_t known_keys[];


/** Sum and xor all u32 values in *buf, read with SH endianness
 * @param [out] *xor
 * @param [out] *sum
 */
void sum32(const uint8_t *buf, long siz, uint32_t *sum, uint32_t *xor);

/** calculate checksums and find their location
 *
 * @param siz : size of *buf in bytes
 * @param p_cks : sum location (offset in buf)
 * @param p_ckx : xor location (offset in buf)
 * @return 0 if ok
 *
 * Uses "standard" algo
 */
int checksum_std(const uint8_t *buf, long siz, long *p_cks, long *p_ckx);

/** calculate alt2 checksum and find its location
 *
 * @param siz : size of *buf in bytes
 * @param p_ack_s : sum location (offset in buf)
 * @param p_ack_x : xor location (offset in buf)
 * @param p_skip1 : if >= 0: first location to skip (offset in buf)
 * @param p_skip2 : if >= 0: second location to skip (offset in buf)
 *
 * @return 0 if ok
 *
 * This is the same algo as "std checksum", but assumes a loop that
 * skips 4 locations (sum,xor, skip1, skip2).
 */
int checksum_alt2(const uint8_t *buf, long siz, long *p_ack_s, long *p_ack_x,
				long p_skip1, long p_skip2);

/** Calculate correction values to give a known checksum
 *
 * @param siz length of *buf, in bytes
 * @param p_cks location of original sum that is to be matched
 * @param p_ckx location of original xor that is to be matched
 * @param p_a location, in *buf, of first correction value
 * @param p_b location, in *buf, of second correction value
 * @param p_c location, in *buf, of third correction value
 *
 * This calculates and sets values a,b,c so that the checksums match the original sum and xor.
 */
void checksum_fix(uint8_t *buf, long siz, long p_cks, long p_ckx,
		long p_a, long p_b, long p_c);


/** Verify if a vector table (IVT) is sane.
 * @param ivt : start of vector table
 * @return true if it's an IVT.
 *
 * Uses very basic heuristics :
 * - check if the power-on and manual resets have the same values for PC and SP
 * - PC points in bottom 16MB, aligned on 2-byte boundary
 * - SP points in RAM, aligned on 4-byte boundary
 *
 * Example of a valid IVT : 0000 0104, ffff 7ffc, 0000 0104, ffff 7ffc
 */
bool check_ivt(const uint8_t *buf);

/** find a likely vector table (IVT)
 * @param siz length of *buf, in bytes
 * @return offset of IVT if successful, -1 otherwise
 */
long find_ivt(const uint8_t *buf, long siz);


/** find EEPROM read_byte(addr, &dest) function address and IO port used */
uint32_t find_eepread(const uint8_t *buf, long siz, uint32_t *real_portreg);

/** try to find sid27 key through code analysis
 * @param s27k : output
 * @param s36k : output
 */
bool find_s27_hardcore(const uint8_t *buf, long siz, uint32_t *s27k, uint32_t *s36k);
