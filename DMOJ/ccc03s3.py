flooring = int(input())
r = int(input())
c = int(input())
grid = [list(input()) for i in range(r)]
def getfloor(i, j):
    grid[i][j] = "I"
    squares = 1
    if i+1 < r and grid[i+1][j] == ".":
        squares += getfloor(i+1, j)
    if i-1 >= 0 and grid[i-1][j] == ".":
        squares += getfloor(i-1, j)
    if j+1 < c and grid[i][j+1] == ".":
        squares += getfloor(i, j+1)
    if j-1 >= 0 and grid[i][j-1] == ".":
        squares += getfloor(i, j-1)
    return squares

rooms = []
for i in range(r):
    for j in range(c):
        if grid[i][j] == ".":
            rooms.append(getfloor(i,j))

rooms.sort(reverse = True)
possible = 0
while(possible < len(rooms) and flooring >= rooms[possible]):
    flooring -= rooms[possible] 
    possible += 1
xd = {1: ""}
print("{} room{}, {} square metre(s) left over".format(possible, xd.get(possible, "s"), flooring))