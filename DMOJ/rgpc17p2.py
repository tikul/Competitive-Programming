import sys
input = sys.stdin.readline
n,m,q = map(int, input().split())
s = {0:[0,0]}
c = 0
prev = 0
for i in input().split():
    c += int(i)
    s[int(i)] = [c, prev]
    prev = int(i)

for _ in range(q):
    a,b = map(int, input().split())
    x, y = sorted([a,b], key = lambda x: s[x][0])
    lol = s[y][0]- s[s[x][1]][0]
    print("Enough" if lol/2 >= m else "Not enough")