parties, surveys = input().split()

bestPartyName = ""
bestPartyPoints = 0
ascendingParties = []

for i in range(int(parties)):
    placeHolder = input().split() # each line as a list
    party = placeHolder[0] # fisr element in list is party name
    points = [int(x) for x in placeHolder[1::]] # list of ints

    if points[-1] - points[0] > bestPartyPoints: # check if you find a party with highest growth
        bestPartyPoints = points[-1] - points[0]
        bestPartyName = party

    unsorted = points

    if unsorted == sorted(points): # if unsorted == sorted => monotonous growth
        ascendingParties.append(party)

if len(ascendingParties) != 0: # check if ascending parties exist and print either them or message
    print(ascendingParties)
else:
    print("Nu exista")

print(f' {bestPartyName} {bestPartyPoints}%')