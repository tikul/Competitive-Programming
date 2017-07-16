def find(t, start):
    if (t[start] == []):
        return 2;
    if len(t[start]) >= 2:
        num = 1
        for x in t[start]:
            num = num * find(t, x)
        return 1 + num
    return 1 + find(t, t[start][0])

n = int(input())
tree = {}
allpaths = []

for i in range(n-1):
    meme = int(input())
    if meme not in tree.keys():
        tree[meme] = [i+1]
    else:
        tree[meme] += [i+1]
    if i+1 not in tree.keys():
        tree[i+1] = []

a = find(tree, n) - 1
    
print(a)