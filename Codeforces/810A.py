import math
n, k = map(int, input().split())
amt = 0
nums = [int(x) for x in input().split()]
amt = sum(nums)
ans = 2*n*k - n - 2*amt
print(math.ceil(ans) if ans >=0 else 0)