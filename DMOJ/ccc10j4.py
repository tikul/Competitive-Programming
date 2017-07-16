import math
def chunks(lst, n):
    return [lst[i:i+n] for i in range(0,len(lst),n) ]

stuff = []
while(1):
    pattern = [int(x) for x in input().split()]
    if pattern == [0]:
        break
    n = pattern.pop(0)
    step = [pattern[i] - pattern[i-1] for i in range(1, n)]
    prefix = step[:]     
    suffix = []
    longest = 0
    while(len(prefix) - len(suffix) >= 2):
        suffix.insert(0, prefix.pop())
        if suffix == prefix[:len(suffix)]:
            longest = len(suffix)
    if not longest:
        stuff.append(len(step))
        continue
    step = step[:-longest]
    done = False
    shortest = step[:]
    while(not done):
        done = True
        for i in range(math.floor(len(shortest)/2), 1, -1):
            if len(shortest) % i == 0:
                temp = chunks(shortest, i)
                if temp.count(temp[0]) == len(temp):
                    shortest = temp[0]
                    done = False
                    break

    if shortest.count(shortest[0]) == len(shortest):
        stuff.append(1)
    else:
        stuff.append(len(shortest))

print(*stuff, sep="\n")