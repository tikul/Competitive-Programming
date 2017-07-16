def knight_positions(start):
    moves = []
    moves.append((start[0]+1, start[1]+2))
    moves.append((start[0]+1, start[1]-2))
    moves.append((start[0]-1, start[1]+2))
    moves.append((start[0]-1, start[1]-2))
    moves.append((start[0]+2, start[1]+1))
    moves.append((start[0]+2, start[1]-1))
    moves.append((start[0]-2, start[1]+1))
    moves.append((start[0]-2, start[1]-1))
    moves = [moves[i] for i in range(8) if 0 < moves[i][0] <= 8 and 0 < moves[i][1] <= 8]
    return moves
    
start = tuple(int(a) for a in input().split())
end = tuple(int(a) for a in input().split())
current = [start]
all_visited = [start]
found = False
moves = 1
if start == end:
    print(0)
else:
    while(True):
        a = len(current)
        b = 0
        while(current and b < a):
            for i in knight_positions(current[0]):
                if i == end:
                    found = True
                    break
                if i not in all_visited:
                    all_visited.append(i)
                    current.append(i)
            if found:
                break
            del current[0]
            b+=1
        if found:
            break
        moves += 1
        
    print(moves)