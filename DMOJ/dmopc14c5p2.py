n = int(input())
big = 0
for i in range(n):
    a, b = map(int, input().split())
    c = b - a
    if c > big:
        big = c
print(big)