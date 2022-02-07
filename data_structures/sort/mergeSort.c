static void merge(int *arr, int left, int right, int *bfr)
{
  if (left < right) {
    int center = (left + right) / 2;
    int arr_idx, sort_idx = left;
    int bfr_idx = 0, bfr_last_idx = 0;
    merge(arr, left, center, bfr);
    merge(arr, center + 1, right, bfr);
        
    for (arr_idx = left; arr_idx <= center; arr_idx++)
      bfr[bfr_last_idx++] = arr[arr_idx];
    while (arr_idx <= right && bfr_idx < bfr_last_idx)
      arr[sort_idx++] = (bfr[bfr_idx] <= arr[arr_idx]) ? bfr[bfr_idx++] : arr[arr_idx++];
    while (bfr_idx < bfr_last_idx)
      arr[sort_idx++] = bfr[bfr_idx++];
  }
}

int mergeSort(int *arr, int n)
{
  int* bfr;
  if ((bfr = calloc(n/2 + 1, sizeof(int))) == NULL)
    return -1;
  merge(arr, 0, n - 1, bfr);
  free(bfr);
  return 0;
}
