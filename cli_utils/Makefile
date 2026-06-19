CC = gcc
CFLAGS = -std=gnu99 -Wall -Wextra -O3 -ggdb -Wno-implicit-function-declaration

TGTLIST = test_ecuidlist nisckfix1 nisckfix2 nisdec1 nisenc1
TGTLIST += nisguess nisguess2 nisrom unpackdat
TGTLIST += findrefs findcallargs test_findcks test_romdb

all: $(TGTLIST)

nisckfix1: nisckfix1.c nislib.c nislib_shtools.c nisrom_finders.c

nisckfix2: nisckfix2.c nislib.c nislib_shtools.c nisrom_finders.c

nisdec1: nisdec1.c nislib.c nislib_shtools.c nisrom_finders.c

nisenc1: nisenc1.c nislib.c nislib_shtools.c nisrom_finders.c

nisguess: nisguess.c nislib.c nislib_shtools.c nisrom_finders.c

nisguess2: nisguess2.c nislib.c nislib_shtools.c nisrom_finders.c

nisrom: nisrom.c nislib.c nislib_shtools.c nisrom_finders.c nisrom_keyfinders.c nissan_romdefs.c nis_romdb.c libcsv/libcsv.c md5/md5.c

unpackdat: unpackdat.c nislib.c nislib_shtools.c nisrom_finders.c

test_ecuidlist: test_ecuidlist.c ecuid_list.c

findrefs: findrefs.c nislib.c nislib_shtools.c nisrom_finders.c

findcallargs: findcallargs.c nislib.c nislib_shtools.c nisrom_finders.c

test_findcks: test_findcks.c nislib.c nislib_shtools.c nisrom_finders.c

test_romdb: test_romdb.c nislib.c nislib_shtools.c nisrom_finders.c nis_romdb.c nissan_romdefs.c libcsv/libcsv.c
