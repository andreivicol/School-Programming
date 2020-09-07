import math
n=int(input("Insert the number of rows: "))
m=int(input("Insert the number of columns: "))


sum1=0
sum2=0

initial=[[0 for i in range(m)] for j in range(n)]
final=initial


for i in range(n):
    for j in range(m):
        initial[i][j]=(int(input()))
        sum1+=initial[i][j]

for i in range(n):
    for j in range(m):
        final[i][j]=math.floor(initial[i][j]*0.9 +2)
        sum2+=final[i][j]

average=(sum2-sum1)/(n*m)

print(round(average,2))
