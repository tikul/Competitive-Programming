import sys
input = sys.stdin.readline
r= int(input())
c = int(input())
grid = [input().strip() for i in range(r)]
newgrid = [["" for i in range(c)] for i in range(r)]
m = int(input())
moves = [input().strip() for i in range(m)]
ll = [(-1,0), (0,1), (1,0), (0,-1)] #right = right, l = l

for i,row in enumerate(grid):
    for j,col in enumerate(row):
        if col == "X":
            newgrid[i][j] = "X"
        else:
            for dir in range(4):
                cur = dir
                pos = [i,j]
                possible = True
                for lol in moves[::-1]:
                    if lol == "F":
                        a,b = ll[cur]
                        pos[0] += a
                        pos[1] += b
                        if pos[0] < 0 or pos[0] >= r or pos[1] < 0 or pos[1] >= c or grid[pos[0]][pos[1]] == "X":
                            possible = False
                            break
                    elif lol == "R":
                        cur = (cur-1)%4
                    else:
                        cur = (cur+1)%4
                if possible:
                    newgrid[i][j] = "*"
                    break
            if not possible:
                newgrid[i][j] = "."

for line in newgrid:
    print("".join(x for x in line))