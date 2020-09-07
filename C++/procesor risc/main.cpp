#include <iostream>
#include <vector>
#include <string>

std::string instruction;
int instructionNb, destination, source1, source2, exceptionLine = 0;

int main() {

    std::cin >> instructionNb;

    std::vector<int> registers(16, 0); // construct vector with 16 0s

    while (std::cin >> instruction){
        ++exceptionLine; // one based line counter
        if (instruction == "lconst"){
            std::cin >> destination >> source1;
            registers[destination] = source1; // add source1 into destination
            continue; // skip unnecessary checks
        }

        if (instruction == "add"){
            std::cin >> destination >> source1 >> source2;
            registers[destination] = registers[source2] + registers[source1]; // add values in registers
            continue;
        }

        if (instruction == "mul"){
            std::cin >> destination >> source1 >> source2;
            registers[destination] = registers[source2] * registers[source1]; // mul values in registers
            continue;
        }

        if (instruction == "div"){
            std::cin >> destination >> source1 >> source2;
            if (registers[source2] != 0) { // check that value in reg is not zero
                registers[destination] = registers[source1] / registers[source2]; // divide registers
            } else {
                std::cout << "Exception: line " << exceptionLine << '\n';
                exit(1); // if value is 0, throw exception and exit
            }
            continue;
        }

        if (instruction == "print"){
            std::cin >> destination;
            std::cout << registers[destination] << '\n'; // print given register
            continue;
        }
    }

    return 0;
}
