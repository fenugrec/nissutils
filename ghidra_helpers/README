Nissan / generic SH-based ROM loader for Ghidra

(c) fenugrec 2022
GPLv3

# Intro
This script is mainly designed for Nissan ECU ROMs but can be useful on other ROMs based on one of these  :

- SH7050, SH7051
- SH7052, SH7054
- SH7055
- SH7058
- SH7059
- SH72531 (limited support, help needed)
- SH72543 (limited support, help needed)

# Operating modes
In "full auto" mode (only works for Nissan ROM dumps), this script will determine the correct CPU and define

- memory areas
- interrupt vectors, including split vector tables if applicable
- IO peripheral registers

In "basic" mode, useful for generic or unknown ROMs, the script will prompt for a device type and define

- memory areas
- basic interrupt vectors
- IO peripheral registers


# Expanding / adding support
The raw data for vectors and registers are stored in .csv files. In addition, some tables may need to be expanded in nissan_load.py

Feel free to expand or improve this, PR's are more than welcome.

# Using
The cleanest way is to use this script as the very first step after importing the .bin file.
1. Open Script Manager
2. One of the buttons top-right is "Manage Script directories"
3. Add the directory containing this script.
4. Refresh the list of scripts : there should be a new category Nissan containing this script
5. Run script

# Examples

Here is part of a dual-IVT ROM, with the second IVT at 0x1000 :
```
000011da 27              ??         27h    '
000011db 5c              ??         5Ch    \
000011dc 00              ??         00h
000011dd 00              ??         00h
000011de 27              ??         27h    '
000011df 5c              ??         5Ch    \
000011e0 00 00 14 08     addr       alt_INT_ATU31_IMI3A                              ATU31_IMI3A interrupt
000011e4 00 03 68 42     addr       alt_INT_ATU31_IMI3B                              ATU31_IMI3B interrupt
000011e8 00 00 27 5c     addr       alt_Manual_Reset                                 ATU31_IMI3C interrupt
000011ec 00 01 02 28     addr       alt_INT_ATU31_IMI3D                              ATU31_IMI3D interrupt
000011f0 00 00 27 5c     addr       alt_Manual_Reset                                 ATU32_OVI3 interrupt
```

Here, some IO regs showing correct names and xrefs:
```
		 PAIOR_W                                 XREF[2]:     FUN_00000cc0:00000cc4(W),
                                                              FUN_0000bf84:0000bf92(W)
fffff720                 undefined2 ??
		 PACRH_W                                 XREF[1]:     FUN_0000bf84:0000bf94(W)
fffff722                 undefined2 ??
		 PACRL_W                                 XREF[1]:     FUN_0000bf84:0000bfa0(W)
fffff724                 undefined2 ??
```

And lastly, an example of code with nice IO reg names :

```
void Manual_Reset(void)

{
  undefined4 *puVar1;

  write_volatile_2(MSTCR_[W]_W,0x3c07);
  DAT_ffff8000 = alt_Manual_Reset;
  alt_Manual_Reset();
  for (puVar1 = &DAT_ffff8000; puVar1 < &DAT_ffffbce9; puVar1 = puVar1 + 0x1) {
    *puVar1 = 0x0;
  }
  write_volatile_2(BSC_BCR1_W,0xf);
  write_volatile_2(BSC_BCR2_W,0xf4ff);
  write_volatile_2(BSC_WCR_W,0xff11);
  write_volatile_2(BSC_RAMER_W,0x0);
  DAT_ffff7ffc = read_volatile_2(ATUII_TSR1A_W);
  write_volatile_2(ATUII_TSR1A_W,0x0);
  FUN_00000cc0();
  ......
```
