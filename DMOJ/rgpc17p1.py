import sys
import math
input = sys.stdin.readline
n,d = map(int, input().split())
def dist(x1, y1, x2, y2):
    return math.sqrt((x1-x2)**2 + (y1-y2)**2)

x,y = map(int, input().split())
max_combo = 1
combo = 1
for i in range(n-1):
    nx,ny = map(int, input().split())
    if dist(nx, ny, x, y) > d:
        max_combo = combo if combo > max_combo else max_combo
        combo = 0
    else:
        combo += 1
    x, y = nx, ny
print(max(combo, max_combo))