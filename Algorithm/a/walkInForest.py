import sys
kb = sys.stdin

n,m = [int(e) for e in kb.readline().strip().split()]
f = [[int(e) for e in kb.readline().strip().split()] for i in range(n)]

def walk(i,j):
    x=y=diag = int()
    if i > 0:
        x = f[i][j] + f[i-1][j]
    if j > 0:
        y = f[i][j] + f[i][j-1]
    if i > 0 and j > 0:
        diag = 2*f[i][j] + f[i-1][j-1]
    if i != 0 or j != 0:
        f[i][j] = max(x,y,diag)
for i in range(n):
    for j in range(m):
        walk(i,j)
print(f[-1][-1])

print("Frame x Lace")