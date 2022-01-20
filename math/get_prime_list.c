#include <stdlib.h>
#include <stdbool.h>

//find the prime number between 2 ~ n, and put the number of primes in 'len'
int* get_prime_list(int* n) {
    int size = *n;
    printf("%d::",size);
    *n = 0;
    bool *nums = (bool*)calloc(size + 1, sizeof(bool));
    nums[0] = nums[1] = true;
    
    int cnt = size - 1;
    for (int i = 2; i * i <= size; i++)
        if (nums[i] == false)
            for (int j = i * i; j <= size; j += i)
                if (nums[j] == false){
                    nums[j] = true;
                    cnt--;
                }
    
    int *prime_list = (int*)calloc(cnt, sizeof(int));
    for (int i = 2; i <= size; i++)
        if (nums[i] == false)
            prime_list[(*n)++] = i;
    
    free(nums);
    return prime_list;
}
