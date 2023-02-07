#include "main.h"

static void bubblesort(int* const data, unsigned int len) {
  for (unsigned int i = 0; i < len; ++i) {
    for (unsigned int j = i + 1; j < len; ++j) {
      if (data[i] > data[j]) {
        SWAP(data[i], data[j]);
      }
    }
  }
}

const Sort bubble = {
    .name = "BubbleSort",
    .func = bubblesort,
};
