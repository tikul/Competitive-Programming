text = input()
happy = text.count(":-)")
sad = text.count(":-(")

if happy == 0 and sad == 0:
    print("none")
elif happy > sad:
    print("happy")
elif sad > happy:
    print("sad")
else:
    print("unsure")