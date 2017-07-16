import math
from heapq import *

def dist(y, x):
    return math.sqrt((y-startr)**2 + (x-startc)**2)
    
row,col = map(int, input().split())
grid = [[0 for j in range(col)] for i in range(row)]
for r in range(row):
    t= input().split()
    for c in range(col):
        if t[c] == "X":
            startr, startc = r, c
        elif t[c] != '.':
            grid[r][c] = int(t[c])

tallest = 0
tallr, tallc = -1, -1
for r in range(row):
    for c in range(col):
        if grid[r][c] > tallest:
            tallest = grid[r][c]
            tallr, tallc = r, c
        elif grid[r][c] == tallest:
            if dist(r, c) < dist(tallr, tallc):
                tallr, tallc = r, c
  
visited = [[0 for j in range(col)] for i in range(row)]            
q = [(0, 0, (startr, startc))] #heights, trees cut, pos
while(q):
    h, t, pos = heappop(q)
    r,c = pos
    if not visited[r][c]:
        visited[r][c] = 1
        if pos == (tallr, tallc):
            break
        if r+1 < row:
            heappush(q, (h+grid[r+1][c], t+(grid[r+1][c]!=0), (r+1, c)))
        if r > 0:
            heappush(q, (h+grid[r-1][c], t+(grid[r-1][c]!=0), (r-1, c)))
        if c+1 < col:
            heappush(q, (h+grid[r][c+1], t+(grid[r][c+1]!=0), (r, c+1)))
        if c > 0:
            heappush(q, (h+grid[r][c-1], t+(grid[r][c-1]!=0), (r, c-1)))
            
print(t-1)