#include <stdio.h>
#include <stdlib.h>
int main() {
    int n = 1000;
    int *arr = (int*)calloc(n + 1, sizeof(int));
    *arr = *(arr + 1) = 1;

    for (int i = 2; i * i <= n; i++)
        if (*(arr + i) == 0)
            for (int j = 2 * i; j <= n; j += i)
                *(arr + j) = 1;

    for (int i = 2; i <= n; i++)
        if (*(arr + i) == 0) printf("%d ", i);
}
