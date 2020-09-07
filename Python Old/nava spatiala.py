import math
n=int(input())
coordinates=[]
for i in range(n):
    coordinates.append(list(map(float, input().split())))
start=list(map(float, input().split()))

distance=0

while len(coordinates)>=1:
    dist=[]

    for element in coordinates:
        dist.append(math.sqrt((start[0]-element[0])**2+(start[1]-element[1])**2+(start[2]-element[2])**2))
    x=min(dist)
    distance+=x
    start=coordinates[dist.index(x)]
    coordinates.pop(dist.index(x))

print (round(distance,2))


