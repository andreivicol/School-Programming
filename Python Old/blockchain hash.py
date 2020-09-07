numbers, repetiotions = input().split()
entries = [input().split()]

max = 0
sum = 0
placeHolder = ""

for entry in entries:
    for i in range(0, 2):
        if len(entry) > 1:
            for ind, char in enumerate(entry):
                try:
                    placeHolder += str(abs(int(char) - int(entry[ind + 1])))
                except IndexError:
                    continue
            sum += int(placeHolder)
            entry = placeHolder
            placeHolder = ""
        else:
            break

    if sum > max:
        max = sum
    sum = 0

print(max)