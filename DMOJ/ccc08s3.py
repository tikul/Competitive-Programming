t = int(input())
for _ in range(t):
    r = int(input())
    c = int(input())
    path = [input() for i in range(r)]
    if path[r-1][c-1] == "*":
        print(-1)
        continue
    q = [(0,0)]
    visited = set()
    visited.add((0,0))
    counts = {(0,0): 1}
    while(q):
        row, col = q.pop(0)
        if (row,col) == (r-1, c-1):
            break
        if path[row][col] == "+":
            if row+1 < r and (row+1,col) not in visited:
                visited.add((row+1,col))
                q.append((row+1,col))
                counts[(row+1,col)] = counts[(row,col)] + 1
            if col+1 < c and (row,col+1) not in visited:
                visited.add((row,col+1))
                q.append((row,col+1))
                counts[(row,col+1)] = counts[(row,col)] + 1
            if row-1 >= 0 and (row-1,col) not in visited:
                visited.add((row-1,col))
                q.append((row-1,col))
                counts[(row-1,col)] = counts[(row,col)] + 1
            if col-1 >= 0 and (row,col-1) not in visited:
                visited.add((row,col-1))
                q.append((row,col-1))
                counts[(row,col-1)] = counts[(row,col)] + 1
        elif path[row][col] == "-":
            if col+1 < c and (row,col+1) not in visited:
                visited.add((row,col+1))
                q.append((row,col+1))
                counts[(row,col+1)] = counts[(row,col)] + 1
            if col-1 >= 0 and (row,col-1) not in visited:
                visited.add((row,col-1))
                q.append((row,col-1))
                counts[(row,col-1)] = counts[(row,col)] + 1
        elif path[row][col] == "|":
            if row+1 < r and (row+1,col) not in visited:
                visited.add((row+1,col))
                q.append((row+1,col))
                counts[(row+1,col)] = counts[(row,col)] + 1
            if row-1 >= 0 and (row-1,col) not in visited:
                visited.add((row-1,col))
                q.append((row-1,col))
                counts[(row-1,col)] = counts[(row,col)] + 1
        
    print(counts.get((r-1,c-1), -1))