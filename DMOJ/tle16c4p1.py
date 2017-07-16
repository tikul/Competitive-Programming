import sys
import bisect
gifts = []
input = sys.stdin.readline
n = int(input())
for _ in range(n):
    gifts.append(int(input()))

gifts.sort()
sum = 0
boxes = 0
while(gifts):
    s = gifts.pop(0)
    if s >= sum:
        boxes += 1
        sum += s
    else:
        del gifts[:bisect.bisect_left(gifts, sum)]

print(boxes)