n = int(input())
marks = [int(input()) for i in range(n)]
marks.sort()
def fixed_round(num):
    if num - int(num) >= .5:
        return int(num)+1
    else:
        return int(num)
        
if n % 2 == 1:
    print(marks[int(n/2)])
else:
    print(fixed_round( (marks[int(n/2)] + marks[(int(n/2))-1])/2) )