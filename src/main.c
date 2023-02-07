#include "main.h"

#include <limits.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern const Sort bubble, select_sort, insert, shell, quick, merge, heap;
// clang-format off
static const Sort* sort_list[] = {
    &bubble,
    &select_sort,
    &insert,
    &shell,
    &quick,
    &merge,
    &heap,
};
// clang-format on
#define SORT_LIST_LEN (unsigned int)(sizeof(sort_list) / sizeof(Sort*))

int main(void) {
  unsigned int len = 0;
  printf("Array length: ");
  scanf("%u", &len);
  if (len == 0) {
    len = 50000;
    printf("(length == 0; use %u)\n", len);
  }
  int* data = calloc(len, sizeof(int));
  if (!data) {
    fprintf(stderr, "Failed to allocate array\n");
    return 1;
  }

  unsigned int times = 0;
  printf("The number of trial: ");
  scanf("%u", &times);
  if (times == 0) {
    times = 10;
    printf("(times == 0; use %u)\n", times);
  }

  srand(time(NULL));
  clock_t total_times[SORT_LIST_LEN] = {0};

  unsigned int i;
  for (i = 0; i < times; ++i) {
    printf("\n====== %d\n", i);
    for (unsigned int i = 0; i < len; ++i) {
      data[i] = rand();
    }

    int* sort_data = calloc(len, sizeof(int));
    if (!sort_data) {
      fprintf(stderr, "Failed to allocate array\n");
      return 1;
    }

    for (unsigned int i = 0; i < SORT_LIST_LEN; ++i) {
      printf(">> %10s : ", sort_list[i]->name);
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
      total_times[i] += total;
      printf("[%8ld (%lf sec)]\n", total, (double)total / CLOCKS_PER_SEC);
    }
    free(sort_data);
  }
  free(data);

  printf("\n====== Result (average time)\n");
  for (unsigned int i = 0; i < SORT_LIST_LEN; ++i) {
    const double avg = (double)total_times[i] / times;
    printf(
        ">> %10s : %9.2lf (%lf sec)\n", sort_list[i]->name, avg,
        avg / CLOCKS_PER_SEC
    );
  }
  return 0;
}
