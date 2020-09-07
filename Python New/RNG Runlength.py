number = int(input())
sequence = input()
sequence += '0'

cnt = 0
counter = number * [0]
sliced = []

for char in sequence:
    if char == '1':
        cnt += 1
    else:
        if cnt >= 1:
            counter[cnt - 1] += 1
            cnt = 0

for ind, value in enumerate(counter):
    if counter[ind::] == (len(counter) - ind) * [0]:
        sliced = counter[0 : ind + 1]
    else:
        print(value, end=" ")

placeHolder = sliced
print("\n")

if placeHolder == sorted(counter, reverse=True):
    print(1)
else:
    print(0)
