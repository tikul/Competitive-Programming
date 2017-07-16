from itertools import permutations
c = [(1,7), (1,4), (2,1), (3,4), (3,5)]
done = False
while(not done):
    temp_c = (int(input()), int(input()))
    if temp_c == (0,0):
        done = True
    else:
        c.append(temp_c)

for p in permutations([1,2,3,4,5,6,7]):
    done = True
    for con in c:
        if p.index(con[0]) > p.index(con[1]):
            done = False
            break
    if done:
        ans = p
        break

if done:
    print(*ans)
else:
    print("Cannot complete these tasks. Going to bed.")