#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string sequence;
int bits, cnt = 0;

bool orderFunctor(int &num1, int &num2) {
    return num1 > num2;
}

int main() {
    std::cin >> bits;
    std::cin >> sequence;
    sequence += '0';

    std::vector<int> counter(bits, 0);

    for (auto number : sequence) {
        if (number == '1') {
            ++cnt;
        } else {
            if (cnt >= 1) {
                ++counter[cnt - 1];
                cnt = 0;
            }
        }
    }

    for (auto it = counter.begin(); it != counter.end(); ++it) {
        if (std::count(it, counter.end(), 0) == counter.end() - it) {
            counter = std::vector<int>(counter.begin(), it);
            break;
        } else {
            std::cout << *it << " ";
        }
    }

    auto unordered = counter;
    std::sort(counter.begin(), counter.end(), orderFunctor);

    std::cout << std::endl;

    if (unordered == counter) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }

    return 0;
}
