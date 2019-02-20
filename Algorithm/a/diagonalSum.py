import sys
kb = sys.stdin

n = int(kb.readline().strip())
matrix = []
result = float("-inf")

for i in range(n):
    matrix.append([int(e) for e in kb.readline().strip().split()])

def diagSum(i,j):
    allsum = list()
    dsum = 0
    count = 0
    while i + count < n and j + count < n:
        dsum += matrix[i+count][j+count]
        allsum.append(dsum)
        count += 1
    return max(allsum)

for i in range(n):
    for j in range(n):
        check = diagSum(i,j)
        if check > result:
            result = check
print(result)