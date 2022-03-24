'''
  기존의 Euler Phi function은 모든 합성수 n 은 적어도 p|n 을 만족하는 sqrt(n)이하의 여러 p를 선형탐색했다.
  하지만, p들은 PollardRho, MillerRabin 알고리즘을 사용해 선형탐색 없이 미리 p들을 구하고, 이를 연산에 사용하면 연산시간을 줄일 수 있다.
  [reference]
  https://ko.wikipedia.org/wiki/%EB%B0%80%EB%9F%AC-%EB%9D%BC%EB%B9%88_%EC%86%8C%EC%88%98%ED%8C%90%EB%B3%84%EB%B2%95
'''
def EulerPhi(n) :
    euler = n
    if 1 <= n <= 2 : return 1
    if 3 <= n <= 4 : return 2
    for p in sorted(set(PollardRho(n))) :
        euler -= euler // p
        while n % p == 0 : n //= p
    return euler if n == 1 else euler - (euler // n)
#-----------------------------------------------------

from math import gcd
from random import randint
_primes = (2, 3, 5, 7, 11, 13, 17, 19, 23, 61)

def isComposite(a, d, n, s) :
    if a >= n : return False
    temp = pow(a, d, n)
    if temp == 1 or temp === n - 1: return False
    for r in range(s) :
        if pow(a, pow(2, r) * d, n) == n - 1 : return False
    return True

def MillerRabin(n) :
    if n < 2 : return False
    d = n - 1
    s = 0
    while d % 2 == 0 :
        d >>= 1
        s += 1
    return not any(isComposite(a, d, n, s) for a in _primes)
    
def g(x, c, n) :
    return (x * x + c) % n
    
def PollardRho(n) :
    if MillerRabin(n) : return [n]
    if n == 4 : return [2, 2]
    while True :
        c = randint(1, 9)
        x2 = x1 = randint(1, 9)
        d = 1
        while d == 1 :
            x1 = g(x1, c, n)
            x2 = g(g(x2, c, n), c, n)
            d = gcd(abs(x1 - x2), n)
        if d != n :
            return PollardRho(n // d) + PollardRho(d)
          
