#define bit unsigned int
#define BIT bit*
#define shift(n) ((bit)1 << (n))
#define byteSize (sizeof(bit) * 8)

int is_prime(const bit *bs, int n) {
    return !(bs[n / byteSize] & shift(n % byteSize));
}

void add(bit *bs, int n) {
    bs[n / byteSize] |= shift(n % byteSize);
}

void print_prime(const bit *bs, int n) {
    for (bit i = 0; i <= (n / byteSize); i++)
        for(bit j = 0; j < byteSize && j + (byteSize * i) <= n; j++)
            if (is_prime(bs, j + (byteSize * i)))
                printf("%lu ", j + (byteSize * i));
}

BIT get_prime_list_bit(int n) {
    int size = (n / byteSize) + 1;
    bit *bs = (bit *)calloc(size, sizeof(bit));
    add(bs, 0);
    add(bs, 1);
	
    for (int i = 2; i * i <= n; i++)
        if (is_prime(bs, i))
            for (int j = i * i; j <= n; j += i)
                if (is_prime(bs, j))
                    add(bs, j);
    return bs;
}
