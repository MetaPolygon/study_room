'''
  제곱 인수가 없는 정수(Square-Free Integer)는 1이 아닌 제곱수를 인수로 갖지 않는 양의 정수를 뜻한다.
  즉, 1보다 큰 제곱수로 나누어 떨어지지 않는 수를 뜻한다.
  편의상 제곱 인수가 없는 정수(Square-Free Integer)를 SFI라고 부르겠다.
'''

'''
  'Sieve Of Eratosthenes' ver
  편의상 
  (1) n까지의 제곱수들을 미리 구한다.
      pow_primes = []
      i = 2
      while i * i <= MAX :
          pow_primes.append(i * i)
          i += 1
          
  (2) 작은 제곱수부터 처음으로 나누어 떨어지는 수(first_not_SFI)를 찾는다.
      SFI = [1] * (n - start_num + 1)       #SFI를 표시할 리스트 선언
      for i in pow_primes :
          first_not_SFI = start_num // i * i
      
  (3) (2)에서 찾은 수 부터 n이하의 수들 중 제곱수의 배수만큼 증가시키며 SFI가 아닌 수들을 표시한다.
          for j in range(first_not_SFI, n + 1, i) :
              if j - start_num >= 0 :
                  SFI[j - start_num] = 0      # SFI가 아닌 수 표시

  (4) (1) ~ (3) 을 거쳐 SFI인지 아닌지 알 수 있는 리스트가 
'''
