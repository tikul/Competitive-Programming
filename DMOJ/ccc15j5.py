n = int(input())
k = int(input())
s = 0
graph = {}

def h(p, d, c):
    return "{}-{}-{}".format(p,d,c)
    
def combs(s, prevsum, depth, cur):
    c = 0
    m = h(prevsum, depth, cur)
    if m in graph.keys():
        return graph[m]
    if depth == k:
        if prevsum == n:
            graph[m] = 1
            return 1
        else:
            graph[m] = 0
            return 0
    i = cur
    while(i * (k - depth) <= n - prevsum):
        c += combs(s, prevsum + i, depth + 1, i)
        i += 1
        
    graph[m] = c
    return c
    
meme = int(n/k)
while(meme >= 1):
    s += combs(meme, meme, 1, meme)
    meme -= 1

print(s)