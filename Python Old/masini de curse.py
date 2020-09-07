n, k = input().split()
details=[]
printer=[]
time=[]
cnt=1

for i in range(int(k)):
    details.append(list(map(float, input().split())))

for car in details:
    time.append((int(n)-car[0])/car[1])

min=min(time)

for tm in time:
    if tm==min:
        printer.append(cnt)
    cnt+=1

print(*printer, sep=' ')