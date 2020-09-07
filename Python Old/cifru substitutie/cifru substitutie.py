texti=input("Write the text you want to code: ")
code=input("Type in your secret cypher: ").split(' ')


new_code=[]
final_text=[]


for element in code:
    new_code.append(element.split(','))



for letter in texti:
    if letter not in [x[0] for x in new_code ]:
        final_text.append(letter)
        continue

    for ind, elem in enumerate(new_code):
        if letter==elem[0]:
            final_text.append(elem[1])
            break


print (''.join(final_text))