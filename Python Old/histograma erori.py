optim=float(input())
try:
    results=list(map(float, input().split()))
except:
    pass

errors=21*[0]

for result in results:
    err=((result-optim)/optim)*100
    res=err//5
    if res>20:
        errors[-1]+=1
    else:
        errors[int(res)]+=1

for ind, error in enumerate(errors):
    x=5*ind
    y=5*ind+5
    if ind==len(errors)-1:
        print (f"100%+ = {error}")
    else:
        print (f"[{x}% - {y}%) = {error}")