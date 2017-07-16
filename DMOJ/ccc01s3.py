def is_alt(t, cur, end, path = []):
    if cur in path:
        return False
    path = path + [cur]
    if cur == end and len(path) == 2:
        return False
    if cur == end:
        return True
    for road in t[cur]:
        p = is_alt(t, road, end, path)
        if p:
            return True
    return False   

def is_path(t, cur, end, ignore, path = []):
    if cur in path or cur == ignore:
        return False
    path = path + [cur]
    if cur == end:
        return True
    for road in t[cur]:
        p = is_path(t, road, end, ignore, path)
        if p:
            return True
    return False
            
def findpath(t, cur, end, path = []):
    if cur in path:
        return None
    path = path + [cur]
    if cur == end:
        return path
    for road in t[cur]:
        p = findpath(t, road, end, path)
        if p:
            return p
    return None
    
graph = {}
while(True):
    r = input()
    a, b = r[0], r[1]
    if a == "*":
        break
    if a not in graph.keys():
        graph[a] = [b]
    else:
        graph[a].append(b)
    if b not in graph.keys():
        graph[b] = [a]
    else:
        graph[b].append(a)

road = findpath(graph, "A", "B")
connecting = []
if(len(road) == 2):
    if not is_alt(graph, "A", "B"):
        connecting.append("AB")
for i in range(1, len(road)-1):
    r = road[:]
    conn = is_path(graph, r[i-1], r[i+1], r[i])
    if not conn:
        conn1 = is_alt(graph, r[i-1], r[i])
        if conn1:
            if r[i] + r[i+1] not in connecting:
                connecting.append(r[i] + r[i+1])
        else:
            if r[i-1] + r[i] not in connecting:
                connecting.append(r[i-1] + r[i])
            conn2 = is_alt(graph, r[i], r[i+1])
            if not conn2:
                if r[i] + r[i+1] not in connecting:
                    connecting.append(r[i] + r[i+1])
for c in connecting:
    print(c)
print("There are {} disconnecting roads.".format(len(connecting)))