import math
n=int(input())
values=[]
x=None
check=True
y=line=cnt=prev=0

for i in range(n):
    values.append(list(map(float, input().split())))

for coord in values:
    if x is not None:
        line=round(math.sqrt((coord[0]-x)**2+(coord[1]-y)**2),3)
        if check is True:
            check=False
            prev=line
            x=coord[0]
            y=coord[1]
            continue

        if line==prev:
            cnt+=1
        else:
            break
    prev=line
    x=coord[0]
    y=coord[1]

print (cnt)
if cnt==(len(values)-2):
    print ('da')
else:
    print ('nu')