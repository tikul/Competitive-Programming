c,m = map(int, input().split())
cages = [[]]
for i in range(c):
    val, cost = map(int, input().split())
    cages.append([cost, val])
    
dp = [[0 for j in range(c+1)] for i in range(m+1)]
for i in range(c+1):
    dp[0][i] = 0
for i in range(m+1):
    dp[i][0] = 0
    
for i in range(1, m+1):
    for j in range(1, c+1):
        cost,val = cages[j]
        dp[i][j] = dp[i][j-1]
        if cost <= i:
            dp[i][j] = max(dp[i][j], val+dp[i-cost][j-1])
           
print(dp[m][c])