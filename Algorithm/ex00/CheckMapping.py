import sys
kb = sys.stdin

n = int(kb.readline())
s = kb.readline().split()
count = set()

for x in s:
    count.add(int(x))

if len(count) == n and max(count) == n:
    print("YES")
else :
    print("NO")