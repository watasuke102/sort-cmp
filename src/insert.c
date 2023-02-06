#include "main.h"

static void sort(int* const data, unsigned int len) {
  for (unsigned int i = 1; i < len; ++i) {
    int          e = data[i];
    unsigned int j;
    for (j = i; j < len; ++j) {
      if (data[j] < e) {
        break;
      }
      data[j] = data[j - 1];
    }
    data[j] = e;
  }
}

const Sort insert = {
    .name = "InsertSort",
    .func = sort,
};
