import sys
s1 = list(sys.stdin.readline().strip()) ; s2 = list(sys.stdin.readline().strip())
def LCS(s1,s2):
    m = len(s1)
    n = len(s2)
    l = [[0 for j in range(n+1)] for i in range(m+1)]
    for i in range(1,m+1):
        for j in range(1,n+1):
            if s1[i-1] == s2[j-1]:
                l[i][j] = 1 + l[i-1][j-1]
            else:
                l[i][j] = max(l[i-1][j],l[i][j-1])
    return l[-1][-1]
print(LCS(s1,s2))