n = int(input())
ingredients = list(map(int, input().split()))
oper = int(input())
operations = []
for i in range(oper):
    operations.append(list(map(int, input().split())))

done = 0
restock = 0
cnt = 0

for plm in operations:
    cnt = 0
    if max(plm) == 0:
        restock += 1
        for x in range(len(ingredients)):
            ingredients[x] += 15
        continue

    for i in range(len(ingredients)):
        if ingredients[i] - plm[i] >= 0:
            cnt += 1

    if cnt == len(plm):
        done += 1
        for j in range(len(ingredients)):
            ingredients[j] = ingredients[j] - plm[j]

print(done)
print(restock)