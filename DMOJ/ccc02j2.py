def changeword(word):
    l = len(word)
    if l > 4:
        if word[-2:] == "or" and word[-3] not in "aeiouy":
            return word[:-2] + "our"
    return word

while(True):
    word = input()
    if word == "quit!":
        break
    print(changeword(word))