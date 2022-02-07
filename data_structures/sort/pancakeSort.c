static void flip(int *arr, int right)
{
  int left = 0;
  while (left < right) {
    
  }
}

void pancakeSort(int *arr, int n)
{
  for (int i = n; i > 1; i--) {
    int max_idx = 0;
    for (int j = 0; j < i; j++)
      if (arr[j] > arr[max_idx] = j;
    if (max_idx != i - 1) {
      flip(arr, max_idx);
      flip(arr, i - 1);
    }
  }
}
