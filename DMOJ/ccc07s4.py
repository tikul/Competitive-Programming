import sys, heapq
input = sys.stdin.readline
n = int(input())
outedges = {i:[] for i in range(1,n+1)}
ways = [0 for i in range(n+1)]
ways[1] = 1
a,b = map(int, input().split())
while(a):
    outedges[a].append(b)
    a,b = map(int, input().split())
q = [1]
visited = []
while(q):
    a = heapq.heappop(q)
    if a not in visited:
        for node in outedges[a]:
            ways[node] += ways[a]
            heapq.heappush(q, node)
        visited.append(a)
print(ways[n])