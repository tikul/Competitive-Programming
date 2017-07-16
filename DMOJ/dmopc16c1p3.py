import sys
input = sys.stdin.readline
sys.setrecursionlimit(9999999)
n = int(input())
shoes = [int(a) for a in input().split()]
memo = {}
def meme(i):
    if i in memo:
        return memo[i]
    if i >= n:
        return 0
    a = shoes[i] + meme(i+1)
    if i + 1 < n:
        b = sum(shoes[i:i+2])-0.5*min(shoes[i:i+2]) + meme(i+2)
        if b < a:
            a = b
    if i + 2 < n: #taking three
        b = sum(shoes[i:i+3])-min(shoes[i:i+3]) + meme(i+3)
        if b < a:
            a = b
    memo[i] = a
    return a
    
print("{0:.1f}".format(meme(0)))