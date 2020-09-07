nava=list(map(int, input().split()))
n=int(input())
enemy=[]
for i in range(n):
    enemy.append(list(map(int, input().split())))

k=0

for ship in enemy:
    v1=nava[0]
    a1=nava[1]
    v2=ship[0]
    a2=ship[1]
    while True:
        v1-=a2
        if v1<0:
            break
        v2-=a1
        if v2<0:
            k+=1
            break

print (k)
