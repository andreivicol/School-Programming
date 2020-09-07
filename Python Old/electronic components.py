batches = int(input())

components = ['T', 'C', 'R']
longestBatch = 0
usefulBatches = 0

for i in range(0, batches):
    #number  = input()
    placeHolder = input().split()

    if longestBatch < len(placeHolder):
        longestBatch = len(placeHolder)

    for component in components:
        if component not in placeHolder:
            break

    if placeHolder.count('C') < placeHolder.count('T') or placeHolder.count('R') < placeHolder.count('T'):
        continue
    usefulBatches += 1

print(f'{usefulBatches} {longestBatch}')