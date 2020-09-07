lista = [1,2,3,4,5]

for ind, elem in enumerate(lista):
    if elem % 2 == 1:
        lista.pop(ind)

print(*lista)