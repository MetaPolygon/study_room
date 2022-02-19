
/*
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
  (3-2) ϕ(p^k) = p^(k - 1) * (p - 1)
  
*/


int eulerPhiFunc(int n)                               // ϕ(n)
{
  int euler = n;
  for (int prime = 2; prime * prime <= n; prime++)    // 모든 합성수는 그 수의 제곱근 이하의 약수를 가진다.
    if (n % prime == 0) {
      euler = euler / prime * (prime - 1)
      while (n % prime) n /= prime;
    }
  return n == 1 ? euler : euler / n * (n - 1)         // 만약 n이 소수이거나, 
}                                                     
