def meme(t, cur, path = []):
    l = len(path)
    if l == 6 and cur == path[0]:
        return True
    if l >= 6:
        return False
    if cur in path:
        return False
    path = path + [cur]
    for p in t[cur]:
        a = meme(t, p, path)
        if a:
            return True
    return False
        
graph = {}
n, m = [int(a) for a in input().split()]
for _ in range(m):
    a, b = [int(a) for a in input().split()]
    if b not in graph.get(a, []):
        graph[a] = graph.get(a, []) + [b]
    if a not in graph.get(b, []):
        graph[b] = graph.get(b, []) + [a]

the_ans = False
for k in graph.keys():
    ans = meme(graph, k)
    if ans:
        the_ans = True
        break
if the_ans:
    print("YES")
else:
    print("NO")