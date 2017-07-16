def get(p, stops, low, high, ht = {7000: 1}): #pass in cur, m[1:], a, b. Returns total possible ways
    ways = 0
    if p in ht.keys():
        return ht[p]
    for i, stop in enumerate(stops):
        if stop > p + high:
            break
        elif p + low <= stop <= p + high:
            if stop in ht.keys():
                ways += ht[stop]
            else:
                w = get(stop, stops[i:], low, high, ht)
                ways += w
                ht[stop] = w
    return ways
    
motels = [0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000]
a = int(input())
b = int(input())
n = int(input())
for _ in range(n):
    motels.append(int(input()))

motels.sort()

total = get(0, motels[1:], a, b)
print(total)