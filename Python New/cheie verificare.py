password = int(input())
generator = int(input())

secret = [int(x) for x in str(password * generator)] # make a list of digits in product

# print(f'pass: {password} gen: {generator} product: {password * generator}')

while len(secret) > 1:
    result = sum(secret) # sum all digits
    secret = [int(x) for x in str(result)] # store the result as list of digits

print(*secret)