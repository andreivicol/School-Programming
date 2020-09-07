n = int(input())
transactions = []
for i in range(n):
    transactions.append(list(input().split()))

chain = []
place = []
lengths = []
bigsum = []
maxx = 0

for transaction in transactions:
    cnt = 0
    dest = transaction[1]
    sum1 = int(transaction[-1])
    subchain = []
    while cnt < len(transactions):
        for trans in transactions:
            if cnt == len(transactions):
                break
            if dest == trans[0]:
                subchain.append(dest)
                dest = trans[1]
                cnt = 0
                if int(trans[-1]) < sum1:
                    sum1 = int(trans[-1])
            else:
                cnt += 1

    if subchain != []:
        subchain.insert(0, transaction[0])
        subchain.append(dest)
        subchain.append(int(sum1))
        place = subchain
        chain.append(subchain)

print(chain)
for elem in chain:
    lengths.append(len(elem))
    bigsum.append(elem[-1])

if lengths != []:
    maxi = max(lengths)
    if lengths.count(maxi) > 1:
        for plm in lengths:
            if plm == maxi:
                if maxx < bigsum[lengths.index(plm)]:
                    maxx = bigsum[lengths.index(plm)]
    else:
        maxx = lengths.index(maxi)

    print(' '.join(str(x) for x in chain[maxx][0:len(chain[maxx]) - 1]))
    print(chain[maxx][-1])
else:
    top = 0
    ind = 0
    for fmm in transactions:
        if int(fmm[-1]) > top:
            top = int(fmm[-1])
            ind = transactions.index(fmm)
    print(' '.join(str(x) for x in transactions[ind][0:2]))
    print(transactions[ind][-1])








