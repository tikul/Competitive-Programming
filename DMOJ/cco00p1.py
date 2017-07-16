n = int(input())
ds = [[] for i in range(26)]
ss = [set() for i in range(26)]
after = [set() for i in range(26)]
sets = [0 for i in range(26)]
num = lambda x: ord(x)-65
for _ in range(n):
    a,b = input().split(" contains ")
    sets[num(a)] = 1
    if b.isupper():
        ds[num(a)].append(num(b))
        sets[num(b)] = 1
    else:
        ss[num(a)].add(b)


for i in range(26):
    if not sets[i]: continue
    things = set(ss[i])
    visited = [0 for i in range(26)]
    q = [i]
    while(q):
        u = q.pop()
        if visited[u]: continue
        for v in ds[u]:
            if v < i: things |= after[v]
            else:
                things |= ss[v]
                q.append(v)
        visited[u] = 1
    after[i] = things
    s = ",".join(x for x in sorted(things))
    print("{} = {{{}}}".format(chr(i+65), s))