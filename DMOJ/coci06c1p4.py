row, col = map(int, input().split())

flooded = [[False for i in range(col)] for j in range(row)]
squares = set([(i,j) for i in range(row) for j in range(col)])
rocks = set()
grid = []
for i in range(row):
    x = input()
    for ind, j in enumerate(x):
        if j == "S":
            start = (i, ind, 0)
        elif j == "*":
            flooded[i][ind] = True
        elif j == "D":
            dest = (i, ind)
        elif j == "X":
            rocks.add((i, ind))
    grid.append(x)
    
visited = set()
it = 0
q = [start]
possible = False
while(q):
    r, c, time = q.pop(0)
    if time > it:
        to_change = set()
        for i in range(row):
            for j in range(col):
                if flooded[i][j]: 
                    to_change.add((i+1,j))
                    to_change.add((i,j+1))
                    to_change.add((i-1,j))
                    to_change.add((i,j-1))
        for s in to_change:
            if s in squares and s not in rocks and s != dest:
                flooded[s[0]][s[1]] = True
        it += 1
    if (r,c) == dest:
        possible = True
        break
    if (r,c) not in squares: continue
    if (r,c) in visited: continue
    if flooded[r][c]: continue
    if (r,c) in rocks: continue
    q.append((r+1, c, time+1))
    q.append((r, c+1, time+1))
    q.append((r-1, c, time+1))
    q.append((r, c-1, time+1))
    visited.add((r,c))

print(it if possible else "KAKTUS")