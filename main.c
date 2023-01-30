#include <limits.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SORT_FUNC_LEN 1
void bubblesort(int* const data, unsigned int len);
void (*sort_func[SORT_FUNC_LEN])(int* const data, unsigned int len) = {
    bubblesort,
};

int main(void) {
  unsigned int len;
  printf("Array length: ");
  scanf("%u", &len);
  if (len == 0) {
    len = UINT_MAX;
  }
  int* data = calloc(len, sizeof(int));
  if (!data) {
    fprintf(stderr, "Failed to allocate array\n");
    return 1;
  }

  srand(time(NULL));
  for (unsigned int i = 0; i < len; ++i) {
    data[len] = rand();
  }

  int* sort_data = calloc(len, sizeof(int));
  if (!sort_data) {
    fprintf(stderr, "Failed to allocate array\n");
    return 1;
  }

  for (int i = 0; i < SORT_FUNC_LEN; ++i) {
    memcpy(sort_data, data, sizeof(int) * len);

    const clock_t begin = clock();
    sort_func[i](sort_data, len);
    const clock_t end = clock();

    const clock_t total = end - begin;
    printf("End: %ld (%lf sec)\n", total, (double)total / CLOCKS_PER_SEC);
  }

  free(sort_data);
  free(data);
  return 0;
}
