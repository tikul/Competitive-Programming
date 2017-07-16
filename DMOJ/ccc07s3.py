import sys
input = sys.stdin.readline

n = int(input())
friends = {}
for _ in range(n):
    a, b = map(int, input().split())
    friends[a] = b

while(1):
    a, b = map(int, input().split())
    if a == 0:
        break
    if a not in friends.keys() or b not in friends.keys():
        print("No")
    else:
        sep = 0
        x = friends[a]
        found = False
        while(x != a):
            if x == b:
                found = True
                break
            x = friends[x]
            sep += 1
        if found:
            print("Yes", sep)
        else:
            print("No")