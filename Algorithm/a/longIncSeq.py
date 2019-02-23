import sys
kb = sys.stdin
n = int(input().strip())
s = [int(e) for e in kb.readline().strip().split()]

def lis(s,i,last,d=dict()):
    if s[i] == s[i]-1: return 1
    if i == len(s)-1:
        if s[i] > last: return 1
        else: return 0
    if i == len(s): return float('-inf')
    if (i,last) in d: return d[(i,last)]
    if s[i] > last:
        a = lis(s,i+1,s[i],d) + 1
    else:
        a = lis(s,i+1,last,d)
    b = lis(s,i+1,last,d)
    r = max(a,b)
    d[(i,last)] = r
    return r

result = float('-inf')
for i in range(n):
    result = max(result,lis(s,i,s[i]-1))
print(result)