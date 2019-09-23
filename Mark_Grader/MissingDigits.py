import sys
kb = sys.stdin
line = kb.readline().strip()
num = ["0","1","2","3","4","5","6","7","8","9"]
for i in line:
    if i in num:
        num.remove(i)
if len(num) == 0: print("None")
else: print(",".join(num))