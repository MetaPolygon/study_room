void insertionSort(int *arr, int n)
{
  for (int i = 1; i < n; i++) {
    int temp = arr[i], j;
    for (j = i; j > 0 && arr[j - 1] > temp; j--)
      arr[j] = arr[j - 1];
    arr[j] = temp;
  }
}
