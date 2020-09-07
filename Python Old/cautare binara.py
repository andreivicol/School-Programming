import math
n=int(input())
v=[]
for i in range(n):
    v.append(int(input()))
x=int(input())
y=0
z=0

compared=[]
check=True
sortat=sorted(v)

while check==True:
    y=math.floor(len(sortat)/2)
    if x>sortat[y]:
        z=sortat[y]
        compared.append(z)
        sortat=sortat[y+1:]

    else:
        z=sortat[y]
        compared.append(z)
        sortat=sortat[0:y+1]

    if z==max(sortat):
        break

print (*compared, sep=' ')

#Varianta galer
import math

n = int(input())
v = []
for i in range(n):
    v.append(int(input()))
x = int(input())

compared = []
sortat = sorted(v)

while True:
    y = math.floor(len(sortat) / 2)
    # print(y)
    # print(compared)
    # print('sortat', sortat)

    if len(sortat) == 0:
        break

    if x == sortat[0]:
        compared.append(sortat[0])
        break

    if x > sortat[y]:
        compared.append(sortat[y])
        sortat = sortat[y + 1:]
    else:
        compared.append(sortat[y])
        sortat = sortat[:y]

for x in compared:
    print(x)