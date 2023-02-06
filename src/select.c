#include "main.h"

static void sort(int* const data, unsigned int len) {
  for (unsigned int i = 0; i < len; ++i) {
    int min_index = i;
    for (unsigned int j = i + 1; j < len; ++j) {
      if (data[min_index] > data[j]) {
        min_index = j;
      }
    }
    int tmp         = data[i];
    data[i]         = data[min_index];
    data[min_index] = tmp;
  }
}

const Sort select_sort = {
    .name = "SelectSort",
    .func = sort,
};
