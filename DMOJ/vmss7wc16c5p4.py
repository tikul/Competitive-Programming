n = int(input())
things = [int(i) for i in input().split()]

dp = [-1 for i in range(n+1)]
dp[0] = 0
for i in range(n+1):
    if dp[i] != -1:
        for thing in things:
            if i + thing <= n:
                dp[i + thing] = max(dp[i + thing], dp[i] + 1)

print(dp[n])