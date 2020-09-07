game = []
line = []
cnt = 0
checkDoubles = dict()

f = open("inputTest.txt", "r")

for horiz in f.readlines():
    line = list(map(int, horiz.split()))
    print (line)
    game.append(line)
print(game)

# horizontal lines
for horizontalLine in game:
    for i in range(1 , 10):
        if i  not in horizontalLine:
            print("Gresit")
            exit(1)

# vertical line
for i in range(0 , 9):
    for column in game:
        checkDoubles[i] = 1
    if len(checkDoubles) < 9:
        print ("Gresit")
        exit(1)

# innerSquare
for i in range(0, 3):
    for j in range(0, 3):
        for k in range(0, 3):
            for key in game[3 * i + k][3 * j : 3 * j + 3]:
                checkDoubles[key] = 1
        if len(checkDoubles) < 9:
            print("Gresit")
            exit(1)
        checkDoubles.clear()

print("Corect")
