dirs = []
while True:
    instr = input()
    dirs.append(instr)
    if instr == "SCHOOL":
        break

new_dirs = dirs[::-1]
new_dirs = new_dirs[1:] + ["HOME"]
lr_dirs = []
street_dirs = []
way = []
for i in range(0, len(new_dirs)):
    if i % 2 == 0:
        lr_dirs.append(new_dirs[i])
    else:
        street_dirs.append(new_dirs[i])

for i, d in enumerate(lr_dirs):
    
    if d == "L":
        t = "RIGHT"
    else:
        t = "LEFT"
    if street_dirs[i] == "HOME":
        s = "into your HOME"
    else:
        s = "onto {} street".format(street_dirs[i])
        
    way.append("Turn {} {}.".format(t, s))

for w in way:
    print(w)