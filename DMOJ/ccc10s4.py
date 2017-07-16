from heapq import *
m = int(input())
temp_edges = {}
weights = {}
edges = {}
graph = {i:[] for i in range(m+1)}
for pen in range(m):
    ok = [int(a) for a in input().split()]
    e = ok.pop(0)
    for i in range(e):
        a,b = ok[i], ok[(i+1)%e]
        if (a,b) in temp_edges:
            temp_edges[(a,b)].append(pen)
        elif (b,a) in temp_edges:
            temp_edges[(b,a)].append(pen)
        else:
            temp_edges[(a,b)] = [pen]
            weights[(a,b)] = ok[i+e]

for k,v in temp_edges.items():
    if len(v) == 1:
        graph[m].append(v[0])
        graph[v[0]].append(m)
        edges[(v[0],m)] = min(edges.get((v[0],m), 99999999), weights[k])
    elif len(v) == 2:
        graph[v[0]].append(v[1])
        graph[v[1]].append(v[0])
        edges[(v[0],v[1])] = min(edges.get((v[0],v[1]), 99999999), weights[k])

mst = 0
out = 0
outcount = 0
q = []
heappush(q, [0, 0, -1]) #dist, node, prev node
visited = set()
while(q):
    d, node, prev = heappop(q)
    if node not in visited:
        if node == m or prev == m:
            if outcount == 0:
                out = d
            outcount += 1
        for n in graph[node]:
            if (node,n) in edges:
                heappush(q, [edges[(node,n)], n, node])
            else:
                heappush(q, [edges[(n, node)], n, node])
        mst += d
        visited.add(node)

print(mst-out if outcount < 2 else mst)