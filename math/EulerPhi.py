
'''
  Euler's phi function
  정수환에 대해 몫환의 가역원을 세는 함수이다.
  즉, n이 양의 정수일 때 ϕ(n)은 n과 서로소인 1부터 n이하의 정수의 개수와 같다.
  ϕ(n) = | { i ∈ {1, 2, ... , n} : gdc{n, i} = 1} |
  -----------------------------------------------------
  cnt = 0;
  for (int i = 1; i <= n ; i++)
    if (gcd(n, i) == 1) cnt++;
  print("[euelr phi function] retuen val : %d", cnt);
  -----------------------------------------------------  
  (1)   ϕ(n) = n ∏ (1 - 1/p)            Euler Product Foumula {p ∣ n}
  (2)   ϕ(mn) = ϕ(m)ϕ(n)                {gcd(m, n) = 1}
  (3-1) ϕ(p) = p - 1
  (3-2) ϕ(p^k) = p^(k - 1) * (p - 1) = p^k - p^(k - 1)
  (4)   Σ ϕ(d) = n                      {d | n}
  (5)   Σ dμ(n/d) = ϕ(n)
  (6)   a^ϕ(n) ≡ 1 (mod n)              {gcd(m, n) = 1}
  (7)   ϕ(n)이 2의 거듭제곱수일 때, 정 n각형은 눈금없는 자와 컴퍼스로 작도할 수 있다.
  
  [reference]
  https://en.wikipedia.org/wiki/Euler%27s_totient_function
  https://www.geeksforgeeks.org/eulers-totient-function/
'''

# 모든 합성수는 그 수의 제곱근 이하의 약수를 적어도 한 개 가진다.

# default ver
def EulerPhi(n) :
    euler = n
    prime = 2
    while prime * prime <= n :                        
        if n % prime == 0:
            euler = euler // prime * (prime - 1)
            while n % prime == 0 : n //= prime
        prime += 1
    return euler if n == 1 else euler // n * (n - 1)  

  #만약 n이 소수이거나, n이 sqrt(n)보다 큰 약수를 가지는 경우(최대 1번)

# simple ver
def EulerPhi(n) :
    euler = n
    prime = 2
    while prime * prime <= n :
        if n % prime == 0:
            euler -= euler // prime
            while n % prime == 0 : n //= prime
        prime += 1
    return euler if n == 1 else euler - euler // n
  
#get EuelrPhi value List
# ϕ(n) == eulerList[n]
def EulerPhiList(n) :
    eulerList = [i for i in range(n + 1)]
    for i in range(2, n + 1) :
        if eulerList[i] == i :
            for j in range(i, n, i) :
                eulerList[j] -= eulerList[j] // i
    return eulerList
