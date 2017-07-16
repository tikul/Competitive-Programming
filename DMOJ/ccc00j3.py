coins = int(input())
m = [int(input()) for i in range(3)] #30 every 35; 60 every 100; 9 every 10
vals = [[30, 34], [60, 99], [9, 9]]
count = 0
done = False

while(not done):
    for i in range(3):
        if coins > 0:
            coins -= 1
            count += 1
        else:
            done = True
            break
        if m[i] == vals[i][1]:
            coins += vals[i][0]
            m[i] = 0
        else:
            m[i] +=1

print("Martha plays {} times before going broke.".format(count))