#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

int placeHolder, height, width;
std::vector<std::vector<double>> matrix;
std::vector<double> line;
double max = 0, offset = 100000;
std::map<int, int> valuesCounter;
std::vector<std::pair<int, int>> sortedNumbers;

void ApplyTransform(const double &gain, const double &offset, double &number) {
    number = std::round((number - offset) * gain); // transform each number with given formula
}

bool SortVector(std::pair<int, int> pair1, std::pair<int, int> pair2) { // custom sorter
    if (pair1.second > pair2.second) { // sort by decreasing instances
        return true;
    }
    if (pair1.second == pair2.second) { // if instances are equal, sort in increasing order
        return pair1.first < pair2.first;
    }
    return false;
}

int main() {
    std::cin >> width >> height;

    while (std::cin >> placeHolder) {
        line.emplace_back(placeHolder); // append each line

        if (line.size() == width) {
            if (max < *std::max_element(line.begin(), line.end())) { // find max element (to calc gain later)
                max = *std::max_element(line.begin(), line.end());
            }

            if (offset > *std::min_element(line.begin(), line.end())) { // offset is min element
                offset = *std::min_element(line.begin(), line.end());
            }

            matrix.emplace_back(line);
            line.clear();
        }
    }


    double gain = 255.0 / (max - offset); // calc gain

    for (auto &entry : matrix) {
        for (auto &item : entry) {
            ApplyTransform(gain, offset, item); // for each number in matrix apply transform

            auto ret = valuesCounter.insert(std::make_pair(item, 1)); // make map that counts instances for each number
            if (!ret.second) {
                ++ret.first->second;
            }
        }
    }

    sortedNumbers = std::vector<std::pair<int, int>>(valuesCounter.begin(), valuesCounter.end()); // make vector with pairs in map
    std::sort(sortedNumbers.begin(), sortedNumbers.end(), SortVector); // sort vector created earlier

    for (auto it = sortedNumbers.begin(); it != sortedNumbers.end(); ++it) {
        std::cout << it->first << " "; // print current element
        if ((it + 1)->second != it->second) { // check if instances of next element are equal
            exit(1);
        }
    }

    return 0;
}
