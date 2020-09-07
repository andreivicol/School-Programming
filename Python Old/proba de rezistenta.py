pupils = int(input())
results = []

for i in range(0, pupils):
  results.append(list(input().split()))

minutes = int(input())

finalResults = dict()

for event in results:
  if int(event[-1]) <= minutes:
    finalResults[int(event[-1])] = event[0:-1]

printList = sorted(finalResults)

print(len(printList))

for ev in printList:
  print(f'{finalResults[ev]} {ev}')