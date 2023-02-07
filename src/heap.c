#include <memory.h>
#include <stdlib.h>

#include "main.h"

static void heap_validate(
    int* const heap, unsigned int len, unsigned int parent_index
) {
  unsigned int child_index;
  {
    const unsigned int child_left = parent_index * 2 + 1;
    if (child_left >= len) {
      return;
    }
    const unsigned int child_right = child_left + 1;
    if (child_right < len && heap[child_left] < heap[child_right]) {
      child_index = child_right;
    } else {
      child_index = child_left;
    }
  }

  if (heap[child_index] <= heap[parent_index]) {
    return;
  }
  SWAP(heap[child_index], heap[parent_index]);
  heap_validate(heap, len, child_index);
}

static void sort(int* const data, unsigned int len) {
  for (int i = len / 2 - 1; i >= 0; --i) {
    heap_validate(data, len, i);
  }

  for (int i = len - 1; i > 0; --i) {
    SWAP(data[0], data[i]);
    heap_validate(data, i, 0);
  }
}

const Sort heap = {
    .name = "HeapSort",
    .func = sort,
};
