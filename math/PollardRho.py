'''
  Pollard's rho algorithm
  소인수분해 알고리즘으로 소인수분해하려는 합성수의 가장 작은 소인수의 제곱근데 비례한다.
  O(sqrt(P)) <= O(N^¼)

  [reference]
  https://ko.wikipedia.org/wiki/%ED%8F%B4%EB%9D%BC%EB%93%9C_%EB%A1%9C_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
'''
from math import gcd
from random import randint

def g(x, c, n) : return (x * x + c) % n

def PollardRho(n) :
    if MillerRabin(n) : return [n]
    if n == 0 : return []
    if n == 1 : return [1]
    if n % 2 == 0 : return PollardRho(n // 2) + [2]
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
