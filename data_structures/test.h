#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a,b) do{int t = a; a = b, b = t;}while(0)
#define print_arr(arr, size) for(int i = 0; i < size; printf("%d ", arr[i++]))

void rand_set_arr(int *arr, int size, int mod){
    srand(time(NULL));
    while(size--) arr[size] = rand() %mod +1;
}

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
