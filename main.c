#include <stdio.h>
#include <stdlib.h>

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
  for (int i = 0; i < len; ++i) {
    printf("data[%2d]: %d\n", i, data[i]);
  }

  free(data);
  return 0;
}
