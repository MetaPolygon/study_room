'''
에라토스테네스의 체(Sieve Of Eratosthenes)는 소수를 찾아, 소수들의 배수는 모두 소수가 아님을 미리 구해놓는 알고리즘이다.
나누는 수와 몫 중 하나는 반드시 sqrt(n)이하이기 때문에, 2 ~ sqrt(n) 중의 소수들에 대해서만 계산하면된다.
'''
def SieveOfEratosthenes(n) :
    primes = [1] * (n + 1)
    primes[0] = primes[1] = 0
    i = 2
    while i * i <= n :
        if primes[i] == 1:
            for j in range(2 * i, n + 1, i) :
                primes[j] = 0
        i += 1
    return primes
