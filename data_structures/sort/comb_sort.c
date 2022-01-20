void comb_sort(int *arr, int n) {
    double gap = n, shrink_factor = 1.3;
    while (gap > 1) {
        gap /= shrink_factor;
        for (int i = 0; i + gap < n; i++)
            if (arr[i] > arr[i + (int)gap])
                swap(arr[i], arr[i + (int)gap]);
    }
}
