#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>
#include <algorithm>

int givenDays, neededDays;
std::vector<float> prices;
float average = 0.0, placeHolder;

int main() {
    std::cin >> givenDays >> neededDays;

    for (int i = 0; i != givenDays; ++i) {
        std::cin >> placeHolder;
        prices.emplace_back(placeHolder); // emplace floats for prices
    }

    for (int i = 0; i != neededDays; ++i) {
        average = float(std::accumulate(prices.end() - givenDays, prices.end(), 0.0)) /
                  float(givenDays); // avg prices from past 'givenDays' days
        prices.emplace_back(average);
    }

    prices = std::vector<float>(prices.end() - neededDays, prices.end()); // resize vector
    for (const auto &price : prices) {
        std::cout << std::fixed << std::setprecision(2) << price << " "; // print prices
    }

    std::cout << '\n' << std::fixed << std::setprecision(2) << *std::max_element(prices.begin(), prices.end()) << " "
              << *std::min_element(prices.begin(), prices.end()); // find max and min

    return 0;
}
