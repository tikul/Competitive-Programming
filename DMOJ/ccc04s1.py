n = int(input())
for i in range(n):
    a,b,c = sorted([input(), input(), input()], key = len)
    if len(set([a,b,c])) != 3:
        print("No")
        continue
    l1, l2, l3 = len(a), len(b), len(c)
    fixfree = True
    if b[:l1] == a or b[:l1] == c:
        fixfree = False
    elif b[l2-l1:] == a or b[l2-l1:] == c:
        fixfree = False
    elif c[:l2] == b or c[:l2] == a:
        fixfree = False
    elif c[l3-l2:] == b or c[l3-l2:] == a:
        fixfree = False
    print("Yes" if fixfree else "No")