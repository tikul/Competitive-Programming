a = int(input())
b = int(input())
c = int(input())
d = int(input())
s = int(input())

nicky = int(s / (a+b)) * (a-b)
w = s % (a+b)
if w <= a:
    nicky += w
else:
    nicky += 2*a - w

byron = int(s / (c+d)) * (c-d)
w = s % (c+d)
if w <= c:
    byron += w
else:
    byron += 2*c - w
    
if nicky > byron:
    print("Nikky")
elif byron > nicky:
    print("Byron")
else:
    print("Tied")