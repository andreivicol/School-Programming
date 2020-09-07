#birthdays=['11-10','10-10','11-10','10-10', '12-12','11-10','09-09','10-10','08-08','10-10']
birthdays=[]

while True:
    try:
        a=input()
        birthdays.append(a)
    except EOFError:
        break

birthday={

}

for event in birthdays:
    if event not in birthday:
        birthday[event]=1
    else:
        birthday[event]+=1


sorted={k : v for k,v in sorted(birthday.items(), key=lambda item:item[1], reverse=True) }

for elem in sorted:
    print (elem)
