import sys
kb = sys.stdin

n,m,a = [int(e) for e in kb.readline().strip().split()]
nItem = [int(e) for e in kb.readline().strip().split()]
bid = dict()
for i in range(a):
    action = kb.readline().strip().split()
    if action[0] == "B":
        U = int(action[1])
        I = int(action[2])
        V = int(action[3])
        if I not in bid:
            bid[I] = dict()
        bid[I][U] = V
    elif action[0] == "W":
        U = int(action[1])
        I = int(action[2])
        if I in bid:
            if U in bid[I]:
                bid[I].pop(U)

result = [[] for i in range(m)]
for i in bid.keys():
    bidResult = sorted([(v,u) for u,v in bid[i].items()], reverse = True)
    for v,u in bidResult[:nItem[i-1]]:
        result[u-1].append(i)

for item in result:
    if item:
        print(*sorted(item))
    else:
        print("NONE")