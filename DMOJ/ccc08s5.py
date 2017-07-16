def patrickCanWin(a,b,c,d):
    k = (a,b,c,d)
    if k in memo:
        return memo[k]
    x = False
    if a >= 2 and b >= 1 and d >= 2:
        x = not patrickCanWin(a-2, b-1, c, d-2)
    if not x and a >= 1 and b >= 1 and c >= 1 and d >=1:
        x = not patrickCanWin(a-1, b-1, c-1, d-1)
    if not x and c >=2 and d >= 1:
        x = not patrickCanWin(a, b, c-2, d-1)
    if not x and b >= 3:
        x = not patrickCanWin(a, b-3, c, d)
    if not x and a >=1 and d >= 1:
        x = not patrickCanWin(a-1, b, c, d-1)
    memo[k] = x
    return memo[k]

memo = {}
n = int(input())
for _ in range(n):
    particles = {}
    pp = [int(i) for i in input().split()]
    if patrickCanWin(*pp):
        print("Patrick")
    else:
        print("Roland")