#include <iostream>
#include <vector>
#include "Hash.h"

int numbers, repetitions, placeHolder;
std::vector<int> values;

int main() {

//    std::cin>>numbers>>repetitions;
//    while (std::cin>>placeHolder){
//        values.emplace_back(placeHolder);
//    }

    repetitions = 3;
    values = {2228, 6};

    Hash hash;
    hash.setEntry(values);
    hash.setSumVector(repetitions);
    std::cout<<hash.getSum()<<std::endl;

    return 0;
}
