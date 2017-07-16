n = int(input())
f = 0
s = []
w, ir = 0, 0
for _ in range(n):
    a = input()
    if a == "WA":
        f += 1
    s.append(a)
f = int(f * 0.3)
for _ in s:
    if _ == "AC":
        print("AC")
    elif _ == "TLE":
        print("WA")
    elif _ == "IR":
        if ir < 10:
            print("AC")
        elif ir < 20:
            print("WA")
        else:
            print("IR")
        ir += 1
    else:
        if w < f:
            print("AC")
        else:
            print("WA")
        w += 1