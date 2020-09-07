#include <iostream>
#include <vector>

int days, happiness = 0, cost, candyHappiness, max = 0;
std::vector<int> dailyBudget;

int main() {

    std::cin >> days;

    for (int i = 0; i != days; ++i) {
        std::cin >> cost;
        dailyBudget.push_back(cost); // make vector with given money
    }

    for (auto it = dailyBudget.begin(); it != dailyBudget.end(); ++it) { // for each day you're given money
        std::cin >> cost >> candyHappiness; // input candy cost and candyHappiness

        if (*it - cost >= 0) { // if he can afford the candy
            happiness += candyHappiness; // increase happiness
            if (it != dailyBudget.end() - 1) { // and if its not the last element => program throws index out of range
                *(it + 1) += *it - cost; // add leftover money to next day; diff can be 0
            }
            if (candyHappiness > max) { // find best candy so far
                max = candyHappiness;
            }
        } else { // if he cant afford it
            if (it != dailyBudget.end() - 1) {
                *(it + 1) += *it; // add leftover money
            }
            if (max <= candyHappiness) { // if its a new best candy
                happiness -= candyHappiness; // make mf sad
            }
        }
    }

    std::cout << happiness<< '\n';

    return 0;
}
