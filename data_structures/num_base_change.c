int num_base_change(unsigned val, int n, char *num) {
    const char *std = "0123456789ABCDEF";
    int idx = 0;
    if (val == 0) num[idx++] = '0';
    else 
        while (val) {
            num[idx++] = std[val % n];
            val /= n;
        }
    return idx;
}
