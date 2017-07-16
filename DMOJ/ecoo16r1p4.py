import math
from heapq import *
for _ in range(10):
    x0, y0 = map(int, input().split())

    def dist(x,y, x1, y1):
        return math.sqrt((x-x1)**2 + (y-y1)**2)

    neighbours = []
    for _ in range(100):
        a = input().split()
        x, y = map(int, a[:2])
        neighbours.append((x,y,a[2]))

    positions = []
    for y in range(1, 51):
        width = math.floor(math.sqrt(2500 - y**2))
        for x in range(-width, width+1):
            positions.append((x+x0, y+y0))
            positions.append((-x+x0, -y+y0))
    for x in range(x0-50, x0+51):
        positions.append((x, y0))

    democrats = 0
    for p in positions:
        q = []
        for n in neighbours:
            d = dist(n[0], n[1], p[0], p[1])
            if len(q) < 3:
                heappush(q, (-d, n[2]))
            else:
                a = q[0]
                if a[0] < -d:
                    heappushpop(q, (-d, n[2]))
                elif a[0] == -d:
                    heappush(q, (-d, n[2]))
        count = 0
        for i in q:
            if i[1] == "D":
                count += 1
        if count >= len(q)/2:
            democrats += 1

    print("{0:.1f}".format(democrats*100/7845))