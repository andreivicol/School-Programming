#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <iomanip>

int sets, setSize, coin, total;
std::map<int, int> coinCount;
// not working

int main() {
    std::cin >> sets;
    std::vector<int> useless(sets, 0);

    for (int i = 0; i != sets; ++sets){
        std::cin >> setSize;
        total = 0;
        int lessThanOne = 0;

        for (int j = 0; j != setSize; ++j){
            std::cin >> coin;
            total += coin;

            if (coin <= 100){
                ++lessThanOne;
            }

            auto ret = coinCount.insert(std::make_pair(coin, 1));
            if (!ret.second){
                ++ret.first->second;
            }
        }

        if (setSize < 8 or setSize > 20){
            ++useless[i];
            continue;
        }

        if (total > 2900 or coinCount.size() < 6 or 2 * lessThanOne < setSize){
            ++useless[i];
            continue;
        }
    }
    for (auto uselessSet : useless){
        std::cout << uselessSet << " ";
    }

    std::cout << '\n' << std::fixed << std::setprecision(2) << float( sets - std::accumulate(useless.begin(), useless.end(), 0) ) / float(sets);

    return 0;
}
