givenDays, neededDays = input().split()
givenDays = int(givenDays)
neededDays = int(neededDays)

prices = list(map(float, input().split()))

for i in range(neededDays):
    prices.append(round(sum(prices[-givenDays::])/givenDays, 2)) # take the sum of the last 'givenDays' and average it

print(*prices[-neededDays::]) # print last 'neededDays'
print(f'{max(prices[-neededDays::])} {min(prices[-neededDays::])}') # find min and max of sequence