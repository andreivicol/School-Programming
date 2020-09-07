hour=input()
n=int(input())
ghisee=[]
h=''

for i in range(n):
    ghisee.append(input().split())

if hour[0]==0:
    h=hour[1]+'.'+hour[3:5]
else:
    h=hour[0:2]+'.'+hour[3:5]
h=float(h)

times=[]
indices=[]
temp=0

for ghiseu in ghisee:
    x=''
    if ghiseu[0][0] == 0:
        x = ghiseu[0][1] + '.' + ghiseu[0][3:5]
    else:
        x = ghiseu[0][0:2] + '.' + ghiseu[0][3:5]
    times.append(float(x))

for indexx,time in enumerate(times):
    if time>h and temp==0:
        temp=time
        continue
    if time>h and time<temp:
        temp=time
        continue
    if time==temp:
        indices.append(indexx)

indices.append(times.index(temp))

if len(indices)==1:
    print (ghisee[indices[0]][2])
else:
    ind=0
    mini=None
    for index in indices:
        if mini is None:
            mini=int(ghisee[index][1])
            ind=index
            continue
        if mini > int(ghisee[index][1]):
            mini=int(ghisee[index][1])
            ind=index
    print(ghisee[ind][2])







