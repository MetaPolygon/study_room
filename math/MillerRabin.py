'''
  Miller-Rabin primality test
  주어진 수가 소수인지 판별하는 알고리즘이다. 
  작은 수에 대한 판별은 n < 341,550,071,728,321 일때, a = 2,3,5,7,11,13,17 에 대해서만 검사하면 충분하다. 
  A is count 'a'
  시간 복잡도는 아래와 같다.
  powmod() : O(N) → O(A log3 N)
  FFT() : O(N) → O(A log2 N)
  [reference]
  https://ko.wikipedia.org/wiki/%EB%B0%80%EB%9F%AC-%EB%9D%BC%EB%B9%88_%EC%86%8C%EC%88%98%ED%8C%90%EB%B3%84%EB%B2%95
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
