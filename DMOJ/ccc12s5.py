import sys
input = sys.stdin.readline
r,c = map(int, input().split())
k = int(input())
cats = [[int(a) for a in input().split()] for i in range(k)]

grid = [[-1 for i in range(c+1)] for j in range(r+1)]
grid[r][c] = 1
for cat in cats:
    grid[cat[0]][cat[1]] = 0

for i in range(r, 0, -1):
    for j in range(c, 0, -1):
        if grid[i][j] == -1 and not (i == r and j == c):
            if j == c:
                grid[i][j] = grid[i+1][j]
            elif i == r:
                grid[i][j] = grid[i][j+1]
            else:
                grid[i][j] = grid[i+1][j] + grid[i][j+1]

print(grid[1][1])