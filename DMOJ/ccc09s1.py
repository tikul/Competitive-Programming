import math
a = int(input())
b = int(input())
s = round(math.pow(a, 1/6), 13)
e = round(math.pow(b, 1/6), 13)
print(int(e)-math.ceil(s)+1)