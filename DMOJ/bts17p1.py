line = input().split()
for i, w in enumerate(line):
    if w[0].isupper() and i != 0:
        line[i-1] += "."
    if i == len(line) -1:
        line[i] += "."

print(" ".join(line))