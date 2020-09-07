def signum(number):
    return 1 if number >= 0 else -1  # signum function


placeHolder = int(input())
balance = list(map(int, input().split()))
variation = []
sequence = []
lengthCnt = 0
index = 0

for ind, amount in enumerate(balance):
    if ind < 1:  # calculate variation beginning with the second day
        continue
    variation.append(amount - balance[ind - 1])  # balance is 1 index behind

for ind, var in enumerate(variation):
    try:
        if signum(var) != signum(variation[ind + 1]):  # compare consecutive variations for differance in sign
            lengthCnt += 1  # count sequence length
        else:
            if len(sequence) <= lengthCnt + 1:  # if sequences are equal, choose the newest one
                sequence = balance[ind + 1 - lengthCnt: ind + 2]
            lengthCnt = 0

    except IndexError:
        continue

if len(sequence) <= 1:
    print(0)
    exit(1)

print(len(sequence))
print(*sequence)
print(f'{round(sum(balance) / len(balance), 2)} {round(sum(variation) / len(variation), 2)}')
