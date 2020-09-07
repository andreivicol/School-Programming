values = list(map(int, input().split()))

students = dict()
stud = []
scholarshipCnt = 0
max = 0
failed = False

for i in range(0, 2 * values[0]):
    placeHolder = input()
    grades = list(map(int, input().split()))
    students[placeHolder] = float(sum(grades) / 3)

    for grade in grades:
        if grade < 5:
            failed = True

    if max < float(sum(grades) / 3):
        max = float(sum(grades) / 3)
        stud = [placeHolder, max]

sort = {k: v for k, v in sorted(students.items(), key=lambda item: item[1], reverse=True)}

for key, value in sort.items():
    if value > 8:
        scholarshipCnt += 1

if scholarshipCnt < values[-1]:
    print(scholarshipCnt)
else:
    print(values[-1])

print(f'{stud[0]} {stud[1]:.2f}')
