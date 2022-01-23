void counting_sort(int *arr, int n, int max) {
    int i, *f = (int*)calloc(max + 1, sizeof(int)),
           *b = (int*)calloc(n, sizeof(int));
    for (i = 0; i < n; i++) f[arr[i]]++;                //create frequency table
    for (i = 1; i <= max; i++) f[i] += f[i-1];          //create cumulative frequency distribution table
    for (i = n-1; i >= 0; i--) b[--f[arr[i]]] = arr[i];
    for (i = 0; i < n; i++) arr[i] = b[i];
    free(f);
    free(b);
}
