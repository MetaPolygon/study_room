static void downheap(int *arr, int left, int right)
{
  int root = arr[left];
  int child, parent = left;
  for (; parent < (right + 1) / 2; parent = child) {
    int lc = parent * 2 + 1, rc = lc + 1;
    child = (rc <= right && arr[rc] > arr[lc]) ? rc : lc;
    if (root >= arr[child]) break;
      arr[parent] = arr[child];
  }
  arr[parent] = root;
}

void heapSort(int *arr, int n)
{
  int i;
  for (i = (n - 1) / 2; i >= 0; i--)
    downheap(arr, i, n - 1);
  for (i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    downheap(arr, 0, i - 1);
  }
}
