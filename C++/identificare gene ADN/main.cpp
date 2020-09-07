#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::string dnaSequence, lookUpSequence, reversed = "";
std::vector<int> coordinates;
int sequenceCnt;
bool found = false;

void ScanSequence(const std::string &dna, const std::string &find) { // function to find sequence
    for (auto it = dna.begin(); it != dna.end(); ++it) {
        found = false;
        if (find[0] == *it) { // checks only start if the first letter matches

            for (int i = 1; i != find.length(); ++i) { // check next letters
                if (find[i] != *(it + i)) { // if it's different => break
                    break;
                }
                if (i == find.length() - 1) { // if all were equal, mark as found
                    found = true;
                }
            }

            if (found or find.length() == 1) { // check if sequence was found or its length is 1
                ++sequenceCnt;
                coordinates.emplace_back(it - dna.begin());
            }
        }
    }
}

int main() {
    std::cin >> dnaSequence >> lookUpSequence;

    std::map<char, char> correspondence = {{'A', 'T'}, // map to find correspondence between letters
                                           {'T', 'A'},
                                           {'C', 'G'},
                                           {'G', 'C'}};

    for (const auto &ch : lookUpSequence) {
        reversed += correspondence[ch];
    }
    std::reverse(reversed.begin(), reversed.end()); // construct and reverse the second lookup seq

    ScanSequence(dnaSequence, lookUpSequence); // call function on both instances
    ScanSequence(dnaSequence, reversed);

    std::sort(coordinates.begin(), coordinates.end()); // sort because indexes need to be in increasing order

    std::cout << sequenceCnt << '\n';
    for (const auto &coord : coordinates) {
        std::cout << coord << " ";
    }

    return 0;
}
