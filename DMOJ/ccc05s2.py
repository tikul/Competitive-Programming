dims = input().split()
dims = [int(i) for i in dims]
cur_pos = [0,0]
done = False
while(not done):
    move = [int(i) for i in input().split()]
    if move == [0, 0]:
        done = True
    else:
        cur_pos[0] += move[0]
        cur_pos[1] += move[1]
        if cur_pos[0] > dims[0]:
            cur_pos[0] = dims[0]
        elif cur_pos[0] < 0:
            cur_pos[0] = 0
        if cur_pos[1] > dims[1]:
            cur_pos[1] = dims[1]
        elif cur_pos[1] < 0:
            cur_pos[1] = 0
        print(*cur_pos)