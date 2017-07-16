from itertools import combinations

d = [int(input()) for _ in range(9)]

for _ in combinations(d, 7):
    if sum(_) == 100:
        print(*_, sep = "\n")
        break