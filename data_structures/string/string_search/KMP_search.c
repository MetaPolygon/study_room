#include <limits.h>

int KMP_search(const char *str, const char *search) {
    int crsr = 1, cmp_crsr = 0;
	int skip_table[UCHAR_MAX + 1];
	
	skip_table[crsr] = 0;
	while (search[crsr] != '\0') {
		if (search[crsr] == search[cmp_crsr])
			skip_table[++crsr] = ++cmp_crsr;
		else if (cmp_crsr == 0) skip_table[++crsr] = cmp_crsr;
		else cmp_crsr = skip_table[cmp_crsr];
	}

	crsr = cmp_crsr = 0;
	while (str[crsr] != '\0' && search[cmp_crsr] != '\0') {
		if (str[crsr] == search[cmp_crsr])
			crsr++, cmp_crsr++;
		else if (cmp_crsr == 0) crsr++;
		else cmp_crsr = skip_table[cmp_crsr];
	}
	
	if (search[cmp_crsr] == '\0')
		return crsr - cmp_crsr;
	return -1;
}
