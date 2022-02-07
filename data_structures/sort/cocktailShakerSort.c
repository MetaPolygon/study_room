void cocktailShakerSort(int *arr, int n)
{
  int left = 0, right = n;
  int shift = left, idx;
  while (left < right) {
    idx = left;
    while (++idx < right)
      if (arr[idx] < arr[idx - 1]) {
        swap(arr[idx], arr[idx - 1]);
        shift = idx;
      }
        
    idx = right = shift; 
    while (left < --idx)
      if (arr[idx] < arr[idx - 1]) {
        swap(arr[idx], arr[idx - 1]);
        shift = idx;
      }
    left = shift;
  }
}
