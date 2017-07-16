import math

num = int(input())
den = int(input())
factors = []
whole = math.floor(num / den)
num %= den
result = ""

i = 2
tnum = num
while(tnum>1):  
    if (tnum % i == 0):
        tnum /= i
        factors.append(i)
        i = 2
    else:
        i += 1

for factor in factors:
    if den % factor == 0:
        den /= factor
        num /= factor

if not num and not whole:
    result = "0"
if whole:
    result += "{}".format(whole)
if num and whole:
    result += " "
if num:
    result += "{}/{}".format(int(num), int(den))

    
print(result)