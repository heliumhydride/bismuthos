#define _POSIX_C_SOURCE 200112L

#include "../include/video.h"

size_t vt_line = 0;
size_t vt_col  = 0;
uint8_t* vt_buffer = (uint8_t*)0xb8000;

void putchar(const char ch, uint8_t col) {
  switch(ch) {
    case '\n':
      vt_line++;
      vt_col = -1; // For some reason not vt_col shouldn't be put to 0... I took a whole year to figure that one out
      break;
    default:
      vt_buffer[VGA_WIDTH * 2 * vt_line + 2 * vt_col]     = ch;
      vt_buffer[VGA_WIDTH * 2 * vt_line + 2 * vt_col + 1] = col;
      break;
  }
  
  if(++vt_col == VGA_WIDTH) {
    vt_col = 0;
    if(++vt_line == VGA_HEIGHT)
      // TODO terminal scrolling
      for(size_t i = 0; i<VGA_WIDTH; i+=2) { // Remove the first line of the screen
        vt_buffer[i] = ' ';
        vt_buffer[i+1] = 0x0F;
      }
      for(size_t i = VGA_WIDTH; i>VGA_WIDTH*VGA_HEIGHT; i--) // Shift the lines up
        vt_buffer[i] = vt_buffer[i-VGA_WIDTH];
      vt_line = 0;
  }
}

void printk(const char* s, unsigned int severity) {
  // 0 -> Log/Note; 1 -> Warning; 2 -> Error; 3 -> Kernel panic
  uint8_t col;
  switch(severity) {
    case 0:
      col = KCOLOR_LOG;
      break;
    case 1:
      col = KCOLOR_WARN;
      break;
    case 2:
      col = KCOLOR_ERROR;
      break;
    case 3:
      col = KCOLOR_PANIC;
      break;
    default:
      col = KCOLOR_LOG;
      break;
  }

  print_color(s,col);
}

// int printf(const char* format, ..) {
void printf(const char* s) { // for now, just a print() command
  // VGA_COLOR defined config.h
  print_color(s, VGA_COLOR);
}

void print_color(const char* s, uint8_t col) {
  for(size_t i = 0; i < strlen(s); i++)
    putchar(s[i], col);
  // vt_col = 0; // TODO TEMP FIX
}

void vt_clear(uint8_t col) {
  vt_col = 0;
  vt_line = 0;
  for(int i = 0; i < VGA_WIDTH*VGA_HEIGHT; i++) {
    vt_buffer[i]   = 0;
    vt_buffer[i+1] = col;
  }
}
