# nissutils — USAGE

## Purpose

nissutils is a collection of command-line tools for working with Nissan ECU
ROMs (roughly 2000–2017). They handle checksum correction, encryption,
key derivation, binary analysis, and ROM identification.

All tools are standalone executables — no install required.

---

## Tools

### nisrom — ROM analysis

Identify and validate a Nissan ROM dump. Reports ECU family, FID (firmware ID),
checksum locations, keyset quality, s27k/s36k keys, EEPROM read address, and
MD5 hash.

```
nisrom <ROMFILE> [OPTIONS]

OPTIONS:
  -v    human-readable output (default if no -c/-l given)
  -c    CSV output (values only)
  -l    CSV headers — can combine with -c, or use alone without ROMFILE
  -h    show help
  -f    force parsing, ignore errors [DANGEROUS — may crash or produce wrong output]
```

**Key output fields:**

| Field | Description |
|-------|-------------|
| ECUID | Extracted from filename (first `-`/`_`-delimited token if 5 chars) |
| FID | Firmware ID string embedded in ROM (e.g. `1Q6MAZNV`) — the Cal ID |
| std cks? | 1 if standard checksum valid; `&std_s` and `&std_x` give locations |
| s27k / s36k1 | Security keys extracted directly from ROM binary |
| &EEPROM_read() | File offset of `eeprom_read()` function — use with `npconf eepr` in nisprog |
| MD5 | ROM file hash — useful for confirming dump integrity |

**Examples:**

```
nisrom rom.bin              # identify ROM — human readable
nisrom rom.bin -c -l        # CSV with headers — pipe to spreadsheet
nisrom -l                   # print CSV column headers only (no ROM file needed)
```

**AI notes:**
- `nisrom` is **analysis only** — it never modifies the ROM file. There is no
  `--fix` flag. Use `nisckfix1` or `nisckfix2` to fix checksums after editing.
- **`nisrom` derives s27k/s36k directly from the ROM binary** via code analysis
  (`find_s27_hardcore`) and brute-force fallback. If `keyset quality` > 0, the
  output s27k/s36k are usable directly in `nisprog setkeys`. This is the primary
  way to get keys for a ROM not in nisprog's bundled DB.
- **ECUID comes from the filename**, not ROM contents. Name the file with the
  ECUID as the first token (e.g. `6S710.bin` or `MEC07-370C1.bin`) for correct
  ECUID display. A file named `rom.bin` will not show an ECUID.
- `&std_s` and `&std_x` from the output are the arguments to pass to
  `nisckfix1`/`nisckfix2` after editing the ROM.
- `&EEPROM_read()` from the output is the address to pass to `npconf eepr`
  in nisprog before running `dm <file> 0 512 eep`.
- Debug output is written to `nisrom_dbg.log` in the current directory.
- `-f` (force parse) may cause segfaults. Do not use on clean workflows.

---

### nisckfix1 — Fix checksum (correction-value strategy)

Rewrites the three correction u32 values that bring the ROM checksum into
agreement. Use when the checksum block address is known.

```
nisckfix1 <&cks_s> <&cks_x> <&corrections> <in_file> [<out_file>]
```

All address arguments are file offsets in hex. If `out_file` is omitted,
output goes to `temp.bin`.

**Example:**

```
nisckfix1 757c 7574 0xbfff4 patched.bin fixed.bin
```

**AI notes:**
- Use `nisrom rom.bin` to get `&std_s` and `&std_x` before calling nisckfix.
- `nisckfix1` takes three address arguments; `nisckfix2` takes two (no `&corrections`).
- All addresses are **file offsets** — not hardware VAs.
- If `out_file` is omitted, output goes to `temp.bin`. Never let `temp.bin`
  accumulate in a directory with original ROM files.

---

### nisckfix2 — Fix checksum (rewrite-values strategy)

Alternative checksum fix that directly overwrites the checksum storage
locations rather than adjusting correction values.

```
nisckfix2 <&cks_s> <&cks_x> <in_file> [<out_file>]
```

**Example:**

```
nisckfix2 757c 7574 patched.bin fixed.bin
```

---

### nisdec1 — Decrypt ROM / data file

Decrypt a file using the Nissan NPT_DDL algorithm.

```
nisdec1 <scode> <in_file> [<out_file>]
```

`scode` is a uint32 hex value (the seed/key).

**Example:**

```
nisdec1 55AA00FF encrypted.bin decrypted.bin
```

---

### nisenc1 — Encrypt ROM / data file

Encrypt a file using Nissan Algo 01.

```
nisenc1 <scode> <in_file> [<out_file>]
```

**Example:**

```
nisenc1 55AA00FF plain.bin encrypted.bin
```

---

### nisguess — Derive key from known enc/dec pair

List possible keys that encode a given pair of uint32 values. Useful when
you have one known plaintext/ciphertext pair.

```
nisguess <enc> <dec>
```

Both arguments are uint32 hex values.

**AI notes:**
- `nisguess` / `nisguess2` are brute-force tools — runtime scales with key
  space. They require at least one known plaintext/ciphertext pair.
- If the ROM is available, run `nisrom rom.bin` first — it may extract s27k/s36k
  directly from the binary without needing nisguess.

---

### nisguess2 — Guess key from enc/dec file pair

Attempt to derive the Nissan encryption key from a pair of encrypted and
decrypted files.

```
nisguess2 <enc_file> <dec_file>
```

---

### findcallargs — Find function calls by r4 argument

Scan a SH2 ROM binary for calls to a target function where register r4
holds a specific value. Useful for tracing how a function is invoked.

```
findcallargs <tgt> <r4val> <in_file>
```

**Example:**

```
findcallargs 0x56738 0x66 rom.bin
```

**AI notes:**
- All addresses passed to `findcallargs` and `findrefs` are **file offsets**,
  not hardware VAs. Ghidra loads at base 0x0 so VA = file offset in that
  project, but hardware ROM base is 0xFFFC0000. Always confirm which address
  space you are working in before passing a value.

---

### findrefs — Find memory accesses to an address

Scan a SH2 ROM binary for instructions that read or write a specific
address. Useful for tracking down what code touches a known register or
memory location.

```
findrefs <in_file> <tgt> [<minbase>]
```

`minbase` filters out accesses below a base address (e.g. to skip ROM
self-references and focus on peripheral I/O).

**Example:**

```
findrefs rom.bin 0xffff40ff 0xffff4000
```

---

### unpackdat — Unpack Nissan .dat payload

Unpack a Nissan `.dat` firmware file, extracting the embedded payload.

```
unpackdat <file.dat> <out.dat>
```

---

## romdb — Keyset database

`romdb/keysets.csv` is a CSV of known Nissan keysets (ECUID → s27k, s36k1,
s36k2). `nisrom` uses this database automatically when querying keys.

To look up keys manually, inspect `keysets.csv` directly or grep for the
ECUID prefix:

```
grep 6S710 romdb/keysets.csv
```

**AI notes:**
- There is no `keyset_lookup.py` script in nissutils. Keys are found either
  by `nisrom` (code analysis of the ROM) or by grepping `keysets.csv` directly.
- If a keyset is not in `keysets.csv` and `nisrom` cannot derive it, the keys
  must be found through other means (hardware extraction or algorithm analysis).

---

## ghidra_helpers — Ghidra ROM loader

`ghidra_helpers/nissan_load.py` is a Ghidra script that auto-configures a
Ghidra project for Nissan SH-series ECU ROMs:

- Defines memory regions and interrupt vectors (IVT)
- Labels IO peripheral registers from included CSV files
- Supports SH7050, SH7051, SH7052, SH7055, SH7058, SH7059

To use: open Script Manager in Ghidra, add the `ghidra_helpers/` directory,
and run `nissan_load.py` immediately after importing the ROM binary.

**Supported variants:** `ivt_7050.csv`, `ivt_7055.csv`, `regs_7055_180.csv`,
`regs_7055_350.csv`, `regs_7058.csv` — pick the variant matching your ECU.
