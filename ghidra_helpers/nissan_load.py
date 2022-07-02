# (c) 2022 fenugrec
# GPLv3
#
# Nissan SuperH ROM initializer
#
# Preferably run this immediately after importing the ROM dump, before running auto-analysis or doing any work.
#
# TODO : range check before creating mem blocks ? or catch exception ?
# TODO : operation mode selection is fugly fragile code
#
# @category: Nissan

import csv
import os	#for os.path.join
import collections
devtype = collections.namedtuple('CPU',
	['cpustring', 'RAMstart', 'RAMsize', 'IOstart', 'IOsize', 'vectlist_file', 'regs_csv'])

# These are basic definitions for the purpose of mem and IO areas
# IVT (primary and secondary) are separately treated according to fidtype
# IO regs : 7058S adds only a few regs to 7058. The csv file contains the full set
devlist = [
	devtype("7050", 0xffffe800, 0x1800, 0xffff8000, 0x800, "ivt_7050.csv", "regs_7050.csv"),	#typo in DS
	devtype("7051", 0xffffd800, 0x2800, 0xffff8000, 0x800, "ivt_7050.csv", "regs_7050.csv"),
	devtype("7052", 0xffff8000, 0x3000, 0xffffe000, 0x2000, "ivt_7052.csv", "regs_7052.csv"),
	devtype("7054", 0xffff8000, 0x4000, 0xffffe000, 0x2000, "ivt_7052.csv", "regs_7052.csv"),
	devtype("7055_350", 0xffff6000, 0x8000, 0xffffe000, 0x2000, "ivt_7055.csv", "regs_7055_350.csv"),
	devtype("7055_180", 0xffff6000, 0x8000, 0xffffe000, 0x2000, "ivt_7055.csv", "regs_7055_180.csv"),
	devtype("7058", 0xffff0000, 0xc000, 0xffffc000, 0x4000, "ivt_7055.csv", "regs_7058.csv"),	#almost identical to 7058S
	devtype("7059", 0xfffe8000, 0x14000, 0xffffc000, 0x4000, "ivt_7059.csv", "regs_7059.csv"),	#typo in DS
	devtype("72531", 0xfff80000, 0x10000, 0xfffc0000, 0x40000, "ivt_7253.csv", "regs_7253.csv"),
	devtype("72533", 0xfff80000, 0x18000, 0xfffc0000, 0x40000, "ivt_7253.csv", "regs_7253.csv")
	]


fidtype = collections.namedtuple('fidtype', ['fidstring', 'cpustring', 'IVT2_addr'])

# Source for this data is nissan_romdefs.c;
# the actual vectors are stored in separate files. 7055 and 7058 have identical vector tables
fidlist = [
	fidtype("SH705101", "7050", None),
	fidtype("SH705415", "7054", None),
	fidtype("SH705507", "7055_350", None),
	fidtype("SH705513", "7055_350", 0x1000),
	fidtype("SH705519", "7055_180", 0x10004),
	fidtype("SH705520", "7055_180", 0x1000),
	fidtype("SH705821", "7055", 0x1000),
	fidtype("SH705822", "7055", 0x20004),
	fidtype("SH705823", "7055", 0x2000),
	fidtype("SH705828", "7055", 0x20004),
	fidtype("SH705927", "7055", 0x20004),
	fidtype("S7253331", "7055", 0x70004),
	fidtype("S7253332", "7055", 0x70004),
	fidtype("S7254332", "7055", 0x70004),
	]


#create RAM and IO areas. device_base is a namedtuple
def create_memblocks(device_base):
	if not askYesNo("Nissan: SH7xxx memory areas", "create + setup memory regions ?"):
		return

	# set initial ROM mem block (containing address 0) to readonly
	block = getMemoryBlock(toAddr(0))
	block.setPermissions(1,0,1)
	block.setName("ROM")

	print "Setting memory areas for ", device_base.cpustring

	# create RAM mem block : uninitialized, RW
	createMemoryBlock("RAM", toAddr(device_base.RAMstart), None, device_base.RAMsize, 0)

	# create IO mem block : uninit, RW and volatile
	ioblock = createMemoryBlock("IO", toAddr(device_base.IOstart), None, device_base.IOsize, 0)
	ioblock.setPermissions(1,1,0)
	ioblock.setVolatile(1)


# return a devtype namedtuple for given CPU string e.g. "7055"
def get_devicetype(cpustring):
	return next((x for x in devlist if x.cpustring == cpustring), None)

# return a fidtype namedtuple for given FID string eg "SH705513"
def get_fidtype(fidstring):
	return next((x for x in fidlist if x.fidstring == fidstring), None)


#return a fidtype namedtuple
def prompt_fid():
	return askChoice("FIDtype selection", "Select CPU code (for int vectors)", fidlist, fidlist[0])

#find FID CPU string (or ask user selection if not found), return a fidtype namedtuple
def find_fid():
	block = getMemoryBlock(toAddr(0))

	#search backwards ! idea is to find latest occurence, to skip the LOADERxx struct if present.

	#incomprehensibly failed attempt:
	#findBytes(block.getEnd(), block.getStart(), bytes("DATABASE"), None)	# TypeError: findBytes(): 1st arg can't be coerced to ghidra.program.model.address.Address,

	fid_pos = currentProgram.getMemory().findBytes(block.getEnd(), bytes("DATABASE"), None, 0, monitor)
	if fid_pos:
		print "found DATABASE string at", fid_pos
		#SHxxxxyy string is 13 bytes later. Change my mind
		cpustring_pos = fid_pos.addNoWrap(13)
		cpustring = getBytes(cpustring_pos, 8).tostring()
		return get_fidtype(cpustring)

	print "could not determine FID type automatically."
	return prompt_fid()


def create_one_vector(label, addr, comment):
	tmp_addr = toAddr(addr)
	from ghidra.program.model.data import PointerDataType

	createData(tmp_addr, PointerDataType())
	setEOLComment(tmp_addr, comment)
	handler_addr = getDataAt(tmp_addr).getValue()
	createFunction(handler_addr, label)


#open vector definitions file and create vector tables
#if ivt2_offset is specified, produce a dual IVT (Nissan)
def create_vectors(devtype_base, ivt2_offset):
	if not askYesNo("Nissan: SH7xxx interrupt vectors", "create + setup Interrupt vectors ?"):
		return

	#for some reason the "current directory" for open() is not the script's location.
	script_location = os.path.dirname(sourceFile.getAbsolutePath())
	csv_filename = os.path.join(script_location, devtype_base.vectlist_file)

	with open(csv_filename, 'rb') as f:
		reader = csv.DictReader(f)
		for row in reader:
			vect_addr = int(row['vect_offs'], base=16)
			vect_label = row['vect_label']

			# if there's a secondary IVT:
			# - create duplicate entries for the first 0x100 bytes
			# - truncate primary IVT to 0x100
			if ivt2_offset:
				alt_label = "alt_" + vect_label
				create_one_vector(alt_label, ivt2_offset + vect_addr, row['comment'])
				if vect_addr < 0x100:
					create_one_vector(vect_label, vect_addr, row['comment'])
			else:
				# if no IVT2 : create complete primary IVT at 0x00000000
				create_one_vector(vect_label, vect_addr, row['comment'])


def mode_basic():
	device_base = askChoice("CPU memory blocks", "Select device type", devlist, devlist[0])
	create_memblocks(device_base)
	create_vectors(device_base, None)

def mode_semi():
	fidtype = prompt_fid()
	devtype_base = get_devicetype(fidtype.cpustring)
	create_memblocks(devtype_base)
	create_vectors(devtype_base, fidtype.IVT2_addr)

def mode_auto():
	fidtype = find_fid()
	devtype_base = get_devicetype(fidtype.cpustring)
	create_memblocks(devtype_base)
	create_vectors(devtype_base, fidtype.IVT2_addr)

def main():
	#Operation modes :
	# full magic finds the FID cpu string (e.g. "SH705513") and defines everything based on that.
	# semi-magic finds the FID cpu string but allows some changes
	# basic is basic

	#Surely there's a better way to do this
	opmodes = [
		"Full-auto magic (Nissan only)",
		"Semi-magic (Nissan only)",
		"Basic (bare SH7xxx)"
	]
	opmode_string = askChoice("Nissan ROM loader", "Select operation mode", opmodes, opmodes[0])
	op_idx = opmodes.index(opmode_string)
	if op_idx == 0:
		mode_auto()
	elif op_idx == 1:
		mode_semi()
	elif op_idx == 2:
		mode_basic()



# Report progress to the GUI.  Do this in all script loops!
#import time
#monitor.initialize(10)
#for i in range(10):
#monitor.checkCanceled() # check to see if the user clicked cancel
#    time.sleep(1) # pause a bit so we can see progress
#    monitor.incrementProgress(1) # update the progress
#    monitor.setMessage("Working on " + str(i)) # update the status message

if __name__ == "__main__":
  main()