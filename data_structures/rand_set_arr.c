void rand_set_arr(int *arr, int size, int mod){
    srand(time(NULL));
    while(size--) arr[size] = rand() %mod +1;
}
