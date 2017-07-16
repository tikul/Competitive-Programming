import sys
input = sys.stdin.readline
i = int(input())
t = 0
for _ in range(i):
    t += int(input())
s = int(input())
for j in range(1, s+1):
    t += int(input())
    print("{0:.3f}".format(t/(i+j)))