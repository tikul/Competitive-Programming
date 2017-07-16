n, m = map(int, input().split())
x = [int(i) for i in input().split()]
y = [int(i) for i in input().split()]
table = [[0 for i in range(m+1)] for i in range(n+1)]
for i in range(1, n+1):
    for j in range(1, m+1):
        if x[i-1] == y[j-1]:
            table[i][j] = table[i-1][j-1] + 1
        else:
            table[i][j] = max(table[i-1][j], table[i][j-1])

print(table[n][m])