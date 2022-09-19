int binary_search(int *arr, int n, int key)
{
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        if (arr[mid = (left + right) / 2] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
