AS = nasm
CC = gcc
LD = ld
ASFLAGS = -f elf32
CFLAGS = -m32 -ffreestanding -Wall -Wextra
LDFLAGS = -m elf_i386 -T linker.ld

BOOTLOADER_SRC = bootloader/boot.asm bootloader/bootloader.c
KERNEL_SRC = kernel/kernel.c kernel/idt.c
BOOTLOADER_OBJ = $(BOOTLOADER_SRC:.asm=.o)
KERNEL_OBJ = $(KERNEL_SRC:.c=.o)

all: bootloader kernel

bootloader: $(BOOTLOADER_OBJ)
    $(LD) $(LDFLAGS) -o build/bootloader.bin $(BOOTLOADER_OBJ)
    dd if=/dev/zero of=build/bootloader.img bs=512 count=2880
    dd if=build/bootloader.bin of=build/bootloader.img conv=notrunc

kernel: $(KERNEL_OBJ)
    $(LD) $(LDFLAGS) -o build/kernel.bin $(KERNEL_OBJ)

%.o: %.asm
    $(AS) $(ASFLAGS) -o $@ $<

%.o: %.c
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -f $(BOOTLOADER_OBJ) $(KERNEL_OBJ) build/*.bin build/*.img
