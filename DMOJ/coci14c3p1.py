m = input().lower()
s = "1qaz2wsx3edc4rfv5tgb6yhn7ujm8ik,9ol.0-=p[];'/"
def finger(char):
    a = s.index(char)
    if a < 4:
        return 0
    elif a < 8:
        return 1
    elif a < 12:
        return 2
    elif a < 20:
        return 3
    elif a < 28:
        return 4
    elif a < 32:
        return 5
    elif a < 36:
        return 6
    else:
        return 7
        
fingers = [0]*8
for c in m:
    fingers[finger(c)] += 1

for f in fingers:
    print(f)