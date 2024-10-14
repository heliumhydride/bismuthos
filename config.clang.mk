CROSS_COMPILE = i486-elf
AS = nasm
CC = clang --target=$(CROSS_COMPILE) -fuse-ld=lld
LD = $(CC)
QEMU = qemu-system-i386

ASFLAGS = -Ox -Wx
CFLAGS = -Os -std=c99 -Wall -Wextra -Wpedantic
LDFLAGS = $(CFLAGS)
QEMU_FLAGS = -M pc -m 32M -cpu 486 -initrd initrd.img -append "bootparam_here"
O = boot.sys
INITRD_O = initrd.img
