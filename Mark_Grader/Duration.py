h1 = int(input())
m1 = int(input())
s1 = int(input())
h2 = int(input())
m2 = int(input())
s2 = int(input())
h3 = h2 - h1 if h2 - h1 >= 0 else h2 - h1 + 23
m3 = m2 - m1 if m2 - m1 >= 0 else m2 - m1 + 59
s3 = s2 - s1 if s2 - s1 >= 0 else s2 - s1 + 59
print(str(h3)+":"+str(m3)+":"+str(s3))