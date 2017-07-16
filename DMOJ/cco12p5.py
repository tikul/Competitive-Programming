import math
import sys
input = sys.stdin.readline
m = int(input())
per = [int(input()) for i in range(m)]
for y in range(1, 100):
    for p in per:
        a,b = y*p/100 - y/200, y*p/100 + y/200
        if math.ceil(a) != math.floor(b) or math.floor(b) == b:
            break
    else:
        print(y)
        break
else:
    print(100)