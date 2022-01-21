void shell_sort(int *arr, int n) {
    int h;
    for (h = 1; h < n / 9; h = h * 3 + 1);
    for (; h > 0; h /= 3)
        for (int i = h; i < n; i++) {
            int temp = arr[i], j;
            for (j = i - h; j >= 0 && arr[j] > temp; j -= h)
                arr[j + h] = arr[j];
            arr[j + h] = temp;
        }
}
