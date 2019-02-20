n , k = [int(e) for e in input().strip().split()]
c = dict()

def binomialCo(n,k):
    if n == k or k == 0:
        return 1
    if n not in c:
        c[n] = dict()
    if k in c[n]:
        return c[n][k]
    else:
        c[n][k] = binomialCo(n-1,k-1) + binomialCo(n-1,k)
        return c[n][k]
       
print(binomialCo(n , k))