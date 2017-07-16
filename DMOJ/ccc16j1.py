results = [input() for i in range(6)]
w = results.count("W")
if w == 5 or w == 6:
    print(1)
elif w == 4 or w ==3:
    print(2)
elif w == 2 or w ==1:
    print(3)
else:
    print(-1)