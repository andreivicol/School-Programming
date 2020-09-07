#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> stack;
std::string instruction;
int value, instructionNb;

void addValue(const int &number, std::vector<int> &memory) { // function to pop last 2 numbers and add value
    memory.pop_back();
    memory.pop_back();
    memory.push_back(number);
}

int main() {
    std::cin >> instructionNb;

    for (int i = 0; i != instructionNb; ++i) {
        std::cin >> instruction;

        if (instruction == "iload") { // if instr is 'iload'
            std::cin >> value; // append needed number
            stack.push_back(value);
            continue;
        }

        if (instruction == "iadd") {
            if (stack.size() > 1) { // is stack is at least 2 elements
                value = stack[stack.size() - 1] + stack[stack.size() - 2]; // add last 2 elements together
                addValue(value, stack);
                continue; // dont do unnecessary checks
            } else { // if not enough elements
                std::cout << "Exception: line " << i + 1 << '\n';
                exit(1); // throw exception and exit
            }
        }

        if (instruction == "imul") {
            if (stack.size() > 1) {
                value = stack[stack.size() - 1] * stack[stack.size() - 2]; // multiply last 2 elements
                addValue(value, stack);
                continue;
            } else {
                std::cout << "Exception: line " << i + 1 << '\n';
                exit(1);
            }
        }

        if (instruction == "dup") {
            if (!stack.empty()) { // if theres at least 1 element in stack
                stack.push_back(stack[stack.size() - 1]); // duplicate last element
                continue;
            } else {
                std::cout << "Exception: line " << i + 1 << '\n';
                exit(1);
            }
        }
    }

    std::cout << stack.size() << '\n';
    std::reverse(stack.begin(), stack.end()); // method for reversing a vector in  <algorithm>

    for (auto entry : stack) {
        std::cout << entry << '\n';
    }

    return 0;
}
