#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) do{int t = a; a = b, b = t;} while(0)
#define swap_t(type, a, b) do{type t = a; a = b, b = t;} while(0)
#define create_arr(n) (int*)calloc(n, sizeof(int))
#define create_arr_t(type, n) (type*)calloc(n, sizeof(type))
#define print_arr(arr, size) for(int i = 0; i < size; printf("%d ", arr[i++]))

void rand_set_arr(int *arr, int size, int mod){
    srand(time(NULL));
    while(size--) arr[size] = rand() %mod +1;
}

const char* is_sorted_s(int *arr, int n){
    int asc = 0, des = 0;
    for (int i = 0; i < n - 1; i++) {
        if (asc != 0 && des != 0)
            return "Not sorted";
        if (arr[i] <= arr[i + 1]) asc++;
        else if (arr[i] >= arr[i + 1]) des++;
    }
    if (arr[0] == arr[n - 1])
        return "all same";
    return asc ? "Ascending" : "descending";
}
