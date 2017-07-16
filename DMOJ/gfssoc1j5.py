import sys
input = sys.stdin.readline
from collections import deque
n, m, t = map(int, input().split())
adj = [[] for i in range(n+1)]
for _ in range(m):
    a,b = map(int, input().split())
    adj[a].append(b)
dp = [[-1 for i in range(n+1)] for j in range(n+1)]
for i in range(1, n+1):
    q = deque([(i, 0)])
    visited = [0 for i in range(n+1)]
    while q:
        u, d = q.popleft()
        if visited[u]: continue
        visited[u] = 1
        dp[i][u] = d
        for v in adj[u]:
            q.append((v, d+1))
q = int(input())     
for _ in range(q):
    a,b = map(int, input().split())
    if dp[a][b] != -1:
        print(t*dp[a][b])
    else:
        print("Not enough hallways!")