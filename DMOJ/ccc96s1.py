def factors(n):
    f = [1]
    d = 2
    while (n != d):
        if n %d == 0:
            f.append(d)
        d+= 1
    return f
n = int(input())
for _ in range(n):
    num = int(input())
    c = sum(factors(num))
    if num == c:
        print("{} is a perfect number.".format(num))
    elif c < num:
        print("{} is a deficient number.".format(num))
    else:
        print("{} is an abundant number.".format(num))