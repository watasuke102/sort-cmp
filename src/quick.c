#include "main.h"


// sort [left, right) recursively
static void quicksort(int* const data, int left, int right) {
  const int len = right - left;
  if (len <= 1) {
    return;
  }
  const unsigned int pivot_index = (left + right) / 2;
  const int          pivot       = data[pivot_index];
  SWAP(data[pivot_index], data[right - 1]);

  int swap_dst = left;
  for (int i = left; i < right - 1; ++i) {
    if (data[i] < pivot) {
      SWAP(data[i], data[swap_dst]);
      ++swap_dst;
    }
  }
  SWAP(data[right - 1], data[swap_dst]);
  quicksort(data, left, swap_dst);
  quicksort(data, swap_dst + 1, right);
}

static void sort(int* const data, unsigned int len) {
  quicksort(data, 0, len);
}

const Sort quick = {
    .name = "QuickSort",
    .func = sort,
};
