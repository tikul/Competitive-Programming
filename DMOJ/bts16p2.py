struct = []
n = int(input())
for i in range(n):
    commands = input().split()
    a = int(commands[0])
    if len(commands) == 2:
        item = commands[1]

    if a == 1:
        if item not in struct:
            print("true")
            struct.append(item)
        else:
            print("false")
    elif a == 2:
        if item in struct:
            print("true")
            struct.remove(item)
        else:
            print("false")
    elif a == 3:
        if item in struct:
            print(struct.index(item))
        else:
            print(-1)
    else:
        print(*sorted(struct))