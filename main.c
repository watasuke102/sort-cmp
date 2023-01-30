#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#define SORT_FUNC_LEN 1
void bubblesort(int* const data, int len);
void (*sort_func[SORT_FUNC_LEN])(int* const data, int len) = {
    bubblesort,
};

int main(void) {
  int len;
  printf("Array length: ");
  scanf("%d", &len);
  int* data = calloc(len, sizeof(int));
  if (!data) {
    fprintf(stderr, "Failed to allocate array\n");
    return 1;
  }

  for (int i = 0; i < len; ++i) {
    printf("data[%2d]: ", i);
    scanf("%d", data + i);
  }
  printf("=====\n");

  int* sort_data = calloc(len, sizeof(int));
  if (!sort_data) {
    fprintf(stderr, "Failed to allocate array\n");
    return 1;
  }
  for (int i = 0; i < SORT_FUNC_LEN; ++i) {
    memcpy(sort_data, data, sizeof(int) * len);
    sort_func[i](sort_data, len);
  }

  free(sort_data);
  free(data);
  return 0;
}
