Simple UNIX-like and Windows NT-like OS

build requirements:
* make -> gnu make
* as   -> nasm
* cc   -> gcc / tcc / clang
* ld   -> binutils / mold / lld
* tar  -> bsdtar / gnu tar / paxmirabilis (initrd creation)

build nice-to-haves:
* qemu for testing the OS
* debugger -> gdb / lldb
* dosfstools (for creating bootable disk image)

debugging:
* add -g3 to CFLAGS and LDFLAGS in config.mk
* add -g to ASFLAGS in config.mk
* add -s -S to QEMU_FLAGS in config.mk
