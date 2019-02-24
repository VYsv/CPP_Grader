n , k = [int(e) for e in input().strip().split()]

def divide(n,k,d=dict()):
    if n < k: return 0
    if k == 1: return 1
    if (n,k) in d: return d[(n,k)]
    a = k*divide(n-1,k,d)
    b = divide(n-1,k-1,d)
    d[(n,k)] = a + b
    return a + b

print(divide(n,k)% 1997)