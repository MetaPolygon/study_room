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
  ax + by = d를 만족하는 두 정수해(x, y)는 d의 값이 gcd(a, b)의 배수일 때 존재한다.
  d % gcd(a, b) == 0
  gcd(a, b) = gcd(b, )
  a = bq + r₁
  b = r₁q + r₂
  r1 = r₂q + r₃
  .
  .
  R(i-1) = R(i)Q(i) + R(i+1) .....(1)
  
  R(i+1) = 0, gcd(a, b) = R(i) = d
  
  R(i) = AS(i) + BT(i) = D .....(2)
  r0 = a, s0 = 1, s1 = 0   # a*s0 + b*s0 = r0 
  r1 = b, t0 = 0, t1 = 1   # a*t1 + b*t1 = r1
  
  (1)
  R(i+1) = R(i-1) - R(i)Q(i)
  
  (1) ← (2)
  S(i+1)A + T(i+1)B
  = (S(i-1)A + T(i-1)B) - (S(i)A + T(i)B)Q(i)
  = (S(i-1)A - S(i)Q(i))A + (T(i-1)B -T(i)Q(i))B
'''
# gcd(a, b) = 1
# ax + by = d
# return (s, t) = (x, y) or (-1, -1)

def exEuclid(a, b) : 
    def onTimeGCD(a, b, q) : return (b, a - q * b)
    d0, d1 = a, b
    s0, s1 = 1, 0
    t0, t1 = 0, 1
    while d1 :
        q = d0 // d1
        d0, d1 = onTimeGCD(d0, d1, q)
        s0, s1 = onTimeGCD(s0, s1, q)
        t0, t1 = onTimeGCD(t0, t1, q)
    return ((s0, t0), (s0 + b, t0 - a))[s0 <= 0] if d0 == 1 else (-1, -1)

