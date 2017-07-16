trout = int(input())
pike = int(input())
pickerel = int(input())
n = int(input())
ways = 0
ans = []
for i in range(n // trout + 1):
    for j in range(n // pike + 1):
        for k in range(n // pickerel + 1):
            if i*trout + j*pike + k*pickerel <= n and i+j+k:
                ways += 1
                ans.append([i,j,k])
                
for fish in ans:
    print("{} Brown Trout, {} Northern Pike, {} Yellow Pickerel".format(fish[0], fish[1], fish[2]))
print("Number of ways to catch fish:", ways)