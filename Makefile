

SOURCES=boot.o main.o  display_adapter.o legacy_vga_adapter.o logging.o memory_operations.o asm.o modules.o

CFLAGS=-m32 -Wall -nostdlib -nostdinc -fno-builtin -fno-stack-protector -I ./include
LDFLAGS=-Tlink.ld -m elf_i386
ASFLAGS=-felf

run:all

all: clean $(SOURCES) link update
	objdump -d kernel >kernel.dump
clean:
	-rm -f *.o kernel kernel.dump
	-umount /dev/loop0
	-losetup -d /dev/loop0

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.SUFFIXES: .asm .o
.asm.o:
	nasm $(ASFLAGS) $<
run:
	losetup /dev/loop0 floppy.img
	-bochs -q -rc bochsdbg.rc
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


