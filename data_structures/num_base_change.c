int num_base_change(unsigned val, int n, char *num) {
    const char *std = "0123456789ABCDEF";
    int len = 0;
    if (val == 0) num[len++] = '0';
    else 
        while (val) {
            num[len++] = std[val % n];
            val /= n;
        }
    for (int i = 0; i < len / 2; i++) {
        char temp = num[i];
        num[i] = num[len - i - 1], num[len - i - 1] = temp;
    }
    return len;
}
