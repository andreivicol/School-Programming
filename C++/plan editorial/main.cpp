#include <iostream>
#include <string>

int pages, problem, letterC = 0;

int sumProblems(int size){ // recursive function that calls itself and returns sum of all numbers[1, size]
    if (size > 0){
        return size + sumProblems(size - 1);
    }
    return 0; // there won't be pages <=0, but compiler requires non-void function to always return 'type'
}

int main() {
    std::cin >> pages >> problem;

    if (problem <= sumProblems(pages)){ // check if the problem can fit within the given pages
        for (int j = 1; j <= problem; ++j){
            letterC += std::to_string(j).size(); // if it can, simply count the number of chars in the converted string
        }
    } // if using C++11(and before) or C++20, there exists std::string::length that does the same thing
    // also std::distance(begin(), end())

    std::cout << letterC << '\n'; // if condition fails, 'letterC' is already 0;

    return 0;
}
