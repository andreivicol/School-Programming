pages, books = input().split()

bookList = []

for i in range(int(books)):
    copies, bookEntry = input().split()
    for j in range(int(copies)):
        bookList.append(int(bookEntry)) # append 'copies' instances of 'bookEntry'

shelves = [[int(pages)] for i in range(len(bookList))] # make a list of lists, each inner list being [pages]

for book in bookList: # iterate through all the books
    for shelf in shelves: # for each book scan shelves starting with the first
        if sum(shelf) >= book: # if the difference between pages and added books >= current book
            shelf.append(-book) # append '-book' (so sum() is actually the difference)
            break # break to make sure no book is added twice

try:
    shelves = shelves[0: shelves.index([int(pages)])] # slice 'shelves' to become [ begin, first instance of [pages] )<-
except ValueError: # index returns value error if no [pages] is found; program will throw error w/out try
    pass # do nothing; shelves has been fully occupied

for shelf in shelves:
    for i in shelf[1::]: # first element in list is pages, so we ignore it
        print(-i, end=" ") # -i because we added -book
    print('\n') # add new line after each shelf