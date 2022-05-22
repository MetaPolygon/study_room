'''
  Fermat's little theroem
  gcd(a, p) = 1
  (1)   a^p ≡ p (mod p)
  (2-1) a^(p - 1) ≡ 1 (mod p)
  (2-2) a^(p - 2) ≡ a^(-1) (mod p)
  
  -> combination and modular
  nCk = n! / k!(n - k)! = n! * (k!(n - k)!)^(-1)
  (k!(n - k)!)^(p - 2) ≡ (k!(n - k)!)^(-1) (mod p)
  >>> nCk (mod p) =  n! * (k!(n - k)!)^(p - 2) (mod p)
  
  nCk 의 펙토리얼 연산 범위는 줄어들 수 있다.
  nCk = (n! - (n - k)!) / k!
  >>> nCk (mod p) = (n! - (n - k)!) * (k!)^(-1) ≡ (n! - (n - k)!) * (k!)^(p - 2) (mod p)
  
  next -> Euler’s theorem
'''

# = a^(-1)
# Using Fermat's little theroem
def FermatLittleTheroemModular(a, p) :
    return pow(a, p - 2, p) % p

