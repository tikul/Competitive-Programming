length = int(input())
log = input()
k = [k for k in log.split("X") if k]
print(len(k))
for l in k:
        print(l)