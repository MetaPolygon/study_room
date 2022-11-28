from math import sqrt

def getDivisor(n) :
    divisor_list = set()
    for i in range(1, int(sqrt(n)) + 1) :
        if n % i == 0 :
            divisor_list.add(i)
            divisor_list.add(n // i)
    return sorted(divisor_list)
