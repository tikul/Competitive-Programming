import sys
input = sys.stdin.readline
n, h = map(int, input().split())
field = []
for _ in range(n):
    field.append([int(a) for a in input().split()])

q = [(0,0)] #look for n-1, n-1
visited = set()
found = False
while(q):
    r, c = q.pop()
    if (r,c) == (n-1, n-1):
        found = True
        break
    if r +1 < n and abs(field[r+1][c] - field[r][c]) <= h and (r+1,c) not in visited:
        q.append((r+1, c))
    if c + 1 < n and abs(field[r][c+1] - field[r][c]) <= h and (r,c+1) not in visited:
        q.append((r, c+1))
    visited.add((r,c))

print("yes" if found else "no")