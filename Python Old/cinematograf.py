arivalTime = input()
movies = int(input())

titles = []
movie = ""

for i in range(0, movies):
    titles.append(input())

startingHour = int(arivalTime[0:2]) * 60 + int(arivalTime[3::])
minTime = startingHour
price = 0

for title in titles:
    if int(title[0:2]) * 60 + int(title[3:5]) > startingHour:

        if int(title[0:2]) * 60 + int(title[3:5]) - startingHour < minTime:
            minTime = int(title[0:2]) * 60 + int(title[3:5]) - startingHour
            price = int(title[6:8])
            movie = title[9::]

        elif int(title[0:2]) * 60 + int(title[3:5]) - startingHour == minTime:
            if price > int(title[6:8]):
                movie = title[9::]
                price = int(title[6:8])

print(movie)
