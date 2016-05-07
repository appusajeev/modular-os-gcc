

SOURCES=boot.o main.o  display_adapter.o legacy_vga_adapter.o logging.o memory_operations.o asm.o modules.o

CFLAGS=-Wall -nostdlib -nostdinc -fno-builtin -fno-stack-protector -I ./include
LDFLAGS=-Tlink.ld
ASFLAGS=-felf

run:all

all: clean $(SOURCES) link update
	objdump -d kernel >kernel.dump
clean:
	-rm -f *.o kernel kernel.dump

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.SUFFIXES: .asm .o
.asm.o:
	nasm $(ASFLAGS) $<
run:
	losetup /dev/loop0 floppy.img
	../bochs-2.6.8/bochs -q
	losetup -d /dev/loop0
update:
	losetup /dev/loop0 floppy.img
	mount /dev/loop0 /mnt
	cp kernel /mnt/kernel
	umount /dev/loop0
	losetup -d /dev/loop0
	
d:
	losetup -d /dev/loop0
de:
	@sed -n "/interrupt/,+2 {p}" bochsout.txt
	@sed -n "/exception/,+2 {p}" bochsout.txt


