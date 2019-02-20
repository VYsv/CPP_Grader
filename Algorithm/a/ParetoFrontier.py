import sys , numpy as np
kb = sys.stdin

n = int(input())
a = []
for i in range(n):
    a.append([int(e) for e in kb.readline().strip().split()])
a.sort(key=lambda x:int(x[0]), reverse=True)
maxy = float('-inf')
count = 0
for x,y in a:
    if y > maxy:
        maxy = y
        count += 1
print(count)