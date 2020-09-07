c=int(input())
colors=list(input().split())
kids=[]


while True:
    try:
        a=list(input().split())
        kids.append(a)
    except EOFError:
        break

combined=['purple','orange','green','brown']
needed=['red','blue','yellow','red','yellow','blue','red','yellow','blue']
final=[]

for kid in kids:
    plm=kid[2::]
    while len(plm)>=1:
        if plm[0] in colors:
            plm.pop(0)
            continue

        elif plm[0] in combined:
            cnt=0
            need=needed[2*combined.index(plm[0]):2*combined.index(plm[0])+2]

            if plm[0]=='brown':
                need=needed[2*combined.index(plm[0])::]

            for elem in need:
                if elem in colors:
                    cnt+=1

            if cnt==len(need):
                plm.pop(0)
            else:
                break

        else:
            break

    if plm==[]:
        final.append(kid[0])

for x in final:
    print(x)