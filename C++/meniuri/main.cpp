#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> oreders;
std::string placeHolder;
int correct = 0, unknown = 0, single = 0, position = 0;
bool unknownDish = false;

int main() {
    while (std::cin >> placeHolder) { // input each order
        if (placeHolder[0] == 'D') // if order code is D, change it to X for ASCII subtraction
            placeHolder[0] = 'X';

        oreders.emplace_back(placeHolder); // append to vector of orders
    }

    for (auto it = oreders.begin(); it != oreders.end(); ++it) { // iterate through orders
        if (it + 1 == oreders.end()) { // if its the last dish in order !!! START READING FROM ELSE BRANCH !!!
            if ((*it)[0] <= (*(it - 1))[0]) { // if current dish has letter before previous dish
                ++single; // it means its a single dish
            } else { // it means position > 1
                for (auto reit = it - position; reit <= it; ++reit) { // go back positions and do the checks again
                    if ((*reit)[1] == '0') {
                        unknownDish = true;
                    }
                }
                if (unknownDish) {
                    ++unknown;
                    ++correct;
                } else {
                    ++correct;
                }
            }
        } else {
            if ((*it)[0] < (*(it + 1))[0]) { // if current dish has letter before next one
                ++position; // increase position
            } else { // if letter is equal or bigger
                if (position == 0) { // check whether its the end of a sequence or consecutive single dishes
                    ++single;
                } else { // if its the end of a sequence ( position > 1)
                    for (auto reit = it - position; reit <= it; ++reit) { // go back 'positions'
                        if ((*reit)[1] == '0') { // and check if any order has a '0'
                            unknownDish = true;
                        }
                    }
                    if (unknownDish) { // if there was an unknown dish
                        ++unknown; // increment both correct and unknown
                        ++correct;
                        unknownDish = false;
                    } else {
                        ++correct;
                    }
                    position = 0; // reset position
                }
            }
        }
    }

    std::cout << correct << std::endl;
    std::cout << unknown << std::endl;
    std::cout << single << std::endl;

    return 0;
}
