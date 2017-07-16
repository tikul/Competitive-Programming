t = int(input())
for _ in range(t):
    n = int(input())
    s = "{0:b}".format(n)
    for i in s:
        if i=="1":
            print("dank", end = " ")
        else:
            print("meme", end = " ")
    print()