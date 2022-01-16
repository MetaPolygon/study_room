#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a,b) do{int t = a; a = b, b = t;}while
#define print_arr(arr, size) for(int i = 0; i < size; printf("%d ", arr[i++]))

void rand_set_arr(int *arr, int size, int mod){
    srand(time(NULL));
    while(size--) arr[size] = rand() %mod +1;
}
