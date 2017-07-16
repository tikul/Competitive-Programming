row,col = map(int, input().split())
grid = [[0 for i in range(col)] for j in range(row)]
for r in range(row):
    x = input()
    for c, j in enumerate(x):
        if j == ".":
            grid[r][c] = 1
        else:
            grid[r][c] = 0

best = -1
line = [0 for i in range(col)]
for i in range(row):
    st = []
    st2 = []
    widths = [0 for i in range(col)]
    for j, y in enumerate(grid[i]):
        line[j] = y*line[j] + y
    #find left
    for j, y in enumerate(line):
        while st and y <= line[st[-1]]:
            st.pop()
        if st:
            widths[j] += j - st[-1] -1
        else:
            widths[j] += j
        st.append(j)
    #find right
    for j in range(col-1, -1, -1):
        y = line[j]
        while st2 and y <= line[st2[-1]]:
            st2.pop()
        if st2:
            widths[j] += st2[-1] - j -1
        else:
            widths[j] += col - j - 1
        st2.append(j)
    for j in range(col):
        if line[j]: best = max(best, (widths[j]+1)+line[j])
        
print(2*best-1)