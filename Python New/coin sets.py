sets = int(input())
useless = sets * [1] # a useless set it marked with a 0

for i in range(sets):
    coinNumber = int(input())
    coins = list(map(int, input().split())) # take all inputs as a list of int

    if coinNumber < 8 or coinNumber > 20: # check the no on coins
        useless[i] = 0
        continue # skip unnecessary checks

    counter = [x for x in coins if x < 100] # make list of coins < 100
    checkIfMissing = {x: 1 for x in coins} # dictionaries are unique, so insertion does not occur if key exists

    if sum(coins) > 2900 or len(counter) <= coinNumber / 2 or len(checkIfMissing) < 6:
        useless[i] = 0 # check if > 29 lei, if coins < 100 are less than half or number of individual coins < 6

print(*useless)
print(round((sets - sum(useless)) / sets, 2))
