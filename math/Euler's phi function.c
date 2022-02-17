
/*
  Euler's phi function
  
  n이 양의 정수일 때, ϕ(n)은 n과 서로소인 1부터 n이하의 정수의 개수와 같다. ('p' is prime)
  -----------------------------------------------------
  cnt = 0;
  for (int i = 1, val; i <= n ; i++)
    if ((val = gcd(n, i)) == 1)
      cnt++;
  print("[euelr phi function] retuen val : %d", cnt);
  -----------------------------------------------------  
  ϕ(n) = n ∏ (1 - 1/p)    {'p' is p ∣ n}
  ϕ(mn) = ϕ(m)ϕ(n)
  ϕ(p) = p - 1
  ϕ(p^k) = p^(k - 1) * (p - 1)
*/


int eulerPhiFunc(int n)                               // ϕ(n)
{
  int euler = n;
  for (int prime = 2; prime * prime <= n; prime++)    // 모든 합성수는 그 수의 제곱근 이하의 약수를 가진다.
    if (n % prime == 0) {
      euler = euler / p * (p - 1)
      while (n % prime) n /= prime;
    }
  return n == 1 ? euler : euler / n * (n - 1)         // euler - 1
}                                                     // 만약 n이 소수이면, 위의 loop가 적용되지 않으므로, 공식에 따라 처리해준다.
