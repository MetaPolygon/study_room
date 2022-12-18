static void __mergeSort(int *arr, int left, int right, int *buff)
{
  if (left < right) {
    int mid = (left + right) / 2;
    __mergeSort(arr, left, mid, buff);
    __mergeSort(arr, mid + 1, right, buff);
    
    int idx = left, buff_p = 0;
    while (idx <= mid) buff[buff_p++] = arr[idx++];
    int sort_p = left, buff_idx = 0;
    while (idx <= right && buff_idx < buff_p)
      arr[sort_p++] = ((buff[buff_idx] <= arr[idx]) ? buff[buff_idx++] : arr[idx++]);
    while (buff_idx < buff_p) arr[sort_p++] = buff[buff_idx++];
  }
}

int mergeSort(int *arr, int size)
{
  int* buff;
  if ((buff = calloc((size>>1) + 1, sizeof(int))) == NULL)
    return -1;
  __mergeSort(arr, 0, size - 1, buff);
  free(buff);
  return 0;
}
