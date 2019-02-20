import sys
kb = sys.stdin

x , n , k = [int(e) for e in kb.readline().strip().split()]

def modExpo(x,n,k):
    if n == 0:
        return 1
    result = modExpo(x,n//2,k)%k
    if n%2 == 0:
        return (result*result)%k
    else:
        return (x*(result*result))%k

print(modExpo(x,n,k))