def isM(s):
    for i, c in enumerate(s):
        if c == "N":
            b = isA(s[:i]) and isM(s[i+1:])
            if b:
                return True
    return isA(s)

def isA(s):
    if not s:
        return False
    if s == "A":
        return True
    if s[0] == "B" and s[-1] == "S":
        return isM(s[1:-1])
    return False

word = input()
while(word != "X"):
    print("YES" if isM(word) else "NO")
    word = input()