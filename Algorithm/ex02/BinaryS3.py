import sys , math
kb = sys.stdin

n , m = [int(e) for e in kb.readline().strip().split()]
elements = [int(e) for e in kb.readline().strip().split()]
queries = [int(e) for e in kb.readline().strip().split()]

def binarySearch( sElement , sQuery , left , right ):
    if left >= right or right - left == 1:
        if left < right:
            if sQuery >= sElement[right]:
                return right
            else:
                return left
        else:
            if sQuery >= sElement[left]:
                return left
            else:
                return right
    mid = (left+right)//2
    if sQuery == sElement[mid]:
        if mid + 1 < n:
            if sQuery == sElement[mid+1]:
                return binarySearch( sElement , sQuery , mid+1 , right)
            else:
                return mid
    elif sQuery > sElement[mid]:
        return binarySearch( sElement , sQuery , mid , right) 
    else:
        return binarySearch( sElement , sQuery , left , mid-1)

for query in queries:
    if query < elements[0]:
        print(-1)
    else:
        print(binarySearch(elements,query,0,n-1))