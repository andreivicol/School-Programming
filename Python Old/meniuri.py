from enum import Enum
menus = list( x for x in input().split() )

class dishes(Enum): # enum with dish order => could also use auto()
    A = 1
    C = 2
    P = 3
    D = 4

correct = 0
unknown = 0
single = 0
mem = 0 # go back mem positions

for ind, order in enumerate(menus):
    try: # always check current and next element // ind + 1 throws for last element in list
        if dishes[order[0]].value < dishes[menus[ind + 1][0]].value: #if order of dishes is respected
            mem += 1 # go back one extra position

        else:
            if mem == 0: # single dish
                single += 1

            else:
                if '0' in [x[1] for x in menus[ind - mem : ind + 1]]: # check if there's a 0 between (ind - mem) and current position (ind + 1)
                    unknown += 1
                    correct += 1
                    mem = 0 # always reset position

                else: # if not, all items are known
                    correct += 1
                    mem = 0

    except IndexError: # last element reached
        if dishes[order[0]].value <= dishes[menus[ind - 1][0]].value: # check if it's a single dish
            single += 1

        else:
            if '0' in [x[1] for x in menus[ind - mem  : ind + 1]]: # again check for 0s
                unknown += 1
                correct += 1
            else:
                correct += 1

print(correct)
print(unknown)
print(single)