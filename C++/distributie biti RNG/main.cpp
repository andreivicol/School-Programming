#include <iostream>
#include <string>
#include <algorithm>

int bitNb;
std::string sequence, placeHolder = "";

int main() {
//    std::cin >> bitNb;
//    std::cin >> sequence;
    sequence = "101100110111100001";

    int digitCnt[2] = {}; // array of zeroes; indexes are [0, 1]
    int seqCnt[4] = {};  // array of zeroes; indexes in binary are [00, 01, 10, 11]

    for (int i = 0; i != sequence.length() / 2; ++i) { // iterate length/2 times over the string

        placeHolder = sequence.substr(i * 2, 2); // each iteration is 2 characters long
        ++seqCnt[std::stoi(placeHolder, nullptr, 2)]; // convert literal string placeHolder written in base 2 to base 10 int
                                                                // and increment element at index

        for (auto chr : placeHolder) {
            ++digitCnt[static_cast<int>(chr - '0')]; // static cast from char to int. each char has decimal, hex and binary values
        } // convert to decimal and subtract decimal value of '0' to get index
    } // ex: '4' is 52 in decimal '0' is 48 thus '4' - '0' = 4 and so on; can also write static_cast<int>(chr - 48)


    float ratio1 = float(*(std::max_element(digitCnt, digitCnt + 2))) / float(*(std::min_element(digitCnt, digitCnt + 2)));
    float ratio2 = float(*(std::max_element(seqCnt, seqCnt + 4))) / float(*(std::min_element(seqCnt, seqCnt + 4)));
    // max_element and min_element return iterator to said element in array and need dereference *
    // could also use minmax_element that returns std::make_pair(min_iterator, max_iterator)

    std::cout<<ratio1<<" "<<ratio2<<std::endl;

    if (ratio2 <= 1.1 and ratio1 <= 1.1){
        std::cout<<'1';
    }else{
        std::cout<<'0';
    }

    return 0;
}
