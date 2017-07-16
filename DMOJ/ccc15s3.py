import sys
input = sys.stdin.readline
g = int(input())
p = int(input())
def find(x):
    if rep[x] == x:
        return x
    else:
        rep[x] = find(rep[x])
        return rep[x]
rep = [i for i in range(g+1)]
total = 0
for i in range(p):
    plane = int(input())
    a = find(plane)
    if a != 0:
        total += 1
        rep[a] = find(a-1)
    else:
        break

print(total)