b, n=input().split()
b=int(b)
n=int(n)
databse=[]
total=0
discount=0

for i in range(b):
    databse.append(list(input().split()))

client=list(input().split())

for product in client:
    for value in databse:
        if product in value:
            if value[1]=='p':
                total+=float(value[2])
            else:
                discount+=float(value[2])



if discount>0:
    print(float(total*(100-discount)/100))
else:
    print (total)
