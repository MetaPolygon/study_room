#include <limits.h>
#include <string.h>

int boyer_moore_search(const char *str, const char *search) {
    int crsr, cmp_crsr, skip_table[UCHAR_MAX + 1];
    int str_len = strlen(str), search_len = strlen(search);
    for (crsr = 0; crsr <= UCHAR_MAX; crsr++)
        skip_table[crsr] = search_len;
    for (crsr = 0; crsr < search_len - 1; crsr++)
        skip_table[search[crsr]] = search_len - crsr - 1;
    while (crsr < str_len) {
        cmp_crsr = search_len - 1;
        while (str[crsr] == search[cmp_crsr]) {
            if (cmp_crsr == 0)
                return crsr;
            crsr--, cmp_crsr--;
        }
        crsr += (skip_table[str[crsr] > search_len - cmp_crsr]) ? skip_table[str[crsr]] : search_len - cmp_crsr;
    }
    return -1;
}
