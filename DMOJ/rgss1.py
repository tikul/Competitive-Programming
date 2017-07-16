a,b,c = map(int, input().split())
dp = [0 for i in range(c+1)]
dp[0] = 1
for i in range(c+1):
    for j in [a,b]:
        if dp[i] and i + j < c+1:
            dp[i+j] = 1
print(c-dp[::-1].index(1))