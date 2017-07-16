import sys
input = sys.stdin.readline
gstr = input()
n = int(input())
dp = {-1: 0}
for g in range(len(gstr)):
    if gstr[g] == "G":
        dp[g] = dp[g-1] + 1
    else:
        dp[g] = dp[g-1]

for _ in range(n):
    a, b = map(int, input().split())
    print(dp[b]-dp[a-1])