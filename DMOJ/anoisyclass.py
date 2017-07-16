n = int(input())
m = int(input())
graph = {x:[] for x in range(1, n+1)}
def getFrom(s):
    for e in s:
        return e
visited = set()
noisy = set()
for _ in range(m):
    a,b = map(int, input().split())
    graph[a].append(b)
    noisy.add(a)
done = False
while(noisy and not done):
    q = [[getFrom(noisy), []]]
    while(q and not done):
        node, path = q.pop()
        if node in path:
            done = True
            break
        for child in graph[node]:
            q.append([child, path+[node]])
        visited.add(node)
    noisy = noisy - visited
print("N" if done else "Y")