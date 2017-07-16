q = int(input())
for _ in range(q):
    d = int(input())
    roots = [int(i) for i in input().split()]
    f = [[-root, 1] for root in roots]
    x,y = map(int, input().split())
    for __ in range(d-1):
        a,b = f.pop(), f.pop()
        nf = [0 for i in range(len(a)+1)]
        for i,j in enumerate(a):
            for k,l in enumerate(b):
                 nf[i+k] += j*l
        f.append(nf)
    exp = f[0]
    val = 0
    for i,t in enumerate(exp):
        val += t*(x**i)
    stretch = y/val
    for i in exp[::-1]:
        print(int(i*stretch), end = " ")
    print()