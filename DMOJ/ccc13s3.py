import itertools
t = int(input())
g = int(input())
scores = [0, 0, 0, 0, 0]
to_play = list(itertools.combinations(range(1,5), 2))
for _ in range(g):
    a, b, s1, s2 = map(int, input().split())
    if (a,b) in to_play:
        to_play.remove((a,b))
    else:
        to_play.remove((b,a))
    if s1 > s2:
        scores[a] += 3
    elif s1 < s2:
        scores[b] += 3
    else:
        scores[a] += 1
        scores[b] += 1

def solve(cur, games, score):
    if cur >= games:
        x = score[t]
        for i in range(1, 5):
            if i == t: continue
            if score[i] >= x:
                return 0
        return 1
    memes = 0
    s = score[:]
    c, d = to_play[cur]
    s[c] += 3
    memes += solve(cur+1, games, s)
    s[c] -=3 
    s[d] += 3
    memes += solve(cur+1, games, s)
    s[d] -= 2
    s[c] += 1
    memes += solve(cur+1, games, s)
    return memes
    
print(solve(0, 6-g, scores))