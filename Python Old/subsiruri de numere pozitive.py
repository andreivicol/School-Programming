n=int(input())
values=list(map(float, input().split()))

final=[]
indices=[]
subsir=[]
series=[]
ind=0
s=0

while ind<len(values):
    if values[ind]>0:
        indices.append(ind)

    if values[ind]<0:
        ind+=1
        continue
    else:
        subsir=[]
        while values[ind]>0 :
            subsir.append(values[ind])
            ind+=1
            if ind==len(values):
                break

    if subsir:
        series.append(subsir)

for ind, element in enumerate(series):
    s=0
    for number in element:
        s+=1
    final.append(s)

if final:
    print (indices[final.index(max(final))], max(final))
else:
    print ('-1', '0')