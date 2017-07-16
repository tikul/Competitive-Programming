import sys
import math
input = sys.stdin.readline

n = int(input())
all_factors = {}
def getfactors(num):
    if num in all_factors.keys():
        return all_factors[num]
    if num == 1:
        return []
    facts = []
    for i in range(2, math.floor(math.sqrt(num)) + 1):
        if num % i == 0:
            facts += ([i] + getfactors(num/i))
            break
    else:
        facts += [int(num)]
    all_factors[num] = facts
    return facts
for _ in range(n):
    a = int(input())
    print(*getfactors(a))