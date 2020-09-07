nbvalues=int(input())
values=[]
modified=[]
cnt=0
check=False

for i in range(nbvalues):
    values.append(float(input()))

step=float(input())

for element in values:
    if element>step:
        modified.append(1)
    else:
        modified.append(0)

for ind,elem in enumerate(modified):
    if elem==1:
        check=True
    if elem==0 and check==True:
        cnt+=1
        check=False
    if elem==1 and ind==len(modified)-1:
        cnt+=1

print (cnt)

# for ind, elem in enumerate(modified):
#     if modified[0]==0:
#         pass
#
#     if elem==0:
#         if modified[ind-1]==1:
#             cnt+=1
#
#     if modified[len(modified)-1]==1 and modified[len(modified)-2]==0:
#         cnt+=1

