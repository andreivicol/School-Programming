#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int number, placeHolder, counter = 0, half;
std::vector<int> sequence, corrections;

int main() {
    std::cin >> number;
    for (int i = 0; i != number; ++i) {
        std::cin >> placeHolder;
        sequence.emplace_back(placeHolder); // hold numbers in a vector
    }

    for (auto it = sequence.begin() + 1; it != sequence.end(); ++it) { // start iteration from second number
        if (*it <= std::accumulate(sequence.begin(), it, 0)) { // if number is <= than the sum of previous numbers
            ++counter; // increase counter
            *it += std::accumulate(sequence.begin(), it, 0) + 1 - *it; // add to it the diff between itself and sum +1
            corrections.emplace_back(it - sequence.begin() + 1); // append index of correction
        }
    }

    (number % 2 == 0) ? half = number / 2 : half = number / 2 + 1; // corrections are allowed in the middle if length is odd

    if (counter == 0) {
        std::cout << counter << '\n' << "ACCEPT" << '\n';
        exit(0);
    }

    std::cout << counter << '\n';
    for (const auto &correction : corrections) {
        std::cout << correction << '\n';
    }
    // check if <= 3 corrections were made and highest index is <= half
    // can also write it as corrections.back() <= half
    if (counter <= 3 and *std::max_element(corrections.begin(), corrections.end()) <= half) {
        std::cout << "ACCEPT" << '\n';
    } else {
        std::cout << "RESPINS" << '\n';
    }

    return 0;
}
