n=int(input())
matrix=[]
matrix3=[]
matrix2=[]
x=0
y=0

for i in range(n):
    semnal=list(map(int, input().split()))
    matrix.append(semnal)

for ind1,elem1 in enumerate(matrix):
    lista=10*[0]
    for ind, elem in enumerate(semnal):
        if lista==10*[0] and i>0:
            for plm in range(x):
                lista[plm]=0
        try:
            lista[ind+x]=semnal[ind]
        except IndexError:pass
    x+=1
    matrix2.append(lista)

for ind1,elem1 in enumerate(matrix2):
    lista=10*[0]
    for ind, elem in enumerate(semnal):
        if lista==10*[0] and y>0:
            for plm in range(y):
                lista[plm]=0
        try:
            lista[ind+y]=semnal[ind]
        except IndexError:pass
    y+=1
    matrix3.append(lista)

print (matrix3)