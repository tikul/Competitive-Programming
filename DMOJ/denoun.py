a_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
n = int(input())
lines = [input() for i in range(n)]
nouns = [0 for i in range(n)]

for i, l in enumerate(lines):
    for w in l:
        if w[0] in a_upper:
            nouns[i] += 1


for noun in nouns:
    print(noun)