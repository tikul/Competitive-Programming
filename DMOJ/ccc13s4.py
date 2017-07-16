import sys
input = sys.stdin.readline
n,m = map(int, input().split())
comp = [[] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int, input().split())
    comp[a].append(b)
p,q = map(int, input().split())
checked = [p]
found = False
while(not found and checked):
    person = checked.pop(0)
    for x in comp[person]:
        if x not in checked:
            checked.append(x)
    if q in checked:
        found = True

if not found:
    checked = [q]
    while(not found and checked):
        person = checked.pop(0)
        for x in comp[person]:
            if x not in checked:
                checked.append(x)
        if p in checked:
            found = True
    print("no" if found else "unknown")
else:
    print("yes")