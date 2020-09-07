l=int(input("Number of lines: "))
c=int(input("Number of columns: "))
cnt=0
sir=[]


for i in range(c*l):
    sir.append(int(input()))

for elem in sir:
    div=2
    while  elem>div:
        if elem % div ==0:
            cnt+=1
            break
        div+=1


print(cnt)



# for i in range(l):
#     line=[]
#     for j in range(c):
#         line.append(int(input()))
#     matrix.append(line)
#
# for ind, elem in enumerate(matrix):
#     for ind1,elem1 in enumerate(line):
#         if elem1<=3:
#             line[ind1]=0
#
#         while elem1>div:
#             if elem1%div == 0:
#                 cnt+=1
#             div+=1
#         if cnt!=0:
#             line[ind1]=1
#             cnt=0
#         else:
#             line[ind1]=0
#
#
# print (matrix)