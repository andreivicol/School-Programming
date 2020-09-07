k, m=input('Insert the values for k and m: ').split()
k=int(k)
m=int(m)


indices=[]
values=[]


def up(n):
    result=1
    for i in range(1,n+1):
        result*=i
    return result

def down(n,k):
    prod=1
    for j in range(1, n-k+1):
        prod*=j
    return prod

def arrangements(n,k):
    arr=up(n)/down(n,k)
    return arr

for n in range(k,m):
    if arrangements(n,k)>=m:
        values.append(arrangements(n,k))
        indices.append(n)





