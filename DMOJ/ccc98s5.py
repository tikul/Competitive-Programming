#dijkstra
from heapq import *
import sys
input = sys.stdin.readline
trips = int(input())
def check(dir):
    global node, n, visited, grid, dists, d, ref, tovisit
    if (0 <=  node+dir < n*n and abs(node%n - (node+dir)%n) <= 1 and 
        node+dir not in visited and abs(grid[node] - grid[node+dir]) <= 2):
        x = dists.pop(node+dir)
        if grid[node] > ref or grid[node+dir] > ref:
            newpair = [min(x[0], d+1), node+dir]
        else:
            newpair = [min(x[0], d), node+dir]
        x[1] = 99999999
        dists[node+dir] = newpair
        heappush(tovisit, newpair)

for _ in range(trips):
    n = int(input())
    grid = [int(input()) for i in range(n*n)]
    visited = set([0])
    dists = {0: [0, 0]}
    tovisit = []
    for i in range(1, n*n):
        pair = [99999999, i]
        dists[i] = pair
        heappush(tovisit, pair)
    heappush(tovisit, [0,0])
    ref = grid[0]
    dirs = [1, -1, n, -n]
    done = False
    while(tovisit):
        d, node = heappop(tovisit)
        if node == 99999999:
            continue
        if d == 99999999:
            break
        if node == n*n -1:
            done = True
            print(d)
            break
        for i in dirs:
            check(i)
        visited.add(node)
    if not done:
        print("CANNOT MAKE THE TRIP")
    if _ != trips-1:
        print()