#ifndef VGATERM_H
#define VGATERM_H

#include "libk.h" // strlen
#include <stddef.h> // uint*_t
#include <stdint.h> // size_t
#include "../config.h" // VGA_COLOR

extern size_t console_Ypos, console_Xpos;
extern uint8_t console_color;
extern uint8_t* video_ptr;

void scroll_console_up(uint32_t n); 
uint8_t get_color_byte(uint8_t fg, uint8_t bg); 
void set_console_color(uint8_t color); 
void console_clear(uint8_t color); 
void putch_at(const char c, const size_t line, const size_t column, const uint8_t color); 
void putchar(const char c); 
void puts(const char* s); 

#endif // VGATERM_H
