translate = {"I": 1, "V": 5, "X": 10, "L": 50, "C":100, "D": 500, "M": 1000}
line = input()
num = 0
prev_a, prev_r = 0, 1001
for i, p in enumerate(line[::2]):
    a, r = int(p), line[2*i+1]
    t = translate[r]
    if t > prev_r:
        num -= 2* prev_a*prev_r
    num += a*t
    prev_r = t
    prev_a = a

print(num)