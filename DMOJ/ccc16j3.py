w = list(input())
w1 = w
w_r = w[::-1]
w_r1 = w_r
a = len(w)
total = 0
for _ in range(a): #shifts
    m = True
    count = 0
    for i, l in enumerate(w_r): #compares
        if m:
            if w_r[i] == w[i]:
                count += 1
                m  = False
        else:
            if w_r[i] == w[i]:
                count +=1
            else:
                break
    if count > total:
        total = count
    w_r = w_r[1:]

for _ in range(a): #shifts
    m = True
    count = 0
    for i, l in enumerate(w1): #compares
        if m:
            if w1[i] == w_r1[i]:
                count += 1
                m  = False
        else:
            if w1[i] == w_r1[i]:
                count +=1
            else:
                break
    if count > total:
        total = count
    w1 = w1[1:]

print(total)