import sys
n = int(input())
a = [int(e) for e in sys.stdin.readline().strip().split()]
count = 0

def mergeSort(arr):
    global count
    if len(arr) > 1:
        mid = len(arr) // 2
        l = arr[:mid]
        r = arr[mid:]
        mergeSort(l)
        mergeSort(r)
        i = j = k = 0
        while i < len(l) and j < len(r):
            if l[i] <= r[j]:
                arr[k] = l[i]
                i += 1
            else:
                count += len(l) - i
                arr[k] = r[j]
                j += 1
            k += 1
        while i < len(l):
            arr[k] = l[i]
            i += 1
            k += 1
        while j < len(r):
            arr[k] = r[j]
            j += 1
            k += 1
    
mergeSort(a)
print(count)