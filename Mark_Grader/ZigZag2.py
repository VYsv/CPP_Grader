import sys
kb = sys.stdin
cmd = True
zz = 0
num = 1
min1 = min2 = float("inf")
max1 = max2 = float("-inf")
while(cmd):
    line = kb.readline().strip()
    if line == "Zig-Zag": zz = 1
    if line == "Zag-Zig": zz = 2
    if zz != 0: 
        cmd = False
        break
    x,y = [int(e) for e in line.split()]
    if num % 2 == 1:
        if x < min1: min1 = x
        if y > max1: max1 = y
        if y < min2: min2 = y
        if x > max2: max2 = x
    else:
        if y < min1: min1 = y
        if x > max1: max1 = x
        if x < min2: min2 = x
        if y > max2: max2 = y
    num += 1
if zz == 1: print(str(min1)+" "+str(max1))
else: print(str(min2)+" "+str(max2))