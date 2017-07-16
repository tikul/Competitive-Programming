n = int(input())
for i in range(n):
    text = input().split()
    newtext = ""
    for t in text:
        if len(t) == 4:
            newtext += "**** "
        else:
            newtext += t + " "
    print(newtext)