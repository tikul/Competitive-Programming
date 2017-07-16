import sys
def input():
    return sys.stdin.readline().strip()
t = int(input())
order = []
types = {}
for i in range(t):
    a = input()
    order.append(a)
    types[a] = []

n = int(input())
for i in range(n):
    types[input()].append(i+1)

for i in order:
    for lol in types[i]:
        print(lol)