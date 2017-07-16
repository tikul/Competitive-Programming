n, t = map(int, input().split())
graph = {"home": [], "Waterloo GO": []}
for _ in range(n):
    graph[input()] = []
for _ in range(t):
    a, b = input().split("-")
    graph[a].append(b)
    graph[b].append(a)

q = ["home"]
visited = []
dist = {"home":0}
while(q):
    key = q.pop(0)
    if key == "Waterloo GO":
        break
    for node in graph[key]:
        if node not in visited and node not in q:
            dist[node] = dist[key]+1
            q.append(node)
    visited.append(key)

if "Waterloo GO" in dist.keys():
    print(dist["Waterloo GO"])
else:
    print("RIP ACE")