n=int(input("Type the size of the matrix: "))

numbers= list(map(int, input("Introduce the elements: ").split()))
counter=0
numbers2=list(map(int, input("Introduce the winning numbers: ").split()))
tabel = [[list() for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        tabel[i][j].append(numbers[counter])
        counter=counter+1

cnt=0

numbers2 = list([num for num in numbers2 if num not in numbers])
if numbers2==[]:
    print ("Bingo!")
else:
    print (numbers2)

for i in range(n):
   for j in range(n):
       print(tabel[i][j], end = " ")
   print()

#for nums in numbers2:
 #   if (nums in numbers):
  #      cnt += 1
   #     numbers2.remove(nums)