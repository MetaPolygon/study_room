from math import sqrt

def getPrimeFactor(N) :
    prime_factor_list = []
    d = 2
    sqrt_n = int(sqrt(N)) + 1
    while d <= sqrt_n :
        if N % d != 0 : d += 1
        else :
            prime_factor_list.append(d)
            N //= d
    return [1, N] if N > 1 else prime_factor_list
