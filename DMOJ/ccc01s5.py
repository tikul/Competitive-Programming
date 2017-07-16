m = int(input())
n = int(input())
a = [input() for i in range(n)]
b = [input() for i in range(n)]
patterns = [a,b]

def h(c, remaining):
    return str(c) + "-" + remaining

hashes = {}

def solve(seq, c , remaining = None, count = 0):
    if count == m:
        return (99999,)
    if remaining == "":
        return (count, seq)
    if remaining is None:
        remaining = ""
    x = h(c, remaining)
    if x in hashes.keys():
        if hashes[x] == (99999,):
            return hashes[x]
    shortest = (99999,)
    for i in range(n):
        meme = (99999,)
        short, long = patterns[c][i], patterns[1-c][i]
        r, lena, lenb = len(remaining), len(short), len(long)
        if lena <= r and remaining[:lena] == short:
            meme = solve(seq+[i+1], c, remaining[lena:] + long, count+1)
        elif lena > r and short[:r] == remaining:
            if lena - r >= lenb and short[r:r+lenb] == long:
                meme = solve(seq+[i+1], 1-c, short[r+lenb:], count+1)
            elif lena - r < lenb and short[r:] == long[:lena-r]:
                meme = solve(seq+[i+1], c, long[lena-r:], count+1)
        if meme[0] < shortest[0]:
            shortest = meme
    hashes[x] = shortest
    return shortest

stuff = solve([], 1)
if stuff[0] == 99999:
    print("No solution.")
else:
    print(stuff[0])
    print(*stuff[1], sep = "\n")