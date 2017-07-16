args = input().split()
n = 1

for a in args:
    if a == "not" or a == "False":
        n *= -1

if n==1:
    print("True")
else:
    print("False")