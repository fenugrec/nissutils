/* collection of funcs for working with Nissan ROMs
 * (c) fenugrec 2014-2015
 * GPLv3
 */

#ifndef NISLIB_H
#define NISLIB_H

#include <stdio.h>	//just for FILE
#include <stdint.h>
#include <stdbool.h>

#include "stypes.h"


#define MIN(_a_, _b_) (((_a_) < (_b_) ? (_a_) : (_b_)))
#define MAX(_a_, _b_) (((_a_) > (_b_) ? (_a_) : (_b_)))
#define ARRAY_SIZE(x)	(sizeof(x) / sizeof((x)[0]))

#define	MIN_ROMSIZE (128*1024UL)	//smallest known ROM is SH7050, 128kB
#define MAX_ROMSIZE (2048*1024UL)

/* this needs to be valid; debugging output is written to this.*/
extern FILE *dbg_stream;	//such as as stdout or stderr

/** get file length but restore position */
uint32_t flen(FILE *hf);

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
const uint8_t *u8memstr(const uint8_t *buf, uint32_t buflen, const uint8_t *needle, unsigned nlen);

/** search for an aligned, big-endian u16 value. */
const uint8_t *u16memstr(const uint8_t *buf, uint32_t buflen, const uint16_t needle);

/** same as u16memstr but searches backwards starting at buf[start_pos] */
const uint8_t *u16memstr_rev(const uint8_t *buf, uint32_t start_pos, const uint16_t needle);

/** search a <buflen> u8 buffer for a 32-bit aligned uint32_t value, in SH endianness
 *
 */
const uint8_t *u32memstr(const uint8_t *buf, uint32_t buflen, const uint32_t needle);


/** Find opcode pattern... bleh
 * "patlen" is # of opcodes
 *
 * @return (u32) -1 if failed
 */
uint32_t find_pattern(const uint8_t *buf, uint32_t siz, unsigned patlen,
			const uint16_t *pat, const uint16_t *mask);


/* "security" algorithms */

/** Encode uint32_t data, algo 1
 * @param data uint32_t value to encode
 * @param scode key to use
 */
uint32_t enc1(uint32_t data, uint32_t scode);

/** Decode uint32_t data, algo 1
 * @param data uint32_t value to decode
 * @param scode key to use
 */
uint32_t dec1(uint32_t data, uint32_t scode);

/* key stuff */

enum key_type {
	KEY_S27 = 0,	//SID27 key
	KEY_S36K1,	//SID36 kernel key
	KEY_S36K2,	//SID36 factory payload key (less useful)
	KEY_INVALID,
};

enum key_quality {
	KEYQ_UNK = 0,	// totally inconclusive
	KEYQ_STRAT_1NEW,	// code analysis found one new key : unusable but useful for further analysis
	KEYQ_STRAT_2NEW,	// code analysis found two new keys, s27 vs s36 not necessarily differentiated.
	KEYQ_BRUTE_1,	// found one known key literal by exhaustive search
	KEYQ_BRUTE_BOTH,	//  found known s27+s36 key literals
	KEYQ_STRAT_1,	// code an. found 1 known key
	KEYQ_STRAT_BOTH,	// code an. found known s27+s36 keys
};

struct keyset_t {
	uint32_t s27k;
	uint32_t s36k1;
	uint32_t s36k2;
	};

extern const struct keyset_t known_keys[];


/** try to see if candidate matches one known keyset.
 *
 * @param candidate must not be 0
 *
 * return NULL if not found
 */
const struct keyset_t *find_knownkey(enum key_type ktype, u32 candidate);

/** Sum and xor all uint32_t values in *buf, read with SH endianness
 * @param [out] *xor
 * @param [out] *sum
 */
void sum32(const uint8_t *buf, uint32_t siz, uint32_t *sum, uint32_t *xor);

/** calculate checksums and find their location
 *
 * @param siz : size of *buf in bytes
 * @param p_cks (output) sum location (offset in buf)
 * @param p_ckx (output) xor location (offset in buf)
 * @return 0 if ok
 *
 * Uses "standard" algo
 */
int checksum_std(const uint8_t *buf, uint32_t siz, uint32_t *p_cks, uint32_t *p_ckx);

/** calculate alt2 checksum and find its location
 *
 * @param siz : size of *buf in bytes
 * @param p_ack_s : sum location (offset in buf)
 * @param p_ack_x : xor location (offset in buf)
 * @param p_skip1 : if != UINT32_MAX: first location to skip (offset in buf)
 * @param p_skip2 : if != UINT32_MAX: second location to skip (offset in buf)
 *
 * @return 0 if ok
 *
 * This is the same algo as "std checksum", but assumes a loop that
 * skips 4 locations (sum,xor, skip1, skip2).
 */
int checksum_alt2(const uint8_t *buf, uint32_t siz, uint32_t *p_ack_s, uint32_t *p_ack_x,
				uint32_t p_skip1, uint32_t p_skip2);

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
void checksum_fix(uint8_t *buf, uint32_t siz, uint32_t p_cks, uint32_t p_ckx,
		uint32_t p_a, uint32_t p_b, uint32_t p_c);


/** Verify if a vector table (IVT) is sane.
 * @param ivt : start of vector table
 * @param siz : bytes in buf[]
 * @return true if it's an IVT.
 *
 * Uses very basic heuristics :
 * - check if the power-on and manual resets have the same values for PC and SP
 * - PC points in bottom 16MB, aligned on 2-byte boundary
 * - SP points in RAM (top 128kB), aligned on 4-byte boundary
 *
 * Example of a valid IVT : 0000 0104, ffff 7ffc, 0000 0104, ffff 7ffc
 */
bool check_ivt(const uint8_t *buf, unsigned siz);

#define IVT_MINSIZE 0x100	//absolute minimum for a trimmed IVT on 705x

/** find a likely vector table (IVT)
 * @param siz length of *buf, in bytes
 * @return offset of IVT if successful, -1 otherwise
 */
uint32_t find_ivt(const uint8_t *buf, uint32_t siz);


/** find the main calltable (large array of function pointers polled in a loop)
 * @return offset if succesful, -1 otherwise; length of table (in # of entries) written to *ctlen
 * @param skip : start at &buf[skip]
*/
uint32_t find_calltable(const uint8_t *buf, uint32_t skip, uint32_t siz, unsigned *ctlen);

/** find EEPROM read_byte(addr, &dest) function address and IO port used
 * returns address of eepread() function, otherwise 0 if nothing found
 */
uint32_t find_eepread(const uint8_t *buf, uint32_t siz, uint32_t *real_portreg);

/** try to find sid27 key through code analysis
 * @param s27k : output
 * @param s36k : output
 *
 * @return quality > KEYQ_UNK if anything found
 */
enum key_quality find_s27_hardcore(const uint8_t *buf, uint32_t siz, uint32_t *s27k, uint32_t *s36k);



/************** SH analysis helpers */

/** backtrack search for immediate value
 *
 * Recursive backtrack inside code to find the root value loaded by "mov imm16, Rn", "mov imm32, Rn" or "movi20 #imm20, rn" instructions.
 *
 * start : offset in buf[] of first opcode to analyze
 * regno : n from "Rn"
 * min : don't backtrack further than buf[min]
 *
 *
 * @return 0 if failed. 32-bit immediate is written to *imm if succesful
 *
 * handles : multiple-mov sequences, shll, shll2, shll8, shlr16, extu.b, add #imm8.
 */
int sh_bt_immload(uint32_t *imm, const uint8_t *buf, uint32_t min, uint32_t start, unsigned regno);

/** return the immediate value loaded by PC-relative opcode (mov.w or mov.l only)
 * caller must have ensured opcode is a mov.x (@PC, disp), Rn opcode
 *
 * @param pos Position of opcode within buffer
 *
 */
uint32_t sh_get_PCimm(const uint8_t *buf, uint32_t pos);


/** Find all "bsr N" occurences that call the function at <tgt>.
 * for every hit, calls <callback>(<cdata>)
 */
void find_bsr(const uint8_t *buf, uint32_t tgt, void (*found_bsr_cb)(const uint8_t *buf, uint32_t pos, void *data), void *cbdata);


/** for bt,bf sign-extended offsets : return PC+4+ (exts.b offset)<<1 */
uint32_t disarm_8bit_offset (uint32_t pos, uint32_t offs);

/** for {bra,bsr} only: (sign-extend 12bit offset)<<1  + PC +4 */
uint32_t disarm_12bit_offset (uint32_t pos, uint32_t insoff);



enum opcode_dest {
	R0 = 0, R15 = 15, GBR, OPC_DEST_OTHER};

/** determine what register is modified by a given opcode */
enum opcode_dest sh_getopcode_dest(uint16_t code);


/** recursively track usage of register <regno>.
 * start at <pos> in buffer (typically opcode after the one setting regno);
 * updates the <visited> array (provided as =={0} by caller)
 * on every instruction, invokes the tracker_cb callback while passing it <cbdata> as a generic holder.
 */
void sh_track_reg(const uint8_t *buf, uint32_t pos, uint32_t siz, unsigned regno, uint16_t *visited,
			void (*tracker_cb)(const uint8_t *buf, uint32_t pos, unsigned regno, void *data), void *cbdata);

#endif // NISLIB_H
