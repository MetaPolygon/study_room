int binary_search(int *arr, int n, int key) {
    int pl = 0, pr = n - 1, pc;
    while (pl <= pr) {
        if (arr[pc = (pl + pr) / 2] == key)
            return pc;
        
        if (arr[pc] < key) pl = pc + 1;
        else pr = pc -1;
    }
    return -1;
}
