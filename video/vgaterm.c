#define _XOPEN_SOURCE   600
#define _POSIX_C_SOURCE 200112L

#include "../include/vgaterm.h"

size_t console_Ypos = 0, console_Xpos = 0;
uint8_t console_color = VGA_COLOR;
uint8_t* video_ptr = (uint8_t*)VGA_BUF_PTR;

void scroll_console_up(uint32_t n) {
  console_Ypos = 0;
}

uint8_t get_color_byte(uint8_t fg, uint8_t bg) {
  return (bg << 4) | fg;
}

void set_console_color(uint8_t color) {
  console_color = color;
}

void console_clear(uint8_t color) {
  // nested for loop to go through each char on screen to erase them
  for(size_t x = 0; x < VGA_WIDTH; x++) {
    for(size_t y = 0; y < VGA_HEIGHT; y++) {
      putch_at(' ', y, x, color);
    }
  }
  console_Ypos = 0, console_Xpos = 0;
}

void putch_at(const char c, const size_t y, const size_t x, const uint8_t color) {
  video_ptr[(y*VGA_WIDTH + x)*2] = c;
  video_ptr[(y*VGA_WIDTH + x)*2 + 1] = color;
}

void _newline(void) {
  console_Ypos++;
  console_Xpos = 0;
}

void putchar(const char c) {
  switch(c) {
    case '\n':
      _newline();
      break;
    default:
      putch_at(c, console_Ypos, console_Xpos, console_color);
      if(console_Xpos+1 >= VGA_WIDTH) {
        _newline();
      } else {console_Xpos++;}
      break;
  }

  if(console_Ypos + 1 > VGA_HEIGHT)
    scroll_console_up(1);
}

void puts(const char* s) {
  for(size_t i = 0; i < strlen(s); i++) {
    putchar(s[i]);
  }
}

