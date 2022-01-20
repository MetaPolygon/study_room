// type is '0', it means Ascending.
// type is '1', it means Descending.
const char* sort_state(int *arr, int n, int order){
    int start = arr[0], end = arr[n - 1];
    for (int i = 0; i < n - 1; i++)
        if (order == 0 && arr[i] > arr[i + 1] || order == 1 && arr[i] < arr[i + 1])
            return "Not sorted";
    if (start == end)
        return "all same";
    return order == 0 ? "Ascending" : "descending";
}
