void binaryInsertionSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i], idx = upper_bound(arr, i + 1, key);
    if(idx != i) {
      memmove(&arr[idx + 1], &arr[idx], sizeof(int)*(i - idx));
      arr[idx] = key;
    }
  }
}
