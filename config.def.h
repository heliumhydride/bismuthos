#ifndef CONFIG_H
#define CONFIG_H

#define VERSION "v0.01a"

// Configuration for BismuthOS
#define KCOLOR_LOG    0x1F
#define KCOLOR_WARN   0xE0
#define KCOLOR_ERROR  0xCF
#define KCOLOR_PANIC  0xFC
#define VGA_COLOR     0x07

#define VGA_WIDTH  80
#define VGA_HEIGHT 25
#define VGA_BUF_PTR 0xb8000

//extern unsigned short* vt_buffer = (unsigned short*) 0xB8000;

#endif
