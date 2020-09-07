n=int(input())
numere=list(map(int, input().split()))
sortat=sorted(numere)
k=0
final=[]
paindrom=''
for nb in sortat:
    if sortat.count(nb)==1:
        k+=1
    if sortat.count(nb)%2==1:
        final.append(sortat.pop(nb))

if k>1:
    print(0)
else:
    final.append(sortat[0])
    x=True
    for num in sortat[1::]:
        if x==True:
            final.append(num)
            x=False
        else:
            final.insert(0, num)
            x=True
    for ltr in final:
        paindrom+=str(ltr)
    print(paindrom)


