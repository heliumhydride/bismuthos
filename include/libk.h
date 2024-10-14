#ifndef LIBK_H
#define LIBK_H

#define NULL ((void*)0)

#include <stdint.h>
#include <stddef.h>

size_t strlen(const char* s);
void* malloc(size_t size);
void free(void* p);
char* itoa(int n, char* s, int base);

#endif
