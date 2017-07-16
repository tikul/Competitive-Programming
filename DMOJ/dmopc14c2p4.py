import sys
input = sys.stdin.readline
n = int(input())
sa = [0 for i in range(n+1)]
for i in range(1, n+1):
    t = int(input())
    sa[i] = sa[i-1]+t
q = int(input())
for _ in range(q):
    a,b = map(int, input().split())
    print(sa[b+1]-sa[a])