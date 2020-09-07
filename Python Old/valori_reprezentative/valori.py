sir1=[]
sir2=[]
sirfinal=[]
length1=input("The len of 1st array: ")
length2=input("The len of 2nd array: ")
length1=int(length1)
length2=int(length2)

for i in range(length1):
    inp=int(input())
    sir1.append(inp)

for i in range(length2):
    inp2=int(input())
    sir2.append(inp2)

sir=sir1+sir2
sir.sort()
index=5-len(sir)
while index<0 :
    sirfinal.append(sir[index])
    index+=1
print(sirfinal)

