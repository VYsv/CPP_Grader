import sys , math
kb = sys.stdin

n , m = [int(e) for e in kb.readline().strip().split()]
elements = [int(e) for e in kb.readline().strip().split()]
queries = [int(e) for e in kb.readline().strip().split()]

def binarySearch( sElement , sQuery , left , right ):
    if left > right:
        return sElement[right]
    mid = (left+right)//2
    if sQuery == sElement[mid]:
        return sQuery
    elif sQuery > sElement[mid]:
        return binarySearch( sElement , sQuery , mid+1 , right) 
    else:
        return binarySearch( sElement , sQuery , left , mid-1)

for query in queries:
    if query < elements[0]:
        print(-1)
    else:
        print(binarySearch(elements,query,0,n-1))