#ifndef NISROM_FINDERS_H
#define NISROM_FINDERS_H

#include <stdbool.h>
#include <stdint.h>

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


/** find EEPROM read_byte(addr, &dest) function address and IO port used
 * returns address of eepread() function, otherwise 0 if nothing found
 */
uint32_t find_eepread(const uint8_t *buf, uint32_t siz, uint32_t *real_portreg);

#endif
