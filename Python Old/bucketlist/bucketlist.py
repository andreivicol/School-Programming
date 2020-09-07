n=input("Input the number of elements: ")
n=int(n)
lista=list(map(int, input("Insert the numbers you wish to bucketlist: ").split()))
result=[0]*19

for element in lista:
    result[len(str(element))-1]+=1
    # cnt = 0
    # while element > 0:
    #     if element // 10 > 0:
    #         cnt= cnt + 1
    #         element = element // 10
    # result[cnt] += 1


for ind, elem in enumerate(result):
    if elem >0:
        print(f'{ind+1} {elem}')

