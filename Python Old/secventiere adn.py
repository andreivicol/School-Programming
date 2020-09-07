adn = input()

x = len(adn) / 2
mirror = adn[int(x):]
mirror = mirror[::-1]
adn = adn[0:int(x)]

original = ['A', 'T', 'C', 'G']
pair2 = ['T', 'A', 'G', 'C']
cnt = 0
i = 0

while i < len(adn):
    if original.index(adn[i]) == pair2.index(mirror[i]):
        i += 1
        continue
    else:
        cnt = i + 1
        break

# for pair in zip(adn, mirror):
#     if original.index(pair[0])==pair2.index(pair[1]):
#         continue
#     else:
#         cnt+=1

print(cnt)
