n = int(input())
a = [i for i in input().split()]
b = [i for i in input().split()]
c = {}
for i, _  in enumerate(b):
    c[_] = a[i]
good = True
for key, val in c.items():
    if key != c[val] or key == val:
        good = False
        break
   
print("good" if good else "bad")