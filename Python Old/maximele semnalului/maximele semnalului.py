n=int(input())
semnal=[]
maxime=[]
cnt=0
cnt2=0
x=0
curr=0
prev=0
last=0
s=0

for i in range(n):
    semnal.append(float(input()))

for ind, elem in enumerate(semnal):
    if x==0:
        if elem>semnal[ind+1]:
            maxime.append(elem)

    if x>=1 and x< len(semnal)-1:
        if elem>semnal[ind-1] and elem>semnal[ind+1]:
            maxime.append(elem)

    if x==len(semnal)-1:
        if elem>semnal[ind-1]:
            maxime.append(elem)
    x+=1


for elem in maxime:
    s+=elem
    cnt+=1

avg=s/cnt

for element in semnal:
    if element>avg:
        cnt2+=1

print (cnt2)




