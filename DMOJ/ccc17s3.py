n = int(input())
wood = [int(a) for a in input().split()]
lens = {i+1: 0 for i in range(2000)}
for w in wood:
    lens[w] += 1

best = [0, 0] 
for board in range(2, 4001):
    meme = 0
    for w in range(1, board):
        if w in lens and board-w in lens:
            meme += min(lens[w], lens[board-w])
    if meme > best[0]:
        best = [meme, 1]
    elif meme == best[0]:
        best[1] += 1

print(int(best[0]/2), best[1])