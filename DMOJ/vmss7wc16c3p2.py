def findpath(t, cur, end, path = []):
    if cur in path:
        return False
    if cur == end:
        return True
    if cur not in t.keys():
        return False
    path = path + [cur]
    for road in t[cur]:
        p = findpath(t, road, end, path)
        if p:
            return True
    return False
    
n, m, a, b = [int(a) for a in input().split()]
graph = {}
for _ in range(m):
    x, y = [int(a) for a in input().split()]
    if x not in graph.keys():
        graph[x] = [y]
    else:
        graph[x] += [y]
    if y not in graph.keys():
        graph[y] = [x]
    else:
        graph[y] += [x]


if findpath(graph, a, b):
    print("GO SHAHIR!")
else:
    print("NO SHAHIR!")