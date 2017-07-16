t = int(input())
clubs = [int(input()) for i in range(int(input()))]
clubs = sorted(clubs)[::-1]
meme = {}
def f(s, c):
    if s in meme.keys():
        return meme[s]
    if s < 0:
        meme[s] = 5281
        return meme[s]
    if s == 0:
        meme[s] = c
        return meme[s]
    if s > 0:
        meme[s] = min( f(s-club, c +1) for club in clubs )
        return meme[s]

ans = f(t, 0)
if ans > 5280:
    print("Roberta acknowledges defeat.")
else:
    print("Roberta wins in {} strokes.".format(ans))