'''
분할 정복을 이용한 거듭제곱
시간 복잡도 : O(N) → O(log N) 으로 단축
'''

def pow(a, b) :
    result = 1
    while b :
        if b & 1 : result *= a
        a *= a
        b >>= 1
    return result

def powmod(a, b, m) :
    result = 1
    while b :
        if b & 1 : result = result * a % m
        a = a * a % m
        b >>= 1
    return result
