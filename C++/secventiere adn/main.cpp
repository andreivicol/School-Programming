#include <iostream>
#include <vector>
#include <map>
#include <string>

std::string ADN;

int main() {
    std::map<char, char> correspondence = {{'A', 'T'}, // map holds correspondence between letters
                                           {'T', 'A'},
                                           {'G', 'C'},
                                           {'C', 'G'}};

    std::cin >> ADN;

    auto firstSeq = std::vector<char>(ADN.begin(), ADN.begin() + ADN.size() / 2); // make vector<char> with first half
    auto secondSeq = std::vector<char>(ADN.rbegin(), ADN.rbegin() + ADN.size() / 2); // same with second half, but reversed

    for (auto it = firstSeq.begin(); it != firstSeq.end(); ++it){ // for each char in first vector
        if (correspondence[*it] != secondSeq[it - firstSeq.begin()]){ // check if corresponding letter is found in the second vector
            std::cout << it - firstSeq.begin() + 1; // +1 because vector indexes are 0 based
            exit(1); // exit to skip unnecessary processing and eliminate the need for a counter
        }
    }

    std::cout << 0; // if condition inside for never checks, program will print 0 by default

    return 0;
}
