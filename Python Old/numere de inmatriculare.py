import random
plates=[]
valid=['AB', 'AR', 'AG', 'B', 'BC', 'BH', 'BN', 'BT', 'BV', 'BR', 'BZ', 'CS', 'CL', 'CJ', 'CT', 'CV', 'DB', 'DJ', 'GL', 'GR', 'GJ', 'HR', 'HD', 'IL', 'IS', 'IF', 'MM', 'MH', 'MS', 'NT', 'OT', 'PH', 'SM', 'SJ', 'SB', 'SV', 'TR', 'TM', 'TL', 'VS', 'VL', 'VN']
toprint=[]

for i in range(3):
    plates.append(input().split())

for ind, elem1 in enumerate(plates):
    if any((not elem1[0] in valid,
            not (elem1[1].isdigit() or 1 < len(elem1[1]) <= 3),
            not (elem1[2].isalpha() or elem1[2].isupper()))):
        continue
    print(' '.join(elem1))

# for ind1,elem1 in enumerate(plates):
#     for ind, elem in enumerate(elem1):
#         if elem1[0] in valid:
#             pass
#         else:
#             continue
#
#         if elem1[1].isdigit() and 1<len(elem1[1])<=3:
#             pass
#         else:
#             continue
#
#         if elem1[2].isalpha() and elem1[2].isupper():
#             pass
#         else:
#             continue

# rezolvare reddit
#
# import random
# plates=[]
# valid=['AB', 'AR', 'AG', 'B', 'BC', 'BH', 'BN', 'BT', 'BV', 'BR', 'BZ', 'CS', 'CL', 'CJ', 'CT', 'CV', 'DB', 'DJ', 'GL', 'GR', 'GJ', 'HR', 'HD', 'IL', 'IS', 'IF', 'MM', 'MH', 'MS', 'NT', 'OT', 'PH', 'SM', 'SJ', 'SB', 'SV', 'TR', 'TM', 'TL', 'VS', 'VL', 'VN']
#
# #for i in range(random.randint(1,4)):
# #    plates.append(input().split())
# plates = [("SV", '17', "AAK"), ('CT', '999', 'SM'),
#           ('GL', '22', 'BRB'), ('B', '123', 'TTY'),
#           ('NG', '22', 'BRB'), ('GL', '1111', 'BRB'), ('GL', '22', 'bRB')]
#
# for elem in plates:
#     if all((elem[0] in valid,
#             (elem[1].isdigit() and 1<len(elem[1])<=3),
#             (elem[2].isalpha() and elem[2].isupper()))):
#         print(' '.join(elem))
#     else:
#         print("skipping {}".format(elem))

