n = int(input())
t = int(input())
pumpkins = [int(input()) for i in range(n)]
low, high = -min(pumpkins), max(pumpkins)
pos = [0 for i in range(high+1)]
neg = [0 for i in range(low + 1)]
for i in range(1, high+1):
    pos[i] = pos[i-1] + (i in pumpkins)
for i in range(1, low+1):
    neg[i] = neg[i-1] + (-i in pumpkins)

if t in pos and t in neg:
    if pos.index(t) < neg.index(t):
        print(pos.index(t))
    else:
        print(neg.index(t))
else:
    best = 3001
    for i in range(1, pos[high] + 1):
        if t-i in neg:
            d = 2 * pos.index(i) + neg.index(t-i)
            if d < best:
                best = d
    for i in  range(1, neg[low] +1):
        if t-i in pos:
            d = 2 * neg.index(i) + pos.index(t-i)
            if d < best:
                best = d
    print(best)