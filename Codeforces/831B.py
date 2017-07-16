first = input()
second = input()

match = {}

for i in range(26):
    match[first[i]] = second[i]
    match[first[i].upper()] = second[i].upper()

conv = input()

ans = ""

for x in conv:
    if x in '0123456789':
        ans += x
    else:
        ans += match[x]

print(ans)
