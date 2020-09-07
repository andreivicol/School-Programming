n=int(input("Numer of participants: "))

participants=[]
max=0


for i in range(n):
    participants.append(list(input().split()))

for ind, element in enumerate(participants):
    area=(int(element[3])-int(element[1]))*(int(element[4])-int(element[2]))
    element.append(area)

for ind, element in enumerate(participants):
    if element[5]>max:
        max=element[5]
        index=ind

print(' '.join(map(str, participants[index])))