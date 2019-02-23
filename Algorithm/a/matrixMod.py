import sys , numpy as np
n , k = [int(e) for e in input().split()]
a = np.matrix([int(e) for e in sys.stdin.readline().split()])
d = dict()
a = a.reshape(2,2)

def MatrixMod(a, n, k):
    if n == 1:
        return a
    if n == 2:
        return np.linalg.matrix_power(a,2)
    result = np.remainder(MatrixMod(a,n//2,k),k)
    result = np.linalg.matrix_power(result,2)
    if n%2 == 0:
        return np.remainder(result,k)
    else:
        result = a@result
        return np.remainder(result,k)
for i in np.ndarray.tolist(MatrixMod(a,n,k)):
    for j in i:
        print(j, end=" ")