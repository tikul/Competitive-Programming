letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
keyword = input()
word = input()
new_word = "".join(l for l in word if l in letters)
decoded = ""

def shift_letter(letter, kw):
    return letters[(letters.index(letter) + letters.index(kw)) % 26]

for i, letter in enumerate(new_word):
    decoded += shift_letter(letter, keyword[i % len(keyword)])
    
print(decoded)