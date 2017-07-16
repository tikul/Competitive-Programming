import sys
input = sys.stdin.readline
n = int(input())
hor = [[0 for i in range(n+1)] for j in range(n+1)]
ver = [[0 for i in range(n+1)] for j in range(n+1)]
bad = [[0 for i in range(n+1)] for j in range(n+1)]

for r in range(n):
    x = input().strip()
    for c, j in enumerate(x):
        bad[r+1][c+1] = 1 if j == "#" else 0
        hor[r+1][c+1] = hor[r+1][c] + bad[r+1][c+1]
        ver[r+1][c+1] = ver[r][c+1] + bad[r+1][c+1]

best = 0
for row in range(1, n):
    for col in range(1, n):
        if bad[row][col]: continue
        for size in range(best+1, n+1-max(row,col)):
            if row+size > n or col+size > n: break
            if (hor[row][col] == hor[row][col+size]
            and hor[row+size][col] == hor[row+size][col+size]
            and ver[row+size][col] == ver[row][col]
            and ver[row+size][col+size] == ver[row][col+size]):
                best = max(best, size)

print(best)