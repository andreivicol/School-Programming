def HowManyProblems(pages):
    if pages > 0:
        return pages + HowManyProblems(pages - 1) # count how many problems can fit on given 'pages'
    return 0


pages, problems = input().split()
letterC = 0 # letter counter

if int(problems) <= HowManyProblems(int(pages)): # if problems fit
    for i in range(1, int(problems) + 1):
        letterC += len(str(i)) # count the number of digits

print(letterC)