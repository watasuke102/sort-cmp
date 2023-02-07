#pragma once

typedef void (*SortFunction)(int* const data, unsigned int len);
typedef struct {
  char         name[32];
  SortFunction func;
} Sort;

#define SWAP(a, b) \
  {                \
    int tmp = a;   \
    a       = b;   \
    b       = tmp; \
  }
