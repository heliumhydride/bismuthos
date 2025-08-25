#define _XOPEN_SOURCE   600
#define _POSIX_C_SOURCE 200112L

#include "../include/libk.h"
//#include "../include/video.h" // Old term driver
#include "../include/vgaterm.h"
#include "../config.h"

void _kernel_putkerninfo(const char* s, const uint32_t severity) {
  uint8_t oldcolor = console_color;

  int vflag = 1; // TODO implement verbose boot
  // 0 -> Log/Note; 1 -> Warning; 2 -> Error; 3 -> Kernel panic
  switch(severity) {
    case 0:
      console_color = KCOLOR_LOG;
      break;
    case 1:
      console_color = KCOLOR_WARN;
      break;
    case 2:
      console_color = KCOLOR_ERROR;
      break;
    case 3:
      console_color = KCOLOR_PANIC;
      break;
    default:
      console_color = KCOLOR_LOG;
      break;
  }

  if(severity > 0 || vflag)
    puts(s);

  set_console_color(oldcolor);
}

void _kernel_poweroff(void) {
  _kernel_putkerninfo("SYSTEM IS HALTING NOW!\n", 0);
	__asm__ __volatile__("hlt");
}

//void _kernel_init(int argc, char* argv[]) {
void _kernel_init(void) { // The question is does argc argv work on bare metal ? (yes i know i need to use my own bootloader for this)

  /*
  vt_clear(VGA_COLOR);
	printk("\nBismuthOS version " VERSION " (under contruction)\n", 0); // TODO it doesnt print unless i lower one line first

  printf("Very long string that must be at the very least, like bare minimum 80 characters long!\n\n");

  vt_line = 24;
  //vt_col  = 0;
  print_color("  --Under contruction--                                                          ", 0xF0);

  vt_line = 6;
  vt_col = 0;

  for(int i = 0; i < 80; i++)
    printf("terminal scrolling ?\n");

    We do not know the fat32/tar initrd end, so we only define the begin ptr
    ... and assume every byte after exists (end or not)
    -- PS: size of initrd could be stored right before the begining of the initrd data ?
    note : 0x106010 is the default address when loading an initrd in qemu-system-i386
    and it will be used once a custom bootloader is made

  uint8_t* initrd_begin = (uint8_t*)0x106010;

  char buf[33];
  itoa((size_t)initrd_begin, buf, 16);

  printf("initrd start: 0x");
  printf(buf); putchar('\n', VGA_COLOR);
  putchar(*initrd_begin, VGA_COLOR); putchar('\n', VGA_COLOR);

  _kernel_poweroff();
  */

  console_clear(VGA_COLOR);
  _kernel_putkerninfo("BismuthOS version " VERSION " (under construction)\n", 0);
  puts("Hello! I'm remaking parts of BismuthOS from scratch.\n");
  puts("This is a long sentence with the honest intention of testing character wrapping, I seriously hope it works or imma go nuts\n"); // TODO one space is outside of screen
  putchar('\n');
  _kernel_putkerninfo("test warn\n", 1);
  _kernel_putkerninfo("test error\n", 2);
  _kernel_putkerninfo("test kernel panic\n", 3);
  puts("here is a color test -> ");

  for(uint8_t i = 0; i <= 15; i++) {
    for (uint8_t j = 0; j <= 15; j++) {
      set_console_color(get_color_byte(i, j));
      putchar('X');
    }
  }
  set_console_color(VGA_COLOR);
  puts("\n\n");

  _kernel_poweroff();
}
