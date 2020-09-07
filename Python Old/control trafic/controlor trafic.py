n=int(input("Maximum number of busses: "))
passed=list(map(int, input("Busses that passed: ").split()))

busses=[i for i in range(1,n+1)]
sum=0


for bus in busses:
    if bus not in passed:
        sum+=bus

print(sum)