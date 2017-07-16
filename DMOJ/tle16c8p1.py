t = input()
t = t[1:]
n = int(input())
for _ in range(n):
    good = True
    s = input()
    for i in t:
        if i not in s:
            good = False
            break
    print("yes" if good else "no")