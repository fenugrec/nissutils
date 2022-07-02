# (c) 2022 fenugrec
# GPLv3
#
# Nissan SuperH ROM initializer
#
# Preferably run this immediately after importing the ROM dump, before running auto-analysis or doing any work.
#
# TODO : range check before creating mem blocks ? or catch exception ?
#
# @category: Nissan

import csv
import os	#for os.path.join
import collections
devtype = collections.namedtuple('CPU',['cpustring', 'RAMstart', 'RAMsize', 'IOstart', 'IOsize'])

# These are basic definitions for the purpose of mem and IO areas
# IVT (primary and secondary) need separate treatment
devlist = [
	devtype("7050", 0xffffe800, 0x1800, 0xffff8000, 0x800),	#typo in DS
	devtype("7051", 0xffffd800, 0x2800, 0xffff8000, 0x800),
	devtype("7052", 0xffff8000, 0x3000, 0xffffe000, 0x2000),
	devtype("7054", 0xffff8000, 0x4000, 0xffffe000, 0x2000),
	devtype("7055", 0xffff6000, 0x8000, 0xffffe000, 0x2000),
	devtype("7058", 0xffff0000, 0xc000, 0xffffc000, 0x4000),	#same for 7058S
	devtype("7059", 0xfffe8000, 0x14000, 0xffffc000, 0x4000),	#typo in DS
	devtype("72531", 0xfff80000, 0x10000, 0xfffc0000, 0x40000),
	devtype("72533", 0xfff80000, 0x18000, 0xfffc0000, 0x40000)
	]



fidtype = collections.namedtuple('fidtype', ['fidstring', 'vectlist_file', 'IVT2_addr'])

# Source for this data is nissan_romdefs.c;
# the actual vectors are stored in separate files. 7055 and 7058 have identical vector tables
fidlist = [
	fidtype("SH705101", "ivt_7050.csv", None),
	fidtype("SH705415", "ivt_7052.csv", None),
	fidtype("SH705507", "ivt_7055.csv", None),
	fidtype("7058_basic", "ivt_7055.csv", None),	#generic single-IVT variant
	fidtype("7059_basic", "ivt_7059.csv", None),	#generic single-IVT variant
	fidtype("SH705513", "ivt_7055.csv", 0x1000),
	fidtype("SH705519", "ivt_7055.csv", 0x10004),
	fidtype("SH705520", "ivt_7055.csv", 0x1000),
	fidtype("SH705821", "ivt_7055.csv", 0x1000),
	fidtype("SH705822", "ivt_7055.csv", 0x20004),
	fidtype("SH705823", "ivt_7055.csv", 0x2000),
	fidtype("SH705828", "ivt_7055.csv", 0x20004),
	fidtype("SH705927", "ivt_7059.csv", 0x20004),
	fidtype("S7253331", "ivt_7253.csv", 0x70004),
	fidtype("S7253332", "ivt_7253.csv", 0x70004),
	fidtype("S7254332", "ivt_7253.csv", 0x70004),
	]


#create RAM and IO blocks
def create_memblocks():
	device_base = askChoice("MCU selection", "Select device type (for mem areas)", devlist, devlist[0])

	print "Setting memory areas for ", device_base.cpustring

	# create RAM mem block : uninitialized, RW
	createMemoryBlock("RAM", toAddr(device_base.RAMstart), None, device_base.RAMsize, 0)

	# create IO mem block : uninit, RW and volatile
	ioblock = createMemoryBlock("IO", toAddr(device_base.IOstart), None, device_base.IOsize, 0)
	ioblock.setPermissions(1,1,0)
	ioblock.setVolatile(1)



#find FID CPU string (or ask user selection if not found), return a fidtype namedtuple
def find_fid():
	block = getMemoryBlock(toAddr(0))

	#search backwards ! idea is to find latest occurence, to skip the LOADERxx struct if present.

	#incomprehensibly failed attempts:
	#findBytes(block.end, block.start, bytes("DATABASE"), None) #TypeError: toAddr(): 1st arg can't be coerced to long, int, String
	#findBytes(toAddr(block.end), toAddr(block.start), bytes("DATABASE"), None)	# 1st arg can't be coerced to ghidra.program.model.address.Address,
	#findBytes(block.getEnd(), block.getStart(), bytes("DATABASE"), None)	# TypeError: findBytes(): 1st arg can't be coerced to ghidra.program.model.address.Address,

	detected_fidtype = None
	fid_pos = currentProgram.getMemory().findBytes(block.getEnd(), bytes("DATABASE"), None, 0, monitor)
	if fid_pos:
		print "found DATABASE string at", fid_pos
		#SHxxxxyy string is 13 bytes later. Change my mind
		cpustring_pos = fid_pos.addNoWrap(13)
		cpustring = getBytes(cpustring_pos, 8).tostring()
		
		detected_fidtype = next((x for x in fidlist if x.fidstring == cpustring), None)

	if not detected_fidtype:
		print "could not determine FID type automatically."
		detected_fidtype = askChoice("FIDtype selection", "Select CPU code (for int vectors)", fidlist, fidlist[0])
	print "FID type is: ", detected_fidtype.fidstring
	return detected_fidtype


def create_one_vector(label, addr, comment):
	tmp_addr = toAddr(addr)
	from ghidra.program.model.data import PointerDataType

	createData(tmp_addr, PointerDataType())
	setEOLComment(tmp_addr, comment)
	handler_addr = getDataAt(tmp_addr).getValue()
	# don't create as Primary label, otherwise the default vector (POR) gets overwritten
	createLabel(handler_addr, label, 0)


#open vector definitions file and create vector tables
def create_vectors(ft):
	#for some reason the "current directory" for open() is not the script's location.
	script_location = os.path.dirname(sourceFile.getAbsolutePath())
	csv_filename = os.path.join(script_location, ft.vectlist_file)

	with open(csv_filename, 'rb') as f:
		reader = csv.DictReader(f)
		for row in reader:
			vect_addr = int(row['vect_offs'], base=16)
			vect_label = row['vect_label']

			# if there's a secondary IVT:
			# - create duplicate entries for the first 0x100 bytes
			# - truncate primary IVT to 0x100
			if ft.IVT2_addr:
				alt_label = "alt_" + vect_label
				create_one_vector(alt_label, ft.IVT2_addr + vect_addr, row['comment'])
				if vect_addr < 0x100:
					create_one_vector(vect_label, vect_addr, row['comment'])
			else:
				# if no IVT2 : create complete primary IVT at 0x00000000
				create_one_vector(vect_label, vect_addr, row['comment'])



def main():
	if askYesNo("Nissan: SH7xxx memory areas", "create + setup memory regions ?"):
		# set initial ROM mem block (containing address 0) to readonly
		block = getMemoryBlock(toAddr(0))
		block.setPermissions(1,0,1)
		block.setName("ROM")

		create_memblocks()

	if askYesNo("Nissan: SH7xxx interrupt vectors", "create + setup Interrupt vectors ?"):
		create_vectors(find_fid())



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