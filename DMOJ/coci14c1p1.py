n = int(input())
b = [int(i) for i in input().split()]
a = []
t = 0
for _ in range(0, n):
    x = (_+1) * b[_] - t
    a.append(x)
    t += x

print(*a, sep = " ")