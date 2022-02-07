static void quick(int *arr, int left, int right)
{
  int pl = left, pr = right, pivot = arr[(pl + pr) / 2];
  while (pl <= pr) {
    while (arr[pl] < pivot) pl++;
    while (arr[pr] > pivot) pr--;
    if (pl <= pr) {
      swap(arr[pl], arr[pr]);
      pl++, pr--;
    }
  }
  if (left < pr) quick(arr, left, pr);
  if (pl < right) quick(arr, pl, right);
}

void quickSort(int *arr, int n)
{
  quick(arr, 0, n - 1);
}
