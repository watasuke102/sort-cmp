void bubblesort(int* const data, unsigned int len) {
  for (unsigned int i = 0; i < len; ++i) {
    for (unsigned int j = i + 1; j < len; ++j) {
      if (data[i] > data[j]) {
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
      }
    }
  }
}
