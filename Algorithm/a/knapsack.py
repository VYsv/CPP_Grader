import sys
n , m = [int(e) for e in input().strip().split()]
v = [int(e) for e in sys.stdin.readline().strip().split()]
w = [int(e) for e in sys.stdin.readline().strip().split()]
V = [[int(e) for e in sys.stdin.readline().strip().split()] for i in range(n+1)]
x = [0 for i in range(n)] ; count = 0

while V[n][m] != 0:
    if V[n][m] == V[n-1][m]: 
        n -= 1
    elif V[n][m] == V[n-1][m-w[n-1]] + v[n-1]: 
        x[n-1] = 1
        count += 1
        m -= w[n-1]
        n -= 1  
    if V[n][m] == v[n-1]:
        count += 1
        x[n-1] = 1
        break
print(count)
for i in range(len(x)):
    if x[i] == 1: print(i+1, end=" ")

"""def Knapsack(i,v,w,W,d = dict()):
    if W == 0: return 0
    if W < 0: return float('-inf')
    if i == len(v): return float('-inf')
    if (i,W) in d: return d[(i,W)]
    a = Knapsack(i+1,v,w,W-w[i],d)
    b = Knapsack(i+1,v,w,W,d)
    r = max(a,b)
    d[(i,W)] = r
    return r
"""