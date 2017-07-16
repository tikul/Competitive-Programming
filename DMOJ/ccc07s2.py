n = int(input())
boxes = [sorted([int(a) for a in input().split()]) for i in range(n)]
m = int(input())
packages = [sorted([int(a) for a in input().split()]) for i in range(m)]
for package in packages:
    volume = 8000000000
    changed = False
    for box in boxes:
        if all(box[i] >= package[i] for i in range(3)):
            temp_volume = box[0] * box[1] * box[2]
            if temp_volume < volume:
                changed = True
                volume = temp_volume
    if changed:
        print(volume)
    else:
        print("Item does not fit.")