#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"

static void mergesort(int* const data, unsigned int left, unsigned int right) {
  if (right - left <= 1) {
    return;
  }
  const unsigned int mid = (left + right) / 2;

  mergesort(data, left, mid);
  const unsigned int left_len   = mid - left;
  int* const         left_array = calloc(left_len, sizeof(int));
  memcpy(left_array, data + left, sizeof(int) * left_len);

  mergesort(data, mid, right);
  const unsigned int right_len   = right - mid;
  int* const         right_array = calloc(right_len, sizeof(int));
  memcpy(right_array, data + mid, sizeof(int) * right_len);

  unsigned int left_i = 0, right_i = 0;
  for (unsigned int i = left; i < right; ++i) {
    if (left_i >= left_len) {
      data[i] = right_array[right_i++];
    } else if (right_i >= right_len) {
      data[i] = left_array[left_i++];
    } else {
      if (left_array[left_i] <= right_array[right_i]) {
        data[i] = left_array[left_i++];
      } else {
        data[i] = right_array[right_i++];
      }
    }
  }

  free(left_array);
  free(right_array);
}

static void sort(int* const data, unsigned int len) {
  mergesort(data, 0, len);
}

const Sort merge = {
    .name = "MergeSort",
    .func = sort,
};
