m, n, p= input().split()
m=int(m)
n=int(n)
p=int(p)
v=[]
w=[]
ascuns=[]
max=None
cnt=0

for i in range(m):
    v.append(list(map(int, input().split())))

for j in range(n):
    w.append(list(map(int, input().split())))

x=list(map(int, input().split()))

for a in range(n):
    y=0
    sum=0
    for element in v:
        sum+=x[y]*element[a]
        y+=1
    ascuns.append(sum)

for b in range(p):
    current=0
    z=0
    for elem in w:
        current+=elem[b]*ascuns[z]
        z+=1
    if max is None:
        max=current
        cnt=b+1
    else:
        if current>max:
            max=current
            cnt=b+1

print (cnt)