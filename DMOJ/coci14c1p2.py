n = int(input())
m = []
for _ in range(n):
    m.append([int(i) for i in input().split()])
    
low_x = min(x[0] for x in m)
high_x = max(x[0] for x in m)

low_y = min(y[1] for y in m)
high_y = max(y[1] for y in m)

s = max((high_x - low_x), (high_y - low_y))


print(s*s)