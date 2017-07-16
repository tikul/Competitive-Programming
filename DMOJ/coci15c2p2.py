n,m = map(int, input().split())
masks = [0 for i in range(n)]
for _ in range(m):
    a,b = map(lambda x: int(x)-1, input().split())
    masks[a] = masks[a] | 1 << b
    masks[b] = masks[b] | 1 << a

def solve(mask, place):
    total = 0
    if place >= n:
        return 0
    dab = solve(mask, place+1)
    if mask & (masks[place]) != 0:
        total += dab
        return total
    total += 1 + solve(mask | 1 << place, place+1) + (dab)
    return total

print(solve(0,0)+1)