#include "main.h"

#include <limits.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern const Sort bubble, select_sort, insert, shell, quick;
// clang-format off
static const Sort* sort_list[] = {
    &bubble,
    &select_sort,
    &insert,
    &shell,
    &quick,
    NULL,
};
// clang-format on

int main(void) {
  unsigned int len;
  // printf("Array length: ");
  // scanf("%u", &len);
  // if (len == 0) {
  //   len = UINT_MAX;
  // }
  len       = 10000;
  int* data = calloc(len, sizeof(int));
  if (!data) {
    fprintf(stderr, "Failed to allocate array\n");
    return 1;
  }

  srand(time(NULL));
  for (unsigned int i = 0; i < len; ++i) {
    data[i] = rand();
  }

  int* sort_data = calloc(len, sizeof(int));
  if (!sort_data) {
    fprintf(stderr, "Failed to allocate array\n");
    return 1;
  }

  for (int i = 0; sort_list[i]; ++i) {
    printf(">> %12s : ", sort_list[i]->name);
    memcpy(sort_data, data, sizeof(int) * len);

    const clock_t begin = clock();
    sort_list[i]->func(sort_data, len);
    const clock_t end = clock();
    printf("Done. ");

    for (unsigned int i = 0; i < len - 2; ++i) {
      if (sort_data[i] > sort_data[i + 1]) {
        printf(
            "Sort Failed!! (%d: %d -> %d: %d)\n",  //
            i, sort_data[i],                       //
            i + 1, sort_data[i + 1]
        );
        return 1;
      }
    }
    const clock_t total = end - begin;
    printf("[%8ld (%lf sec)]\n", total, (double)total / CLOCKS_PER_SEC);
  }
  free(sort_data);
  free(data);
  return 0;
}
