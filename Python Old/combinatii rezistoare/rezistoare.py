m=int(input("The value of M: "))
n=int(input("The value of n: "))

indices=[]
values=[]
cnt=0


def factorial(x):
    result=1
    for i in range(1,x+1):
        result*=i
    return result

def factorial_diff(x,k):
    result2=1
    for i in range(1,x-k+1):
        result2*=i
    return result2

def combinations(x,k):
    comb= factorial(x)/(factorial(k)*factorial_diff(x,k))
    return comb

for i in range(1,n+1):
    if m<=combinations(n,i):
        cnt=1
        indices.append(i)
        values.append(combinations(n,i))

if cnt!=0:
    y=min(values)
    ind=values.index(y)
    print (indices[ind])
else:
    print (0)

