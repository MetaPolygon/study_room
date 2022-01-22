const char* is_sorted(int *arr, int n){
    int asc = 0, des = 0;
    for (int i = 0; i < n - 1; i++) {
        if (asc != 0 && des != 0)
            return "Not sorted";
        if (arr[i] <= arr[i + 1]) asc++;
        else if (arr[i] >= arr[i + 1]) des++;
    }
    if (arr[0] == arr[n - 1])
        return "all same";
    return asc ? "Ascending" : "descending";
}

// order is '0', it means Ascending.
// order is '1', it means Descending.
const char* is_sorted(int *arr, int n, int order){
    int start = arr[0], end = arr[n - 1];
    for (int i = 0; i < n - 1; i++)
        if (order == 0 && arr[i] > arr[i + 1] || order == 1 && arr[i] < arr[i + 1])
            return "Not sorted";
    if (start == end)
        return "all same";
    return order == 0 ? "Ascending" : "descending";
}
