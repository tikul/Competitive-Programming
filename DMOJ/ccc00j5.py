import re
n = int(input())
graph = {}
re_url = re.compile("<A HREF=\"\\S+\">")
for _ in range(n):
    site = input()
    graph[site] = []
    while(1):
        line = input()
        if line == "</HTML>":
            break
        a = re.findall(re_url, line)
        for o in a:
            togo = o[9:-2]
            graph[site].append(togo)
            print("Link from {} to {}".format(site, togo))
while(1):
    first = input()
    if first == "The End":
        break
    second = input()
    q = [first]
    visited = set()
    can = False
    while(q):
        s = q.pop(0)
        if s in visited: continue
        if s == second:
            can = True
            break
        if s in graph:
            for i in graph[s]:
                q.append(i)
        visited.add(s)
    lol = "" if can else "'t"
    print("Can{} surf from {} to {}.".format(lol, first, second))