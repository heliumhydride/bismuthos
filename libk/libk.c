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
  //stub function, returns NULL
  return NULL;
}
