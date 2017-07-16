square = 1
snakes = [[54, 19], [90, 48], [99,77]]
ladders = [[40, 64], [9, 34], [67, 86]]
win = True
while(square != 100):
    move = int(input())
    if move == 0:
        win = False
        break
    if square + move <= 100:
        square += move
    for l in ladders:
        if square == l[0]:
            square = l[1]
    for s in snakes:
        if square == s[0]:
            square = s[1]
    print("You are now on square {}".format(square))

if win:
    print("You Win!")
else:
    print("You Quit!")