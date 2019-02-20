import sys
kb = sys.stdin

n,m = [int(e) for e in kb.readline().split()]
r = int(kb.readline().strip())
matrix = list()

for i in range(n):
    matrix.append([int(e) for e in kb.readline().strip().split()])

for j in range(r):
    r1,c1,r2,c2 = [int(e) for e in kb.readline().strip().split()]
    if c1 > c2 or r1 > r2:
        print("INVALID")
    elif r1 > n or c1 > m:
        print("OUTSIDE")
    else:
        if(r2 > n): r2 = n
        if(c2 > m): c2 = m
        target = float("-inf")
        count = -1
        for i in range(r2 - r1 + 1):
            if target < max(matrix[r1 + count][c1 - 1:c2]):
                target = max(matrix[r1 + count][c1 - 1:c2])
            count += 1
        print(target)