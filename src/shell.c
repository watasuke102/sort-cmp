#include "main.h"

#define GAPS_LEN 8
// Marcin Ciura's gap sequence
static const unsigned int gaps[GAPS_LEN] = {701, 301, 132, 57, 23, 10, 4, 1};

static void sort(int* const data, unsigned int len) {
  for (unsigned int i = 0; i < GAPS_LEN; ++i) {
    const unsigned int gap = gaps[i];
    if (gap > len) {
      continue;
    }
    // -----
    for (unsigned int i = gap; i < len - gap; ++i) {
      const int    e = data[i];
      unsigned int j;
      for (j = i; j < len; j += gap) {
        if (data[j] < e) {
          break;
        }
        data[j] = data[j - gap];
      }
      if (j < len) {
        data[j] = e;
      }
    }
    // -----
  }
}

const Sort shell = {
    .name = "ShellSort",
    .func = sort,
};
