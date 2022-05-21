'''
  gcd(a, b) ≥ 1
  gcd(a, b) = gcd(|a|, |b|)
  gcd(|a|, 0) = |a|
  gcd(a, b) = d,  gcd(a/d, b/d) = 1
  gdc(a + kb, b) = gcd(a, b)
'''

def gcd(a, b) :
  return gcd(b, a % b) if b else a

'''
  # Bezout's identity
  ax + by = d에 대해 둘 중 하나는 0이 아닌 정수 a, b가 있다. (d = gcd(a, b))
  i)  ax + by = d를 만족하는 정수해가 반드시 존재한다.
  ii) 
  
  
  ax + by = d를 만족하는 두 정수해(x, y)는 d의 값이 gcd(a, b)의 배수일 때 존재한다.
  d % gcd(a, b) == 0
  즉, 두 정수의 최대공약수는 두 정수를 만족하는 
  두 정수의 최대공약수를 원래 두 수의 배수의 합으로 나타낼 수 있다.
  
'''
