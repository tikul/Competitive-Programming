ticket = [int(input()) for i in range(4)] #pink, green, red, orange
goal = int(input())
responses = []
cur_sum = 0
for a in range(goal+1):
    cur_sum += a*ticket[0]
    if cur_sum <= goal:
        for b in range(goal+1):
            cur_sum += b*ticket[1]
            if cur_sum <= goal:
                for c in range(goal+1):
                    cur_sum += c*ticket[2]
                    if cur_sum <= goal:
                        for d in range(goal+1):
                            cur_sum += d*ticket[3]
                            if cur_sum == goal:
                                responses.append([a,b,c,d])
                            cur_sum -= d*ticket[3]
                    cur_sum -= c*ticket[2]
            cur_sum -= b*ticket[1]
    cur_sum -= a*ticket[0]


for r in responses:
    print("# of PINK is {0} # of GREEN is {1} # of RED is {2} # of ORANGE is {3}".format(r[0],r[1],r[2],r[3]))
    
    
print("Total combinations is {}.".format(len(responses)))
if len(responses) > 0:
       min_tic = min(sum(r) for r in responses)
else:
       min_tic = 0
print("Minimum number of tickets to print is {}.".format(min_tic))