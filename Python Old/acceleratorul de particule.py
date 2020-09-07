r, a, n= input().split()
r=float(r)
a=float(a)
n=int(n)
values=[]

for i in range(n):
    user=float(input())
    values.append(user)

speed=4*3.1415*r*a*10**3*0.75
masses=[]
notknown=0

for value in values:
    masses.append((2*value)/speed)


for mass in masses:
    if mass>=0.9*1.67*10**-27 and mass<= 1.1*1.67*10**-27 :
        continue
    elif mass>=0.9*9.11*10**-31 and mass<=1.1*9.11*10**-31:
        continue
    else:
        notknown+=1

ratio=notknown/n

for plm in masses:
    print(f"{plm:.6e}")
print (round(ratio,4))