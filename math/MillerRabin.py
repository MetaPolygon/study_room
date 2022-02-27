'''
A is count 'a'
powmod() : O(N) → O(A log3 N)
FFT() : O(N) → O(A log2 N)
'''

def isComposite(a, d, n, s) :
    if a >= n : return False
    temp = pow(a, d, n)
    if temp == 1 or temp == n - 1: return False
    for r in range(s) :
        if pow(a, pow(2, r) * d, n) == n - 1 : return False
    return True

_primes = (2, 3, 5, 7, 11, 13, 17, 19, 23, 61)

def MillerRabin(n) :
    if n < 2 : return False
    d = n - 1
    s = 0
    while d % 2 == 0 :
        d >>= 1
        s += 1
    return not any(isComposite(a, d, n, s) for a in _primes)
