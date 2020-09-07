numere = ['1111110', '0110000', '1101101', '1111001', '0110011', '1011011', '1011111', '1110000', '1111111', '1111011']
values = []
to_print = ''

while True:
    try:
        a = input()
        values.append(''.join(a.split(',')))
    except:
        break

for elem in values:

    if elem[0:7] not in numere:
        break

    for number in numere:

        if elem[-1] != '1' and elem[-1] != '0':
            break

        if elem[0:7] == number:
            to_print += str(numere.index(number))

            if elem[-1] == '1':
                to_print += '.'

    if elem[-1] != '1' and elem[-1] != '0':
        break

print(to_print)



# numere={
#     '1':'0110000',
#     '2':'1101101',
#     '3':'1111001',
#     '4':'0110011',
#     '5':'1011011',
#     '6':'1011111',
#     '7':'1110000',
#     '8':'1111111',
#     '9':'1111011',
#     '0':'1111110'
# }
# values=[]
# string=''
#
# while True:  #input for moodle EOF
#     try:
#         a=input()
#         values.append(''.join(a.split(',')))
#     except :
#         break
#
# while True:
#     a=input()
#     if a=='':
#         break
#     else:
#         values.append(''.join(a.split(',')))
#
# for element in values:
#     for key, value in numere.items():
#         if element[0:7]==value:
#             string+=key
#             if element[-1]=='1':
#                 string+='.'
#
# print (string)
