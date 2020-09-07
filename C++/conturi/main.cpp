#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

std::vector<int> account, variation;
int placeHolder, mem = 0, cnt = 0;
bool initialized = false;
double averageValue = 0.0, averageVariation = 0.0;

int singum(int &current) { // basic signum function that returns 1 for positive and -1 for negative
    return (current >= 0) ? 1 : -1;
}

int main() {

    std::cin >> placeHolder;

    while (std::cin >> placeHolder) {
        account.push_back(placeHolder); // append entry to account vector

        if (initialized) {
            variation.push_back(placeHolder - mem); // append differance of consecutive days to variation
            mem = placeHolder;
        } else {
            initialized = true; // bool to start variation from second day
            mem = placeHolder;
        }
    }

    placeHolder = 0; // resuse same variable

    averageValue = std::accumulate(account.begin(), account.end(), 0.0) / account.size(); // accumulate sums all numbers in vector;  add to 0.0 to get double
    averageVariation = std::accumulate(variation.begin(), variation.end(), 0.0) / variation.size();

    auto pos = variation.begin(); // global iterator to find needed sequence

    for (auto it = variation.begin(); it != variation.end() - 1; ++it) {
        if (singum(*it) != singum(*(it + 1))) { // check whether 2 consecutive variations have different signum
            ++cnt; // count number of variations - 1
        } else {
            if (placeHolder <= cnt) {
                pos = it - cnt; // go back it - cnt positions
                placeHolder = cnt; //remember longest sequence
                cnt = 0; // reset cnt
            } else {
                cnt = 0; // if placeHolder > cnt reset cnt also
            }
        }
    }

    if (placeHolder == 0) {
        std::cout << 0;
        exit(1); // exit if all entries are equal
    }

    int start = pos - variation.begin(); // position to slice account
    auto sequence = std::vector<int>(account.begin() + start + 1, account.begin() + start + 2 + placeHolder); // +1 because [first, last)

    std::cout << placeHolder + 1 << '\n';

    for (auto value : sequence) {
        std::cout << value << " ";
    }

    std::cout << '\n' << std::setprecision(2) << std::fixed << averageValue << " " << averageVariation;

    return 0;
}
