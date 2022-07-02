# (c) 2022 fenugrec
# GPLv3
#
# Nissan SuperH ROM initializer
#
# Preferably run this immediately after importing the ROM dump, before running auto-analysis or doing any work.
#
# TODO : range check before creating mem blocks ? or catch exception ?
# TODO : fallback option if CPUstring isn't found
#
# @category: Nissan


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



fidtype = collections.namedtuple('fidtype', ['fidstring', 'IVT2_addr'])

# Source for this data is nissan_romdefs.c
fidlist = [
	fidtype("SH705507", None),
	fidtype("SH705513", 0x1000)
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



#find FID CPU string
def find_fid():
	block = getMemoryBlock(toAddr(0))

	#search backwards ! idea is to find latest occurence, to skip the LOADERxx struct if present.

	#incomprehensibly failed attempts:
	#findBytes(block.end, block.start, bytes("DATABASE"), None) #TypeError: toAddr(): 1st arg can't be coerced to long, int, String
	#findBytes(toAddr(block.end), toAddr(block.start), bytes("DATABASE"), None)	# 1st arg can't be coerced to ghidra.program.model.address.Address,
	#findBytes(block.getEnd(), block.getStart(), bytes("DATABASE"), None)	# TypeError: findBytes(): 1st arg can't be coerced to ghidra.program.model.address.Address,

	fid_pos = currentProgram.getMemory().findBytes(block.getEnd(), bytes("DATABASE"), None, 0, monitor)
	if not fid_pos:
		print "TODO: manual select"
		return
	else:
		print "found DATABASE string at", fid_pos
		#SHxxxxyy string is 13 bytes later. Change my mind
		cpustring_pos = fid_pos.addNoWrap(13)
		cpustring = getBytes(cpustring_pos, 8).tostring()
		#for detected_fidtype in fidlist if detected_fidtype.fidstring == cpustring
		detected_fidtype = next((x for x in fidlist if x.fidstring == cpustring), None)
		print "FID type is: ", detected_fidtype.fidstring


def main():
	# set initial ROM mem block (containing address 0) to readonly
	block = getMemoryBlock(toAddr(0))
	block.setPermissions(1,0,1)
	block.setName("ROM")

	create_memblocks()
	find_fid()
	


# Add a comment to the current program
#minAddress = currentProgram.getMinAddress()
#listing = currentProgram.getListing()
#codeUnit = listing.getCodeUnitAt(minAddress)
#codeUnit.setComment(codeUnit.PLATE_COMMENT, "This is an added comment!")


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