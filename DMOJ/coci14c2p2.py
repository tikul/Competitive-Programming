import sys
all_data = sys.stdin.read().split('\n')
vals = {}
for i in all_data[1:]:
    if i:
        vals[i] = vals.get(i, 0) + 1;
    
for thing in vals.items():
    if thing[1] % 2 == 1:
        print(thing[0])
        break