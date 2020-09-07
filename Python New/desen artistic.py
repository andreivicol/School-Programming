coloursNumber = input()
colors = input().split()
kids = []
finishedDrawings = []
combined = True

combinations = {"purple": ["red", "blue"], "orange": ["red", "yellow"], "green": ["yellow", "blue"],
                "brown": ["red", "yellow", "blue"]}  # dictionary that holds combinations needed for each colour

while True:
    try:  # input until EOF
        drawing = input().split()
        kids.append(drawing)
    except EOFError:
        break

for drawing in kids:  # for every drawing
    combined = True
    for colour in drawing[2::]:  # make a list of all needed colours and iterate over it
        if colour not in colors:  # if current colour is in 'colors' => do nothing, else
            if colour not in combinations:  # check if color can be combined
                combined = False  # if not, combined = False and break => check next drawing
                break
            else:  # if it can be made
                for clr in combinations[colour]:  # check if all colours needed are in 'colors'
                    if clr not in colors:
                        combined = False
                        break
    if combined:  # combined is False only when a drawing cant be made
        finishedDrawings.append(drawing[0])

for child in finishedDrawings:
    print(child)
