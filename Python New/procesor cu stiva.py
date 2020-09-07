instructions = int(input())
stack = [] # create empty list

for cycle in range(instructions):
    instruction = list(input().split()) # save each instruction as a list

    if instruction[0] == "iload":
        stack.append(int(instruction[1])) # add to end of stack
        continue

    if instruction[0] == "dup":
        if len(stack) > 0: # check if theres at least one element
            stack.append(stack[-1])
            continue # continue so you dont do unnecessary checks
        else:
            print(f'Exception: line {cycle + 1}') # range is 0 based so add 1
            exit(1) # exit

    if instruction[0] == "imul":
        if len(stack) > 1:
            stack.append(stack.pop(len(stack) - 1) * stack.pop(len(stack) - 1)) # to read: .pop()
            continue # pop returns the element it pops, so we can use it straight away. element is always at index len - 1
        else:
            print(f'Exception: line {cycle + 1}')
            exit(1)

    if instruction[0] == "iadd":
        if len(stack) > 1:
            stack.append(stack.pop(len(stack) - 1) + stack.pop(len(stack) - 1)) # same thing, just with addition
            continue
        else:
            print(f'Exception: line {cycle + 1}')
            exit(1)

print(len(stack))
stack.reverse() # use .reverse() method to reverse list; can't use it directly in for => returns None

for element in stack:
    print(element)
