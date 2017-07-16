from heapq import *
n,m = map(int, input().split())
graph = {lang: [] for lang in input().split()}
edge = {}
graph["English"] = []
for i in range(m):
    a,b,c = input().split()
    graph[a].append(b)
    graph[b].append(a)
    edge[(a,b)] = int(c)
    edge[(b,a)] = int(c)
q = []
heappush(q, (0, 0, "English"))
visited = set()
total = 0
while(q):
    dist, cost, node = heappop(q)
    if node in visited: continue
    total += cost
    for x in graph[node]:
        heappush(q, (dist+1, edge[(x,node)], x))
    visited.add(node)

print(total if len(visited)==n+1 else "Impossible")