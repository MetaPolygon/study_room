// Initialize the elements of array to random numbers of 1 ~ mod
// the function 'rand()' returns a value in the range of at least 0 ~ (2^15 -1 == 32,767)

void rand_set_arr(int *arr, int size, int mod){
    srand(time(NULL));
    while(size--) arr[size] = rand() %mod +1;
}
