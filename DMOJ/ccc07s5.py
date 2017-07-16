import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n, k, w = map(int, input().split())
    dp = [[0 for i in range(k+1)] for i in range(n+1)] #[pins][balls_used]
    sa = [0 for i in range(n+1)]
    for i in range(1, n+1):
        a = int(input())
        sa[i] = a+sa[i-1]
    for b in range(1, k+1):
        for p in range(n+1):
            if p-w >= 0: 
                dp[p][b] = max(dp[p-1][b], dp[p-w][b-1] + sa[p]-sa[p-w])

    print(dp[n][k])