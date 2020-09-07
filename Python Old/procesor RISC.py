n = int(input())
instructiuni = []
registre = 16 * [0]

for i in range(n):
    instructiuni.append(list(input().split()))

for instr in instructiuni:
    if instr[0] == 'lconst':
        registre[int(instr[1])] = int(instr[2])

    if instr[0] == 'add':
        registre[int(instr[1])] = registre[int(instr[2])] + registre[int(instr[3])]

    if instr[0] == 'mul':
        registre[int(instr[1])] = registre[int(instr[2])] * registre[int(instr[3])]

    if instr[0] == 'div':
        if int(instr[3]) == 0:
            print("Exception: line", int(instructiuni.index(instr) + 1))
            break
        registre[int(instr[1])] = int(registre[int(instr[2])] / registre[int(instr[3])])

    if instr[0] == 'print':
        print(int(registre[int(instr[1])]))