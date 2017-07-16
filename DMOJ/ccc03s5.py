import sys
input = sys.stdin.readline
def findrep(node):
    if cities[node] == node:
        return node
    else:
        cities[node] = findrep(cities[node])
        return cities[node]
    
c, r, d = map(int, input().split())
cities = [i for i in range(c+1)]
ranks = [0 for i in range(c+1)]
edges = []
dests = set()
for _ in range(r):
    a,b,w = map(int, input().split())
    edges.append((w, b, a))
for _ in range(d):
    dests.add(int(input()))
edges.sort(key = lambda x: x[0], reverse=True)
best = edges[0][0]
i = 0
while(dests):
    best, a, b = edges[i]
    r1, r2 = findrep(a), findrep(b)
    i += 1
    if r1 == r2: continue
    if ranks[r1] < ranks[r2]:
        cities[b] = r1
    else:
        if r1 == r2: ranks[r2] += 1
        cities[a] = r2
    if a in dests:
        dests.remove(a)
    if b in dests:
        dests.remove(b)
    
    
print(best)