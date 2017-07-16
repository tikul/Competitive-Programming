def to_num(letter):
    if letter.isupper():
        return 0
    else:
        return 1

m, f = input(), input()
number_of_babies = int(input())
babies = []
possible_phenos = []
for i in range(0, 10, 2):
    phen = []
    p1 = to_num(m[i]) * to_num(f[i])
    phen.append(p1)
    p2 = to_num(m[i]) * to_num(f[i+1])
    if p2 not in phen:
        phen.append(p2)
    p3 = to_num(m[i+1]) * to_num(f[i])
    if p3 not in phen:
        phen.append(p3)
    p4 = to_num(m[i+1]) * to_num(f[i+1])
    if p4 not in phen:
        phen.append(p4)
    possible_phenos.append(phen)


for _ in range(number_of_babies):
    babies.append(input())

for baby in babies:
    their_baby = True
    for i, pheno in enumerate(baby):
        if to_num(pheno) not in possible_phenos[i]:
            their_baby = False
            break 
    if(their_baby):
        print("Possible baby.")
    else:
        print("Not their baby!")