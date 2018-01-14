.PHONY=all clean emulation

INCLUDE_DIR=header/

all:
	-mkdir build
	nasm -f bin -o build/bootloader src/bootloader.asm
	cat build/bootloader /dev/zero | dd of=build/disk-image bs=512 count=2880



build/video.o:
		gcc -o build/video.o -c src/video.c

build/kernel.o:
	gcc -I ${INCLUDE_DIR} -o build/kernel.o -c src/kernel.c

build/kernel: build/kernel.o
	nasm -f elf32 -o build/kernelasm.o src/kernel.asm
	ld build/video.o build/kernel.o build/kernelasm.o -o build/kernel


clean:
	-rm build/*

emulation:
	qemu-system-x86_64 --hda build/disk-image
