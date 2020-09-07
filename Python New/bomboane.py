days = int(input())
money = list(map(int, input().split()))
max = 0
happiness = 0

for ind, value in enumerate(money):
    day = list(map(int, input().split())) # each day make a list of cost and happiness

    try:
        if value - day[0] >= 0: # if he can afford that day's candy
            happiness += day[1] # add happiness
            money[ind + 1] += value - day[0] # add leftover money

            if max < day[1]: # if bought candy is new best
                max = day[1] # update max
        else: # if he can'r afford it
            if max <= day[1]: # check if its better than past ones
                happiness -= day[1]
            money[ind + 1] += value # add today's money to next day

    except IndexError:
        continue

print(happiness)
