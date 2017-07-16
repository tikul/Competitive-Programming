plaintext = input()
ciphertext = input()
encrypted = input()
ans = ""

for c in encrypted:
    i = ciphertext.find(c)
    if i == -1:
        ans += "."
    else:
        ans += plaintext[i]
        
print(ans)