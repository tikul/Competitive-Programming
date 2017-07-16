n = int(input())
grid = []
dp = [[0 for j in range(n)] for i in range(n)]
for i in range(n):
    grid.append([int(a) for a in input().split()])

dp[0][0] = grid[0][0]
for i in range(n-1):
    for j in range(i+1):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + grid[i+1][j])
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + grid[i+1][j+1])
        
print(max(dp[n-1]))