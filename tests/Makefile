#modify this to fit the prefix of the gcc toolchain binaries. i.e.
#if gcc is installed as "sh4-none-elf-gcc", then PREFIX should be sh4-none-elf
PREFIX=sh-elf

#DBGFLAGS=-gdwarf-2

# Specify compiler to be used
CC = $(PREFIX)-gcc

# Specify Assembler to be used
#AS = $(PREFIX)-as
AS   = $(PREFIX)-gcc -x assembler-with-cpp

CP   = $(PREFIX)-objcopy
SIZE = $(PREFIX)-size
BIN  = $(CP) -O binary -S

# Specify linker to be used
LD = $(PREFIX)-ld

# Specify CPU flag
CPU = -m2e -mb

# Common compiler flags
#OPT = -Os
OPT = -Os -ffunction-sections



PROJECT = testrom

#-specs=nano.specs

ASFLAGS = $(CPU) $(DBGFLAGS) -nostartfiles -Wa,-amhls=$(<:.s=.lst) $(E_ASFLAGS)
CPFLAGS = $(CPU) $(DBGFLAGS) $(OPT) -fomit-frame-pointer -std=gnu99 -Wall -Wextra -Wstrict-prototypes \
	-fstack-usage -fverbose-asm -Wa,-ahlms=$(<:.c=.lst) $(E_CFLAGS)

LDFLAGS = $(CPU) -nostartfiles -T$(LDSCRIPT) -Wl,-Map=$(PROJECT).map,--cref

LDSCRIPT = lkr_7055.ld


ASRC = test1.s

# SRC = main.c

OBJS  = $(ASRC:.s=.o) $(SRC:.c=.o)

all: $(OBJS) $(PROJECT).elf $(PROJECT).bin
	$(SIZE) $(PROJECT).elf


%.o: %.c
	$(CC) -c $(CPFLAGS) -I . $< -o $@

%.o: %.s
	$(AS) -c $(ASFLAGS) $< -o $@

%elf: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

%bin: %elf
	$(BIN)  $< $@

.PHONY : clean
clean:
	-rm -f $(OBJS)
	-rm -f $(SRC:.c=.su)
	-rm -f  $(PROJECT).elf
	-rm -f  $(PROJECT).map
	-rm -f  $(PROJECT).bin
	-rm -f  $(SRC:.c=.c.bak)
	-rm -f  $(SRC:.c=.lst)
	-rm -f  $(ASRC:.s=.s.bak)
	-rm -f  $(ASRC:.s=.lst)
