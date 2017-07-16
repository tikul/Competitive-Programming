m = int(input())
q = int(input())
names = []
times = []
memo = {q:0}
people = {}
for _ in range(q):
    names.append(input())
    times.append(int(input()))
c = sum(times)
def dp(x):
    if x in memo.keys():
        return memo[x]
    low = c
    for j in range(x+1, min(q+1, x+m+1)):
        a = max(times[x:j]) + dp(j)
        if a < low:
            low = a
            people[x] = [j] + people.get(j, [])
    memo[x] = low
    return memo[x]

ways = dp(0)
split = [0] + people[0]
print("Total Time:", ways)
for i in range(len(split)-1):
    print(*names[split[i]:split[i+1]])