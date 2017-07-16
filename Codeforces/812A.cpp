line = input().split(":")

hrs, mins = line

done = False
t = 0
while(not done):
    p_mins = mins[::-1]
    i_mins = int(mins)
    p_hrs = int(hrs[::-1])
    i_hrs = int(hrs)
    if (i_hrs in range(0, 6) or i_hrs in range(10, 16) or i_hrs in range(20, 24)) and i_mins <= p_hrs:
        done = True
        t += p_hrs - i_mins
    else:
        t += 60-i_mins
        hrs = "0"+str((i_hrs+1)%24)
        hrs = hrs[-2:]
        mins = "00"
print(t)