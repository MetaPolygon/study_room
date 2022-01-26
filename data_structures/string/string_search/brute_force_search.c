int brute_force_search(const char *str, const char *search) {
    int idx = 0, cmp_idx = 0;
    while (str[idx] != '\0' && search[cmp_idx] != '\0') {
        if (str[idx] == search[cmp_idx])
            idx++, cmp_idx++;
        else 
            idx = idx - cmp_idx + 1, cmp_idx = 0;
    }
    if (search[cmp_idx] == '\0')
        return idx - cmp_idx;
    return -1;
}
