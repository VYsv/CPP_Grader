r,c=map(int,input().split())
a=[[int(i)for i in input()]for j in range(r)]
for i in range(1,r):
  for j in range(1,c):
    if a[i][j]:a[i][j]+=min(a[i-1][j-1],a[i][j-1],a[i-1][j])
print(max([max(i) for i in a]))
