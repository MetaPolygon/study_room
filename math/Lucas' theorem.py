'''
  Lucas' theorem
  어떤 combination을 소수 p에 대한 법 p상에서 구할 때 O(p^2)안에 구할 수 있는 공식이다.
  mCn ≡ ∏ C(m_i, n_i) (mod p)               {i ∈ {0, 1, """, k (k는 combination의 유효성에 따른다.}
  
  n과 m을 p진법으로 전개했을 때 얻어지는 조합을 이용하면 된다.
  m = m_k * p^k + m_(k - 1) * p^(k - 1) + ... + m_1 * p + m_0
  n = n_k * p^k + n_(k - 1) * p^(k - 1) + ... + n_1 * p + n_0
   
  mCn = C(m_k, n_k) * C(m_(k - 1), n_(k - 1)) * ... * C(m_1, n_1) * C(m_0, n_0)                                     
                                                              
  [reference]
  https://ko.wikipedia.org/wiki/%EB%A4%BC%EC%B9%B4%EC%9D%98_%EC%A0%95%EB%A6%AC
'''
# Using Fermat's little theroem
def combination(m, n, mod_prime) :
    sub_fac = 1
    for i in range(m, m - n, -1) : sub_fac = sub_fac * i % mod_prime
    fac = 1
    for i in range(n, 1, -1) : fac = fac * i % mod_prime
    return sub_fac * pow(fac, mod_prime - 2, mod_prime) % mod_prime

def LucasCombination(m, n, mod_prime) :
    result = 1
    while m or n :
        result = result * combination(m % mod_prime, n % mod_prime, mod_prime) % mod_prime
        m //= mod_prime
        n //= mod_prime
    return result
