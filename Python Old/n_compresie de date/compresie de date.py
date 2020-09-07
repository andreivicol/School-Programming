n=int(input())

datain=[]
final=[]
prev=1
temp=0
cnt=0

for i in range(1,n+1):
    m=list(map(int, input().split(',')))
    datain.append(m)

for ind, elem in enumerate(datain):
    datain[ind]=[int(i) for i in elem]


for ind, elem in enumerate(datain):
    for ind1, x in enumerate(elem):
        sir=[]
        if x != 0 and cnt == 0:
            if temp==0:
                final.append(x)
            else:
                final.append(temp)
        if x != 0 and cnt != 0:
            sir.append(temp)
            sir.append(cnt)
            final.append(sir)
            cnt=0
        if x == 0:
            cnt += 1
            continue
        # else:
        #     if cnt == 0:
        #         final.append(elem)
        #     else:
        #         final.append([elem, *[0 for x in range(cnt)]])

# temp = {}
# datain = [5,0,0,6,1,0,0,9,0,0,0,7,0]
# out = ""
# for i in range(len(datain)):
#     a = datain[i]
#     if a != 0:
#         temp[a] = 0
#         k = 1
#         try:
#             while datain[i+k] == 0:
#                 temp[a] += 1
#                 k+=1
#         except IndexError:pass
#         if temp[a] == 0:
#             out = out + str(f", {a}")
#         else:
#             out = out + str(f", ({a},{temp[a]})")
# out = out[2:] #to delete the first ", "
print(out)

    print (final)

