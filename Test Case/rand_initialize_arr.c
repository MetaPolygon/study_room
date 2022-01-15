#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_initialize_arr(int *arr, int size, int mod, int range = 0){
	srand(time(NULL));
	if (range == -1){
		range = -mod;
		mod = 2*mod + 1;
	}
	for(int i = 0; i < size; arr[i++] = rand() %mod +range);
}
