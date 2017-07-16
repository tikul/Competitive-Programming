a = int(input())
b = int(input())
count = 2
while(True):
    c = a-b
    count +=1
    if c > b:
        print(count)
        break
    else:
        a, b = b, c