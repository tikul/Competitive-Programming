sq = [[int(a) for a in input().split()] for i in range(4)]

sum1 = sum(sq[0])
magic = all(sum(sq[l]) == sum1 for l in range(4))
if magic:
    magic = all(sq[0][l] + sq[1][l] + sq[2][l] + sq[3][l] for l in range(4))
if magic:
    print("magic")
else:
    print("not magic")