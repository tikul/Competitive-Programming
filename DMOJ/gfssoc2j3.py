line = input().split()
ans = 0
op = "+"
for c in line:
    if c != "P" and c!= "M" and c != "=":
        ans = eval(str(ans) + op + c)
    elif c == "P":
        op = "+"
    elif c == "M":
        op = "-"

print(ans)