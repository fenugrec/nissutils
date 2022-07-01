# (c) 2022 fenugrec
# GPLv3
#
# Nissan SuperH ROM initializer
#
# Preferably run this immediately after importing the ROM dump, before running auto-analysis or doing any work.
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
	devtype("72533", 0xfff80000, 0x18000, 0xfffc0000, 0x40000)]
	

def create_memblocks():
	# TODO : get these values from table
	device_base = askChoice("MCU selection", "Select device type (for mem areas)", devlist, devlist[0])

	print "Setting memory areas for ", device_base.cpustring

	# create RAM mem block : uninitialized, RW
	createMemoryBlock("RAM", toAddr(device_base.RAMstart), None, device_base.RAMsize, 0)

	# create IO mem block : uninit, RW and volatile
	ioblock = createMemoryBlock("IO", toAddr(device_base.IOstart), None, device_base.IOsize, 0)
	ioblock.setPermissions(1,1,0)
	ioblock.setVolatile(1)


def main():
	# set initial ROM mem block (containing address 0) to readonly
	block = getMemoryBlock(toAddr(0))
	block.setPermissions(1,0,1)
	block.setName("ROM")

	create_memblocks()
	


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