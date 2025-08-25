#include config.clang.mk
include config.mk

asflags_private = -felf32 $(ASFLAGS)
cflags_private = -ffreestanding $(CFLAGS)
ldflags_private = -ffreestanding -T kernel/linker.ld -nostdlib $(LDFLAGS)
#ldflags_private = -ffreestanding -Wl,-Ttext=0x100000 -nostdlib $(LDFLAGS)

OBJS = kernel/boot.o kernel/kernel.o libk/libk.o video/vgaterm.o io/io.o

all: config.h $(O) $(INITRD_O)

run: all
	$(QEMU) $(QEMU_FLAGS) -kernel $(O)

$(O): $(OBJS)
	$(LD) $(ldflags_private) -o $(O) $(OBJS)

kernel/boot.o: kernel/boot.asm
	$(AS) $(asflags_private) -o kernel/boot.o kernel/boot.asm

kernel/kernel.o: kernel/kernel.c
	$(CC) $(cflags_private) -c -o kernel/kernel.o kernel/kernel.c

libk/libk.o: libk/libk.c
	$(CC) $(cflags_private) -c -o libk/libk.o libk/libk.c

# Old video driver, not compiled normally
video/video.o: video/video.c
	$(CC) $(cflags_private) -c -o video/video.o video/video.c

video/vgaterm.o: video/vgaterm.c
	$(CC) $(cflags_private) -c -o video/vgaterm.o video/vgaterm.c

io/io.o: io/io.c
	$(CC) $(cflags_private) -c -o io/io.o io/io.c

$(INITRD_O):
	echo "INITRD STARTS HERE!!" > $(INITRD_O) 

config.h:
	cp config.def.h config.h

clean:
	rm -f $(O) $(INITRD_O)
	rm -f $(OBJS)

check:
	./scripts/check.sh

.PHONY: clean run check
