n = int(input())

def GAA(n):
    prev = 0; gaa = 3; k = 1
    while gaa < n:
        prev = gaa
        gaa += 1 + 2 + k + gaa
        k += 1
    if prev+1 == n: return 'g'
    if prev+1 < n <= prev+k+2: return 'a'
    return GAA(n - prev - 2 - k)

print(GAA(n))