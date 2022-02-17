/*
  gcd(a, b) ≥ 1
  gcd(a, b) = gcd(|a|, |b|)
  gcd(|a|, 0) = |a|
  gcd(a, b) = d,  gcd(a/d, b/d) = 1
  gdc(a + kb, b) = gcd(a, b)
  ax + by = gcd(a, b)
*/

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}
