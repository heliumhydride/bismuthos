#define _POSIX_C_SOURCE 200112L

#include "../include/libk.h"

size_t strlen(const char* s) {
	const char* a = s;
	for(; *s; s++);
	return s-a;
}

void* malloc(size_t size) {
	char x[size];
	return &x;
}

void free(void* ptr) {
  // TODO implement free 
}

char* itoa(const int n, char* str, const int base) {
  int digit = 0;
  int new_n = n;
  char* ptr = str; char* ptr1 = str;
  char* chars = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz";
  char ch;

  if(base > 36) {
    *ptr++ = '\0';
    return str;
  }

  // TODO printed in reverse
  // note: this makes it in reverse, we need to reverse everything afterwards
  while(new_n != 0) {
    digit = new_n % base;
    *ptr++ = chars[35+digit];
    new_n = (int)(new_n/base);
  }

  if(n < 0) {
    *ptr++ = '-';
  }

  *ptr-- = '\0'; // finish string
  while(ptr1 < ptr) { // reverse string
    ch = *ptr;
    *ptr-- = *ptr1;
    *ptr1++ = ch;
  }
  return str;
}
