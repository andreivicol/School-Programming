concertsNb,gasPrice, consumption  = input().split()
holiday  = list(map(int, input().split()))

city = ""
cost = 0


def CalculatePrice(price, distance):
    total = 0
    total = price + 2*distance*float(consumption)*float(gasPrice)/3
    return total


def CorrectDate(date, month):
    if holiday[1] == holiday[-1] == month :
        if holiday[0] <= date <= holiday[-2]:  # concert is during holiday
            return 0

    if holiday[-1] > holiday[1]:  # holiday crossing to the next month and concert is in between
        if month == holiday[1] and date >= holiday[0]:
            return 0
        if month == holiday[-1] and date <= holiday[-2]:
            return 0

    return 1  # all other cases


for i in range(0, int(concertsNb)):
    concert = input().split()
    if CorrectDate(int(concert[1]), int(concert[2])):
        if cost == 0 and city == "":
            cost = CalculatePrice(int(concert[-2]), int(concert[-1]))
            city = concert[0]

        else:
            if CalculatePrice(int(concert[-2]), int(concert[-1])) < cost:
                cost = CalculatePrice(int(concert[-2]), int(concert[-1]))
                city = concert[0]

print(f'{city} {cost:.2f}')