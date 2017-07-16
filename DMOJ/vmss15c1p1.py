import math
a = int(input())
factors = []
i = a
while(i > 0):
    if a % i == 0:
        factors.append(i)
    i -= 1
    
b = math.ceil(math.sqrt(a))
c = 0
while not c:
    if b in factors:
        for f in factors:
            if b*f == a:
                c = f
    else:
        b+=1


print("{}".format(2*b+2*c))