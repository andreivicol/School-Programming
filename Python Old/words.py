f=open('source_text.txt', 'r',encoding="utf8")

d=open('single_words2.txt', 'w+')

lista=[]
ch=''
lengths=[]

for word in f.read().split(" "):
    for letter in word.lower():
        if letter.isalpha():
            ch+=letter
        else:
            continue
    if ch in lista:
        ch=''
        continue
    elif(len(ch)<4):
        ch=''
    else:
        lista.append(ch)
        ch=''

print(len(lista))

for elem in lista:
    d.write(str(elem)+"\n")






