#define _XOPEN_SOURCE   600
#define _POSIX_C_SOURCE 200112L

#include "../include/libk.h"
#include "../include/video.h"
#include "../config.h" // for readability, already included by video.h

//void _kernel_init(int argc, char* argv[]) {
void _kernel_init(void) { // The question is does argc argv work on bare metal ? (yes i know i need to use my own bootloader for this)

  vt_clear(VGA_COLOR);
	printk("BismuthOS version " VERSION " (under contruction)\n", 0);

  printf("Very long string that must be at the very least, like bare minimum 80 characters long!\n\n");

  vt_line = 24;
  //vt_col  = 0;
  print_color("  --Under contruction--                                                          ", 0xF0);

  vt_line = 6;
  vt_col = 0;

  /*
  for(int i = 0; i < 80; i++)
    printf("terminal scrolling ?\n");
  */

  /*
    We do not know the fat32/tar initrd end, so we only define the begin ptr
    ... and assume every byte after exists (end or not)
    -- PS: size of initrd could be stored right before the begining of the initrd data ?
    note : 0x106010 is the default address when loading an initrd in qemu-system-i386
    and it will be used once a custom bootloader is made
  */
  uint8_t* initrd_begin = (uint8_t*)0x106010;

  char buf[33];
  itoa(*initrd_begin, buf, 10);
  printf(buf);
	__asm__ __volatile__("hlt");
}
