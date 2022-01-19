// type is '0', it means Ascending.
// type is '1', it means Descending.
const char* sort_state(int *arr, int n, int type){
    int start = arr[0], end = arr[n - 1];
    for (int i = 0; i < n - 1; i++)
        if (type == 0 && arr[i] > arr[i + 1] || type == 1 && arr[i] < arr[i + 1])
            return "Not sorted";
    if (start == end)
        return "all same";
    return type == 0 ? "Ascending" : "descending";
}
