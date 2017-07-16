n = int(input())
numbers = [int(a) for a in input().split()]
print(*numbers)
for i in range(n):
    for j in range(n-1-i):
        if numbers[j] > numbers[j+1]:
            numbers[j], numbers[j+1] = numbers[j+1] , numbers[j]
            print(*numbers)