//improved ver, set the range to the last exchanged index
void bubble_sort(int *arr, int n){
    for (int i = 0; i < n - 1;) {
        int last_idx = n - 1;
        for (int j = n - 1; j > i; j--)
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                last_idx = j;
            }
        i = last_idx;
    }
}

//default
void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; j > i; j--)
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
}
