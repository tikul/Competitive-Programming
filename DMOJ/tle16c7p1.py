import sys
input = sys.stdin.readline
t = int(input())

def answer(ans):
    print("y' =", ans)

for _ in range(t):
    s = input().strip()
    s = s[4:]
    if "x" not in s:
        answer(0)
        continue
    if "^" not in s:
        if s[:-1] == "-" or s[:-1] == "":
            answer(s[:-1]+"1")
        else:
            answer(s[:-1])
        continue
    pre, after = s.split("x^")
    if pre == "0":
        answer(0)
        continue
    
    if not pre:
        pre = 1
    elif pre == "-":
        pre = -1
    else:
        pre = int(pre)
        
    after = int(after)
    pre *= after
    after -= 1

    if pre == 0:
        answer(0)
        continue
    else:
        pre = str(pre)
        if pre == "1" or pre == "-1":
            pre = pre[:-1]
    
    
    if after == 0:
        if pre == "" or pre == "-":
            pre += "1"
        answer(pre)
    elif after == 1:
        answer(pre+"x")
    else:
        answer(pre+"x^"+str(after))