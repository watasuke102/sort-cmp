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
  free(data);
  return 0;
}
