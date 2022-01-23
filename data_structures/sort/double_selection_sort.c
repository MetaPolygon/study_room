void double_selection_sort(int *arr, int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int min_idx = left, max_idx = right;
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[min_idx]) min_idx = i;
            if (arr[i] > arr[max_idx]) max_idx = i;
        }
        swap(arr[left], arr[min_idx]);
        if (max_idx == left) swap(arr[min_idx], arr[right]); //
        else swap(arr[max_idx], arr[right]);
        left++, right--;
    }
}
