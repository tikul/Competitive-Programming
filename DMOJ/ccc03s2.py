vowels = "aeiouAEIOU"
v = int(input())
classify = []
        
def get_end(line):
    lastword = line.split()[-1]
    for i, l in enumerate(lastword[::-1]):
        if l in vowels:
            return lastword[len(lastword)-i-1:].lower()
    return lastword

for i, _ in enumerate(range(v)):
    endings = []
    verse = [input() for i in range(4)]
    for __ in verse:
        endings.append(get_end(__))
    if endings.count(endings[0]) == 4:
        classify.append("perfect")
    elif endings[0] == endings[1] and endings[2] == endings[3]:
        classify.append("even")
    elif endings[0] == endings[2] and endings[1] == endings[3]:
        classify.append("cross")
    elif endings[0] == endings[3] and endings[1] == endings[2]:
        classify.append("shell")
    else:
        classify.append("free")

for c in classify:
    print(c)