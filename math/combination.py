'''
    what is 'nCk' ??
    The number of combinations for selecting 'K' subsets from a set of 'N' elements
    is called binomial coefficients.
  
    C(n, k) =  nCk  =  P(n, k) / k!  =  n! / k! * (n - k)! = n! - (n - k)! / k!
            =  C(n, n - k)
            =  C(n - 1, k - 1) + C(n - 1, k)
            =  C(n + 1, k    ) - C(n, k - 1)
            =  C(n + 1, k + 1) - C(n, k + 1)
           
    C(n - 1, k - 1) + C(n - 1, k)       
    n == k is return 1
    k == 1 is return n
    but it's a lot of recursive calls
'''   
    
# Using Fermat's little theroem
def combination(n, k, mod_prime) :
    sub_fac = 1
    for i in range(n, n - k, -1) : sub_fac = sub_fac * i % mod_prime
    fac = 1
    for i in range(k, 1, -1) : fac = fac * i % mod_prime
    return sub_fac * pow(fac, mod_prime - 2, mod_prime) % mod_prime
