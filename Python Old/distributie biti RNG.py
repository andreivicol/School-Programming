# bitsNb = input()
# bits = input()
bits = "101100110111100001"
digitCnt = 2 * [0]
sequenceCnt = 4 * [0]

for i in range(0, len(bits)//2):
    number = bits[i * 2 : i * 2 + 2]
    sequenceCnt[int(number, 2)] += 1
    for char in number:
        digitCnt[int(char)] += 1

sorted(digitCnt)
sorted(sequenceCnt)

ratio2 = digitCnt[-1]/digitCnt[0]
ratio1 = sequenceCnt[-1]/sequenceCnt[0]

print(ratio1, ratio2)

if ratio1 <= 1.1 and ratio2 <= 1.1:
    print("1")
else:
    print("0")