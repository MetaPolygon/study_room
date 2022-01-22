int upper_bound(int *arr, int n, int key) {
    int pl = 0, pr = n - 1, pc;
    while (pl < pr) {
        if (arr[pc = (pl + pr) / 2] > key) pr = pc;
        else pl = pc + 1;
    }
    return pr;
}

int lower_bound(int *arr, int n, int key) {
    int pl = 0, pr = n - 1, pc;
    while (pl < pr) {
        if (arr[pc = (pl + pr) / 2] < key) pl = pc + 1;
        else pr = pc;
    }
    return pl;
}
