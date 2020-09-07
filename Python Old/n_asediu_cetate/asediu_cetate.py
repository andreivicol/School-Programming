m,n,p=input().split()
m=int(m)
n=int(n)
p=int(p)
soldati=[i for i in range(1,n+1)]

index=p-1

while len(soldati)>1:
    for i in range(m-1):
        index+=1
        if index==len(soldati):
            index=0
    soldati.pop(index)
    if index==len(soldati):
        index=0

print (soldati[0])