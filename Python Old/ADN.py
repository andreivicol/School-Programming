s = input()
g = input()
cnt = 0
indices = []
instances = 0
o = ''

for letter in g:
    if letter == 'A':
        o += 'T'
    elif letter == 'T':
        o += 'A'
    elif letter == 'C':
        o += 'G'
    else:
        o += 'C'

sec = o[::-1]

for ind, elem in enumerate(s):
    cnt = 0
    if g[0] == elem:
        cnt += 1
        for i in range(1, len(g)):
            try:
                if g[i] == s[ind + i]:
                    cnt += 1
            except IndexError:
                continue
        if cnt == len(g):
            indices.append(ind)
            instances += 1

for ind, elem in enumerate(s):
    cnt = 0
    if sec[0] == elem:
        cnt += 1
        for i in range(1, len(sec)):
            try:
                if sec[i] == s[ind + i]:
                    cnt += 1
            except IndexError:
                continue
        if cnt == len(sec):
            indices.append(ind)
            instances += 1

print(instances)
print(*sorted(indices), sep=' ')