/* collection of funcs for SuperH analysis
 * (c) fenugrec 2014-2022
 * GPLv3
 */

#ifndef NISLIB_SHTOOLS_H
#define NISLIB_SHTOOLS_H

#include <stdio.h>	//just for FILE
#include <stdint.h>
#include <stdbool.h>

#include "stypes.h"

/* this needs to be valid; debugging output is written to this.*/
extern FILE *dbg_stream;	//such as as stdout or stderr


/************** SH analysis helpers */

/** find the main calltable (large array of function pointers polled in a loop)
 * @return offset if succesful, -1 otherwise; length of table (in # of entries) written to *ctlen
 * @param skip : start at &buf[skip]
 *
 * Arguably this belongs more in nislib maybe
*/
uint32_t find_calltable(const uint8_t *buf, uint32_t skip, uint32_t siz, unsigned *ctlen);

/** Find opcode pattern... bleh
 * "patlen" is # of opcodes
 */
uint32_t find_pattern(const uint8_t *buf, uint32_t siz, unsigned patlen,
			const uint16_t *pat, const uint16_t *mask);


/** sign-extension helpers */
u32 sh_extsb(u8 val);
u32 sh_extsw(u16 val);

enum opcode_dest {
	R0 = 0, R15 = 15, GBR, OPC_DEST_OTHER};


/** backtrack, starting at &buf[starpos], trying to find a MOV.W R0, @(disp, Rn)
*
* @param min : lower bounds of search at &buf[min]
* @param found_pos : if found, position of hit
* @param reg_dest : if found, Rn number
* @param disp : if found, displacement (in bytes)
*
* @return 1 if ok
*/
bool bt_MOVW_R0_REGDISP(const u8 *buf, u32 startpos, u32 min, u32 *found_pos, enum opcode_dest *reg_dest, unsigned *disp);


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


/** determine what register is modified by a given opcode */
enum opcode_dest sh_getopcode_dest(uint16_t code);


/** recursively track usage of register <regno>.
 * start at <pos> in buffer (typically opcode after the one setting regno);
 * updates the <visited> array (provided as =={0} by caller)
 * on every instruction, invokes the tracker_cb callback while passing it <cbdata> as a generic holder.
 */
void sh_track_reg(const uint8_t *buf, uint32_t pos, uint32_t siz, unsigned regno, uint16_t *visited,
			void (*tracker_cb)(const uint8_t *buf, uint32_t pos, unsigned regno, void *data), void *cbdata);

#endif
