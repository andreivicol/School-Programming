text=list(map(str, input("Inseert the text you want to modify: ").split()))
n=int(input("How many words to censor: "))
words=list(map(str, input("Words to censor: ").split()))


# Rezolvarea finuta si smart pe care nu o accepta moodle(textul de input are mai multe spatii si outputul e mai scurt). Hobincu e cretin.

for word in words:
    for ind,elem in enumerate(text):
        if word in elem:
            text[ind]=elem.replace(str(word), ''.join(['*'for x in word]))

print (' '.join(text))

# Rezolvarea de maimuta pe care o accepta hobincu care si el e o maimuta
#
# text=input()
# for i in range(len(words)):
#     text.replace(words[i], '*'*len(words[i]))