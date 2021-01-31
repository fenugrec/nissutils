CC = gcc
CFLAGS = -std=gnu99 -Wall -Wextra -Wpedantic -O2

TGTLIST = test_ecuidlist nisckfix1 nisckfix2 nisdec1 nisenc1
TGTLIST += nisguess nisguess2 nisrom unpackdat
TGTLIST += findrefs findcallargs test_findcks

all: $(TGTLIST)

nisckfix1: nisckfix1.c nislib.c

nisckfix2: nisckfix2.c nislib.c

nisdec1: nisdec1.c nislib.c

nisenc1: nisenc1.c nislib.c

nisguess: nisguess.c nislib.c

nisguess2: nisguess2.c nislib.c

nisrom: nisrom.c nislib.c

unpackdat: unpackdat.c nislib.c

test_ecuidlist: test_ecuidlist.c ecuid_list.c

findrefs: findrefs.c nislib.c

findcallargs: findcallargs.c nislib.c

test_findcks: test_findcks.c nislib.c

