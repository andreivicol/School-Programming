bits = int(input())
pairSize = int(input())

numbers = []
zeroCode = "0" # start of each encoding
oneCode = "1"

for i in range(bits):
    numbers.append(input())

initial = len(numbers)

while len(numbers) > 0:
    sequence = numbers[0: pairSize] # select substring of pairSize elements
    if len(sequence) < pairSize: # if numbers is not multiple of pairSize
        zeroCode += '1' + ''.join(sequence) # treat them as incorrect sequence
        oneCode += '0' + ''.join(sequence)
        break # break to not append twice

    # zero encoding
    if '1' in sequence: # check if it can be compressed
        zeroCode += '1' + ''.join(sequence) # add string made by concatenating '1' and sequence
    else:
        zeroCode += '0' # else, compress

    # one encoding
    if '0' in sequence:
        oneCode += '0' + ''.join(sequence)
    else:
        oneCode += '1'
    numbers = numbers[pairSize::]

if initial / len(zeroCode) >= initial / len(oneCode): # calculate lengths and print best compression
    print(round(initial / len(zeroCode), 2))
    for char in zeroCode:
        print(char, end='\n') # no need for end='\n' => C-style printing
else:
    print(round(initial / len(oneCode), 2))
    for char in oneCode:
        print(char, end='\n')
