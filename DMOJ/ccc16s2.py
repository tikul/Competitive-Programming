t = int(input())
n = int(input())
d = [int(a) for a in input().split()]
p = [int(a) for a in input().split()]

if t ==1:
    d = sorted(d)
    p = sorted(p)
    a = sum(max(d[i], p[i]) for i in range(n))
    print(a)
else:
    d = sorted(d)
    p = sorted(p)[::-1]
    a = sum(max(d[i], p[i]) for i in range(n))
    print(a)