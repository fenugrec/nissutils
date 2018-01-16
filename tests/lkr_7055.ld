/*
*****************************************************************************
**
** Linker script for SH7055
**	- no heap
**	- no stack init
**	- uses RAM > 0xFFFF8000 to test sign extension
**
From GNU ld docs : 
"
Every loadable or allocatable output section has two addresses. The ?rst is the VMA, or
virtual memory address. This is the address the section will have when the output ?le is
run. The second is the LMA, or load memory address. This is the address at which the
section will be loaded. In most cases the two addresses will be the same. An example of
when they might be diferent is when a data section is loaded into ROM, and then copied
into RAM when the program starts up (this technique is often used to initialize global
variables in a ROM based system). In this case the ROM address would be the LMA, and
the RAM address would be the VMA.
"
ADDR(section) returns the VMA of <section>.
LOADADDR(section) returns the LMA of <section>
*****************************************************************************
*/

/* (c) copyright fenugrec 2018
 * GPLv3
 */



/* Entry Point */
/* ENTRY(test_main)*/

/* Memory areas */
MEMORY {
	ROMHOLE (xr)	: ORIGIN = 0x00000, LENGTH = 64k
	RAM (xw)	: ORIGIN = 0xFFFF8000, LENGTH = 32K
}
REGION_ALIAS("TGT", ROMHOLE);

/* Define output sections */
SECTIONS
{
	/* program code and other data */
	.text :
	{
		. = ALIGN(4);
		*(.text)           /* .text sections (code) */
		*(.text*)          /* .text* sections (code) */

		. = ALIGN(4);
		_etext = .;        /* define a global symbols at end of code */
	} >TGT

	/* Constant data  */
	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)         /* .rodata sections (constants, strings, etc.) */
		*(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
		. = ALIGN(4);
	} >TGT


	/* Initialized data sections */
	.data : 
	{
		. = ALIGN(4);
		_sdata = .;        /* create a global symbol at data start */
		*(.data)           /* .data sections */
		*(.data*)          /* .data* sections */

		. = ALIGN(4);
		_edata = .;        /* define a global symbol at data end */
		_idatalen = . - _sdata;
	} >RAM


	/* Uninitialized data section */
	. = ALIGN(4);
	.bss :
	{
		_sbss = .;         /* define a global symbol at bss start */
		*(.bss)
		*(.bss*)
		*(COMMON)

		. = ALIGN(4);
		_ebss = .;         /* define a global symbol at bss end */
		_bsslen = . - _sbss;
	} >RAM


	/* Remove information from the standard libraries */
	/DISCARD/ :
	{
	*(.comment)
	libc.a ( * )
	libm.a ( * )
	libgcc.a ( * )
	}

}
