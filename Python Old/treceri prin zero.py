n=int(input())
v=[]
for r in range(n):
    v.append(float(input()))

w=int(input())

ind1, ind=0, 0
final=[]

while ind<n:
    prev=None
    s,cnt, altcnt=0,0,0
    treceri=[]

    for i in range(w):
        try:
            s+=v[ind]
            altcnt+=1
        except IndexError:
            pass
        ind+=1

    avg=float(s/altcnt)

    for j in range(w):
        try:
            treceri.append(float(v[ind1]-avg))
        except IndexError:
            pass
        ind1+=1

    for element in treceri:
        if prev is None:
            prev=element
            continue
        else:
            if (prev>0 and element<0) or (prev<0 and element>0):
                cnt+=1
        prev=element
    final.append(cnt)

print (final)


