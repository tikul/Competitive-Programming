import sys
from collections import deque
input = sys.stdin.readline
n, m = map(int, input().split())
pho = set()
for a in input().split():
    pho.add(int(a))
restaurants = [[] for i in range(n)]
counts = {i:0 for i in range(n)}
for _ in range(n-1):
    a, b = map(int, input().split())
    counts[a] += 1
    counts[b] += 1
    restaurants[a].append(b)
    restaurants[b].append(a)

q = deque([x for x in range(n) if len(restaurants[x])==1])
bad = [0 for i in range(n)]
allbad = 0
visited = set()
while(q):
    node = q.popleft()
    if node in visited: continue
    if node not in pho:
        allbad += 1
        bad[node] = 1
        for adj in restaurants[node]:
            counts[adj] -= 1
            if counts[adj] == 1:
                q.append(adj)
    visited.add(node)
    
for i in range(n):
    if not bad[i]:
        start = i
        break
    
prev = 0
far = -1
q = deque([(start, 0)])
visited = set()
while(q):
    node, depth = q.popleft()
    if node in visited or bad[node]: continue
    for adj in restaurants[node]:
        q.append((adj, depth+1))
    if depth > prev:
        prev = depth
        far = node
    visited.add(node)
    
q = deque([(far, 0)])
dist = 0
visited = set()
while(q):
    node, depth = q.popleft()
    if node in visited or bad[node]: continue
    for adj in restaurants[node]:
        q.append((adj, depth+1))
    dist = max(dist, depth)
    visited.add(node)

print(2*((n-allbad)-dist-1)+dist)