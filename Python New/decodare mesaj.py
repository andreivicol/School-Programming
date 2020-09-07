entry = input()

secretMessage = ""
number = [digit for digit in entry] # make list of all digits

while len(number) > 0:
    if number[0] == '0': # if current char is '0'
        if number[1] == '0': # if second char is 0
            secretMessage += chr(32) # add space
        else:
            secretMessage += chr(int(number[1]) + 64) # else add second letter
        number.pop(0) # pop current and next element
        number.pop(0)

    else:
        if len(number) > 1: # if length is > 2 we can do 2 pops
            if int(number[0] + number[1]) <= 26: # if number is < 26
                secretMessage += chr(int(number[0] + number[1]) + 64) # add that letter to word
                number.pop(0) # do first pop
            else:
                secretMessage += chr(int(number[0]) + 64) # else only add current letter
            number.pop(0) # this is the first pop for else and second for if => mode efficient
        else:
            secretMessage += chr(int(number[0]) + 64) # if its the last letter, add it to word

print(secretMessage)
