# Nissan SuperH ROM initializer
#
# (c) 2022 fenugrec
# GPLv3
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
	devtype("7059", 0xfffe8000, 0x14000, 0xffffc000, 0x4000, "ivt_7055.csv", "regs_7058.csv"),	#typo in DS
	devtype("72531", 0xfff80000, 0x10000, 0xfffc0000, 0x40000, "ivt_7253.csv", "regs_7253.csv"),
	devtype("72533", 0xfff80000, 0x18000, 0xfffc0000, 0x40000, "ivt_7253.csv", "regs_7253.csv")
	]


fidtype = collections.namedtuple('fidtype', ['fidstring', 'cpustring', 'IVT2_addr'])

# Source for this data is nissan_romdefs.c;
# the actual vectors are stored in separate files. 7055 and 7058 have identical vector tables
fidlist = [
	fidtype("SH705101", "7050", None),
	fidtype("SH705415", "7054", 0x1000),
	fidtype("SH705507", "7055_350", None),
	fidtype("SH705513", "7055_350", 0x1000),
	fidtype("SH705519", "7055_180", 0x10004),
	fidtype("SH705520", "7055_180", 0x1000),
	fidtype("SH705821", "7058", 0x1000),
	fidtype("SH705822", "7058", 0x20004),
	fidtype("SH705823", "7058", 0x2000),
	fidtype("SH705828", "7058", 0x20004),
	fidtype("SH705927", "7059", 0x20004),
	fidtype("S7253331", "72533", 0x70004),
	fidtype("S7253332", "72533", 0x70004),
#	fidtype("S7254332", "72543", 0x70004),
	]


#create RAM and IO areas. device_base is a namedtuple
def create_memblocks(device_base):
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


#find FID CPU string (or ask user selection if not found), return a fidtype namedtuple
def find_fid():
	block = getMemoryBlock(toAddr(0))

	#search backwards ! idea is to find latest occurence, to skip the LOADERxx struct if present.

	#incomprehensibly failed attempt:
	#findBytes(block.getEnd(), block.getStart(), bytes("DATABASE"), None)	# TypeError: findBytes(): 1st arg can't be coerced to ghidra.program.model.address.Address,

	fid_pos = currentProgram.getMemory().findBytes(block.getEnd(), bytes("DATABASE"), None, 0, monitor)
	fidtype = None
	if fid_pos:
		print "found DATABASE string at", fid_pos
		#SHxxxxyy string is 13 bytes later. Change my mind
		cpustring_pos = fid_pos.addNoWrap(13)
		cpustring = getBytes(cpustring_pos, 8).tostring()
		fidtype = get_fidtype(cpustring)

	if not fidtype:
		return askChoice("Nissan: FID type", "Could not detect FID type. Select one: ", fidlist, fidlist[0])
	else:
		return askChoice("Nissan: FID type", "Detected " + fidtype.fidstring + " . Change if desired ",
			fidlist, next(x for x in fidlist if x.cpustring == fidtype.cpustring))


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


# define peripheral regs
def create_ioregs(devtype_base):
	#for some reason the "current directory" for open() is not the script's location.
	script_location = os.path.dirname(sourceFile.getAbsolutePath())
	csv_filename = os.path.join(script_location, devtype_base.regs_csv)

	with open(csv_filename, 'rb') as f:
		reader = csv.DictReader(f)
		for row in reader:
			reg_name = row['reg_name']
			#print reg_name, row['reg_addr']
			reg_addr = int(row['reg_addr'], base=16)
			# create as Primary label
			createLabel(toAddr(reg_addr), reg_name, 1)

# niceness : offer to not create everything. Useful for partially-defined projects
def create_all(devtype_base, IVT2):
	enabled_ops = askChoices("Select operations", "The script will now create/define the following:",
		[ 1, 2, 3 ], ["Mem regions", "Interrupt vectors (+ IVT2 if applicable)", "MMIO peripheral registers"])
	if 1 in enabled_ops:
		create_memblocks(devtype_base)
	if 2 in enabled_ops:
		create_vectors(devtype_base, IVT2)
	if 3 in enabled_ops:
		create_ioregs(devtype_base)

def mode_basic():
	device_base = askChoice("CPU memory blocks", "Select device type", devlist, devlist[0])
	create_all(device_base, None)

def mode_nissan():
	fidtype = find_fid()
	devtype_base = get_devicetype(fidtype.cpustring)
	create_all(devtype_base, fidtype.IVT2_addr)

def main():
	#Operation modes :
	# Nissan finds the FID cpu string (e.g. "SH705513") and defines everything based on that.
	# basic is basic

	#Surely there's a better way to do this
	opmodes = [
		"Nissan (detect or choose FID CPU type)",
		"Basic (bare SH7xxx)"
	]
	opmode_string = askChoice("Nissan ROM loader", "Select operation mode", opmodes, opmodes[0])
	op_idx = opmodes.index(opmode_string)
	if op_idx == 0:
		mode_nissan()
	elif op_idx == 1:
		mode_basic()



if __name__ == "__main__":
  main()
