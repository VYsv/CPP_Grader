import sys
kb = sys.stdin

n,target = [int(e) for e in kb.readline().strip().split()]
coins = [int(e) for e in kb.readline().strip().split()]
coins.sort()

def exchange(n,coins,target):
    matrix = [[0 for j in range(target+1)] for i in range(n)]
    for i in range(n):
        for j in range(1,target+1):
            if j >= coins[i]:
                if i > 0:
                    matrix[i][j] = min(matrix[i-1][j] , 1 + matrix[i][j-coins[i]])
                else:
                    matrix[i][j] = j
            else:
                matrix[i][j] = matrix[i-1][j]
    return matrix[-1][-1]
print(exchange(n,coins,target))