words = ["ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"]
memo = {}

def solve(i, s):
    if i >= len(s):
        return 1
    key = s[i:]
    if key in memo:
        return memo[key]
    ans = 0
    for j in range(i, len(s)):
        if s[i:j+1] in words:
            ans += solve(j+1, s)
    memo[key] = ans
    return ans

for _ in range(10):
    print(solve(0, input()))