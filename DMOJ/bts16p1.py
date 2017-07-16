test = input()
upper = 0
lower = 0

for i in test:
    if i.isupper():
        upper +=1
    elif i.islower():
        lower +=1

if lower > upper:
    print( test.lower() )
elif upper > lower:
    print(test.upper())
else:
    print(test)