import sys
input = sys.stdin.readline
n,m,k = map(int, input().split())
da = [0 for i in range(n)]
for _ in range(m):
    a,b = map(int, input().split())
    da[a-1] -= 1
    if b < n:
        da[b] += 1
a = [0 for i in range(n+1)]
a[0] = m
for i in range(n):
    a[i+1] = a[i] + da[i] 
a.pop(0)

sa = [0 for i in range(n)]
sa[0] = a[0]
for i in range(1,n):
    sa[i] = sa[i-1] + a[i]
sa.insert(0, 0)

l,r, w = 1, 1, 200002
while(r <= n and l <= r):
    if sa[r] - sa[l-1] >= k:
        if r - l + 1 < w:
            w = r - l + 1
        l += 1
    else:
        r += 1

if k == 0:
    print(0)
else:
    print(-1 if w == 200002 else w)