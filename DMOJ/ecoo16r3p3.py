import sys
input = sys.stdin.readline
n = int(input().strip())
words = set([input().strip() for i in range(n)])
for _ in range(10):
    s = input().strip()
    ls = len(s)
    dp = [99999 for i in range(ls+1)]
    dp[0] = 0
    for i in range(ls+1):
        for j in range(i):
            if s[j:i] in words:
                dp[i] = min(dp[j]+1, dp[i])
    print(dp[-1]-1)