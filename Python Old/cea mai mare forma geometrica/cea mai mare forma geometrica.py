n=int(input("Number of participants: "))
concurs=[]
areas=[]
max=0
for i in range(n):
    concurs.append(list(input().split()))


for ind, elem in enumerate(concurs):
    if elem[0]=="cerc":
        area=float(elem[1])*float(elem[1])*3.14
        areas.append(area)
    if elem[0]=="dreptunghi":
        area=float(elem[1])*float(elem[2])
        areas.append(area)
    if elem[0]=="patrat":
        area=float(elem[1])*float(elem[1])
        areas.append(area)
    print (area)


for ind, elem in enumerate(areas):
    if elem>max:
        max=elem
        index=ind

print(' '.join(concurs[index]))