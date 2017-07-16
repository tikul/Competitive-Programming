lines = int(input())
student = [input() for i in range(lines)]
answers = [input() for i in range(lines)]
correct = 0
for i in range(lines):
    if student[i] == answers[i]:
        correct+=1
print(correct)