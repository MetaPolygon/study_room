'''
  제곱 인수가 없는 정수(Square-Free Integer)는 1이 아닌 제곱수를 인수로 갖지 않는 양의 정수를 뜻한다.
  즉, 1보다 큰 제곱수로 나누어 떨어지지 않는 수를 뜻한다.
  편의상 제곱 인수가 없는 정수(Square-Free Integer)를 SFI라고 부르겠다.

  특정 구간에 존재하는 SFI의 개수는 다음과 같은 방법으로 구할 수 있다.
  
  (1) n까지의 제곱수들을 미리 구한다. [꼭 미리 구할 필요는 없다. (2) ~ (3)의 과정 중에서 계산 가능하다.]
  (2) 작은 제곱수부터 처음으로 나누어 떨어지는 수(first_not_SFI)를 찾는다.
  (3) (2)에서 찾은 수 부터 n이하의 수들 중 제곱수의 배수만큼 증가시키며 SFI가 아닌 수들을 표시한다.
  (4) (1) ~ (3) 을 거쳐 SFI인지 아닌지 알 수 있는 리스트 isSFI가 반환된다.
  
'''

# 'Sieve Of Eratosthenes' ver 
# SquareFreeInteger(start[,n]) n 생략시 0부터 start이하 중에서 SFI를 구한다.

def SquareFreeInteger(start, n = 0) :
    if n == 0 : start, n = n, start
    isSFI = [1] * (n - start + 1)
    i = 2
    while i * i <= n :
        pow_prime = i * i
        first_not_SFI = start // pow_prime * pow_prime
        for j in range(first_not_SFI, n + 1, pow_prime) :
            if j - start >= 0 :
                isSFI[j - start] = 0
        i += 1
    return isSFI
