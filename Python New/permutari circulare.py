binary = bin(int(input()))
binary = binary[2::]

max = 0

for i in range(len(binary)):
    binary = binary[-1] + binary[0:len(binary) - 1]
    if max <= int(binary, 2):
        max = int(binary, 2)

print(max)