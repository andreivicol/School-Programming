#include <iostream>
#include <string>
#include "Permutari.h"

std::string word;

int main() {

    std::cin>>word;
    Permutari permutari(word);
    permutari.printPermutations(word);

    return 0;
}
