
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
  (3-2) ϕ(p^k) = p^(k - 1) * (p - 1) = p^k - p^(k - 1)
  (4)   Σ ϕ(d) = n                      {d | n}
  (5)   Σ dμ(n/d) = ϕ(n)
  (6)   a^ϕ(n) ≡ 1 (mod n)              {gcd(m, n) = 1}
  (7)   ϕ(n)이 2의 거듭제곱수일 때, 정 n각형은 눈금없는 자와 컴퍼스로 작도할 수 있다.
  
  [reference]
  https://en.wikipedia.org/wiki/Euler%27s_totient_function
  https://www.geeksforgeeks.org/eulers-totient-function/
*/

// default ver
int eulerPhiFunc(int n)                               // ϕ(n)
{
  int euler = n;
  for (int prime = 2; prime * prime <= n; ++prime)    // 모든 합성수는 그 수의 제곱근 이하의 약수를 적어도 한 개 가진다.
    if (n % prime == 0) {
      euler = euler / prime * (prime - 1);
      while (n % prime == 0) n /= prime;
    }
  return n == 1 ? euler : euler / n * (n - 1);        // 만약 n이 소수이거나, n이 sqrt(n)보다 큰 약수를 가지는 경우(최대 1번)
}

int eulerPhiFunc(int n)
{
  int euler = n;
  for (int prime = 2; prime * prime <= n; ++prime)
    if (n % prime == 0) {
      euler -= euler / prime;
      while (n % prime == 0) n /= prime;
    }
  return euler + (n > 1 ? - (euler / n) : 0);
}

int* eulerArr(int n)
{
  int size = n + 1;
  int *temp = (int*)malloc(size * sizeof(int));
  for (int i = 0; i < size; ++i) temp[i] = i;
  for (int i = 2; i < size; ++i)
    if (temp[i] == i) 
      for (int j = i; j < size; j += i)
        temp[j] = temp[j] / i * (i - 1);
        
  int *euler_arr = (int*)malloc(n * sizeof(int));
  memcpy(euler_arr, temp + 1, sizeof(int) * n);
  free(temp);
  return euler_arr;
}
