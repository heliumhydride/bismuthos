# BismuthOS

My unix-like toy operating system

PLEASE never consider usage for production (even when you will be able to boot)

## Building

### requirements
* **i486-elf** targetting c compiler: see [osdev wiki](http://wiki.osdev.org/GCC_Cross-Compiler) (i can't get clang or tcc to work yet) (note: i586 and i686 can also be used)
* assembler: [nasm assembler](https://nasm.us/)
* [gnu make](https://www.gnu.org/software/make/)
* linker: [binutils ld](https://www.gnu.org/software/binutils/) (i plan to support [mold](https://github.com/rui314/mold) and [llvm linker](https://lld.llvm.org/))

nice to have:
* emulator: [qemu](https://www.qemu.org/)
* code checking tool: [cppcheck](https://cppcheck.sourceforge.io/), run `make check` or `scripts/check.sh`
* debugger: [gdb](https://www.sourceware.org/gdb/) or [lldb](https://lldb.llvm.org/)

### configuring
Create the config file:
```sh
make config.h
```
And edit config.h to your needs

### compiling
```sh
make
```

or to build just the kernel
```sh
make boot.sys
```

### running
```sh
make run
```

### debugging
change some compilation settings first:
* add `-g3` to `CFLAGS` and `LDFLAGS` in `config.mk`
* add `-g` to `ASFLAGS` in `config.mk`
* add `-s -S` to `QEMU_FLAGS` in `config.mk`

start debugging using **gdb**:
```sh
$ gdb boot.sys
...
(gdb) target remote :1234
```

start debugging using **lldb**:
```sh
$ lldb boot.sys
...
(lldb) target create boot.sys
(lldb) gdb-remote localhost:1234
```
