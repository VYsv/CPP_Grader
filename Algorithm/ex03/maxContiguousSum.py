import sys
n = int(input())
a = [int(e) for e in sys.stdin.readline().strip().split()]
matrix = [0 for i in range(n)]
minT = a[-1]
maxT = a[-1]
matrix[-1] = a[-1]
for i in range(n-2, -1, -1):
    matrix[i] = a[i] + matrix[i-1]
    if matrix[i] < minT: minT = matrix[i]
    if matrix[i] > maxT: maxT = matrix[i]
if maxT == minT: print(maxT)
else: print(maxT - minT)