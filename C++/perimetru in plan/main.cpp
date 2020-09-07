#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int gridSize, figureSize, sideLength, firstNum, secondNum;
std::string placeHolder, coordinate;
std::vector<std::pair<int, int> > coordinates;
bool secondNumber = false;

int main() {
    std::cin >> gridSize >> figureSize;
    int totalSides = 4 * figureSize; // each square has 4 sides, so the nb of sides is figureSize * 4

    for (int i = 0; i != figureSize; ++i) {
        std::cin >> placeHolder; // input coordinates as string
        
        for (auto it = placeHolder.begin(); it != placeHolder.end(); ++it) { // iterate string to find digits
            if (std::isdigit(*it)) { // if you find a digit
                if (std::isdigit(*(it + 1))) { // and next one is a digit too
                    coordinate = new char[2]; // redefine 'coordinate' to be array of 2 chars
                    coordinate[0] = *it; // form number
                    coordinate[1] = *(it + 1);
                    ++it; // increment 'it' to accound for 2 digit number
                } else {
                    coordinate = *it; // if next char is not number
                }
                if (secondNumber) { // each coordinate has 2 numbers, so you need to separate them
                    secondNum = std::stoi(coordinate);
                    secondNumber = false;
                } else {
                    firstNum = std::stoi(coordinate);
                    secondNumber = true; // after you create firstNum, set bool to initialize secondNum
                }
            }
        }
        coordinates.push_back(std::make_pair(firstNum, secondNum)); // after each coordinate append new pair
    }

    std::cin >> sideLength;

    for (auto pair : coordinates) { // take each pair of coordinates
        for (auto pair2 : coordinates) { // and iterate through the entire grid
            if (pair.first == pair2.first and std::abs(pair.second - pair2.second) == 1) {
                --totalSides; // if they're on the same line and neighbouring squares
            } // subtract a side from each square
            if (pair.second == pair2.second and std::abs(pair.first - pair2.first) == 1) {
                --totalSides; // same for columns
            }
        }
    }

    std::cout << totalSides * sideLength; // the perimeter will be remaining sides * sideLength

    return 0;
}
