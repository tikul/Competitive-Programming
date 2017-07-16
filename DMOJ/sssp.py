#bellman ford
n,m = map(int, input().split())
edge = {} 
dist = [99999999 for i in range(n)]
dist[0] = 0
for _ in range(m):
    u,v,w = map(int, input().split())
    edge[(u-1,v-1)] = min(w, edge.get((u-1,v-1), 99999999))
    edge[(v-1,u-1)] = min(w, edge.get((v-1,u-1), 99999999))
for i in range(n-1):
    changed = False
    for j in edge.keys():
        u, v = j
        if dist[u] > dist[v] + edge[j]:
            changed = True
            dist[u] = dist[v] + edge[j]
    if not changed:
        break 
for d in dist:
    print(-1 if d == 99999999 else d)