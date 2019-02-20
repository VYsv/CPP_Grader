import sys
kb = sys.stdin

n , m , k = [int(e) for e in kb.readline().strip().split()]
A = []
for i in range(n):
    A.append([int(e) for e in kb.readline().strip().split()])

p = [[0 for j in range(m)] for i in range(n)]
p[0][0] = A[0][0]
for j in range(1,m):
    p[0][j] = p[0][j-1] + A[0][j]
for i in range(1,n):
    p[i][0] = p[i-1][0] + A[i][0]
    for j in range(1,m):
        p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + A[i][j]
def P(a,b):
    if a < 0:
        return 0
    if b < 0:
        return 0
    return p[a][b]

for i in range(k):
    r1,c1,r2,c2 = [int(e) for e in kb.readline().strip().split()]
    print(P(r2,c2) - P(r1-1,c2) - P(r2,c1-1) + P(r1-1,c1-1))