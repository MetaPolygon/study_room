int radix_sort(int *arr, int n, int digit, int num_base) {
    int *cnt, *temp;
    if ((cnt = (int*)calloc(num_base, sizeof(int))) == NULL || 
        (temp = (int*)calloc(n, sizeof(int))) == NULL)
        return -1;
        
    int i, digit_val, idx;
    for (int d = 0; d < digit; d++) {
        memset(cnt, 0, num_base * sizeof(int));
        digit_val = pow(num_base, d);
        
        for (i = 0; i < n; i++) {
            idx = (arr[i] / digit_val) % num_base;
            cnt[idx] = cnt[idx] + 1;
        }
        for (i = 1; i < num_base; i++)
            cnt[i] = cnt[i] + cnt[i - 1];
            
        for (i = n - 1; i >= 0; i--) {
            idx = (arr[i] / digit_val) % num_base;
            temp[cnt[idx] - 1] = arr[i];
            cnt[idx] = cnt[idx] - 1;
        }
        memcpy(arr, temp, n * sizeof(int));
    }
    free(cnt);
    free(temp);
}
