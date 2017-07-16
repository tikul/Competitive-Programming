conv = {"ABC": "2", "DEF":"3", "GHI": "4", 
        "JKL":"5", "MNO":"6", "PQRS":"7", "TUV":"8",
        "WXYZ":"9",}

nums = [input() for i in range(int(input()))]
new_nums = []

for num in nums:
    new_str = ""
    for char in num:
        if len(new_str) >= 10:
            break
        if char in ([str(i) for i in range(0, 10)]):
            new_str += char
        elif char == "-":
            continue
        else:
            for key,val in conv.items():
                if char in key:
                    new_str += val
    new_str = new_str[0:3] + "-" + new_str[3: 6] + "-" + new_str[6:]
    new_nums.append(new_str)


print(*new_nums, sep = "\n")