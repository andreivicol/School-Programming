import string
mesaj=list(input())
cuvinte=list(string.ascii_uppercase)
cuvant = ''

while mesaj!=[]:
    if len(mesaj)>=2:
        place=str(mesaj[0])+str(mesaj[1])
    else:
        place=str(mesaj[0])

    if place=='00':
        cuvant+=' '
    if place[0]=='0' and place[1]!='0':
        place=place[1]

    if int(place) in range(1,26):
        cuvant+=cuvinte[int(place)-1]
        if not mesaj:
            mesaj.pop(0)
            mesaj.pop(0)
    else:
        place=place[0]
        if int(place) in range(1, 26):
            cuvant += cuvinte[int(place) - 1]
            if not mesaj:
                mesaj.pop(0)




print (cuvant)


