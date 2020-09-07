#include <iostream>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>

std::string placeHolder;
std::map<std::string, int> unsortedWords; // first instance to store and count words

bool SortingFunctor(std::pair<std::string, int>& pair1, std::pair<std::string, int>& pair2){ // make custom sorting
    if (pair1.second > pair2.second){ // that orders the vector using the 'value' in original map
        return true; // first, arrange items by largest pair.second
    }
    if (pair1.second == pair2.second){ // if they are equal
        return pair1.first < pair2.first; // place words in alphabetical order
    }
    return false; // default return for false cases
}

int main() {
    std::string inputWord = "";

    while (std::cin >> placeHolder){ // input a string
        for(auto& ch : placeHolder){ // iterate char&
            inputWord += std::tolower(ch); // lower case the char and append to word
        }

        auto ret = unsortedWords.insert(std::make_pair(inputWord, 1)); // try and insert new pair
        if (!ret.second){ // if word already exists
            ret.first->second += 1; // increment it
        }
        inputWord = "";
    }

    auto sortedWords = std::vector<std::pair<std::string, int>>(unsortedWords.begin(), unsortedWords.end());
    // use vector constructor to initialize 'sortedWords' as pairs inside 'unsortedWords'
    std::sort(sortedWords.begin(), sortedWords.end(), SortingFunctor); // use our custom sorting functor

    for (const auto& entry : sortedWords){
        std::cout << entry.first << " " << entry.second << '\n';
    }

    return 0;
}
