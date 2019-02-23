import sys
n = int(input()) ; a = [int(e) for e in sys.stdin.readline().strip().split()]
def MCS(a):
    p = a[0] ; s = a[0]
    for i in range(1,len(a)):
        p = max(p+a[i],a[i])
        s = max(p,s)
    return s
print(MCS(a))