# BismuthOS

My unix-like toy operating system

PLEASE never consider usage for production (even when you will be able to boot)

## Building

### requirements
* c compiler: [gcc compiler](https://gcc.gnu.org/) (clang and tcc don't work yet)
* assembler: [nasm assembler](https://nasm.us/)
* [gnu make](https://www.gnu.org/software/make/)
* linker: [binutils ld](https://www.gnu.org/software/binutils/) (i plan to support [mold](https://github.com/rui314/mold) and [llvm linker](https://lld.llvm.org/))

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
NOTE: you need to install [qemu](https://www.qemu.org/)

### debugging
* add `-g3` to `CFLAGS` and `LDFLAGS` in `config.mk`
* add `-g` to `ASFLAGS` in `config.mk`
* add `-s -S` to `QEMU_FLAGS` in `config.mk`
