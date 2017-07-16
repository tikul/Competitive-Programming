t = int(input())
n = int(input())
types = [[] for i in range(t+1)] #cost,val
for _ in range(n):
    c,v,tt = map(int, input().split())
    types[tt].append((c,v))
budget = int(input())
dp = [[0 for i in range(budget+1)]] + [[-1 for i in range(budget+1)] for i in range(t)]
for i in range(1, t+1):
    for j in range(budget+1):
        bestVal = -1
        for k in types[i]:
            cost,val = k
            if cost <= j and dp[i-1][j-cost] != -1 and val+dp[i-1][j-cost] > bestVal:
                bestVal = val+dp[i-1][j-cost]
        dp[i][j] = bestVal
print(dp[t][budget])