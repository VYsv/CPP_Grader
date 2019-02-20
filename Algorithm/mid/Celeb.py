import sys
kb = sys.stdin

n = int(input())
k = []
for i in range(n):
    k.append([int(e) for e in kb.readline().strip().split()])

N = [0 for e in range(n)]
C = [0 for e in range(n)]
for j in range(n):
    for i in range(n):
        if k[i][j] == 1:
            N[j] += 1
            C[i] += 1
check = False
for i in range(n):
    if N[i] == n-1 and C[i] == 0:
        print(i+1)
        check = True
if check == False:
    print(0)