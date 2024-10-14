#ifndef VIDEO_H
#define VIDEO_H
#include "libk.h"
#include <stdint.h>
#include <stddef.h>
#include "../config.h"

extern size_t vt_line;
extern size_t vt_col;
extern uint8_t* vt_buffer;

void printk(const char* s, unsigned int severity);
void printf(const char* s);
void print_color(const char* s, uint8_t col);
void putchar(const char ch, uint8_t col);
void vt_clear(uint8_t col);

#endif
