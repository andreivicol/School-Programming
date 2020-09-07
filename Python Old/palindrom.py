n = int(input())
numere = list(input().split())
palindrome = []
singles = []

for numar in numere:
    if numere.count(numar) == 1:
        singles.append(numar)
for plm in singles:
    numere.remove(plm)

sortat = sorted(numere)
if len(singles) == 1:
    palindrome.append(singles[0])

for x in sortat:
    if sortat.count(x) == 3:
        palindrome.append(x)
        sortat.remove(x)

while sortat != []:
    palindrome.append(sortat.pop(0))
    palindrome.insert(0, sortat.pop(0))

if len(singles) > 1:
    print(0)
else:
    print(''.join(palindrome))