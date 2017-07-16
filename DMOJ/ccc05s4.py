def longest(graph, current, counter = 0):
    largest = 0
    if graph[current] == []:
        return counter
    for branch in graph[current]:
        num = longest(graph, branch, counter + 1)
        if num > largest:
            largest = num
    return largest
    
l = int(input())
for i in range(l):
    tree = {}
    tree_list = []
    n = int(input())
    for j in range(n):
        tree_list.append(input())
    prev = tree_list[-1]
    tree[prev] = []
    
    for j, m in enumerate(tree_list):
        if tree_list[j] not in tree.keys():
            tree[prev].append(m)
            tree[m] = []
        prev = m
    
    new = 20 * longest(tree, prev)
    old = 10 * n
    print(old - new)