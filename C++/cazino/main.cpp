#include <iostream>
#include <map>
#include <vector>
#include <string>

std::map<std::string, int> game;
std::string placeHolder;
std::vector<std::string> card;
int hands;

int main() {
    std::cin >> hands;

    while (std::cin >> placeHolder) {
        card.push_back(placeHolder);
        if (card.size() == 2) {
            auto ret = game.insert(std::make_pair(card[0] + " " + card[1], 1));

            if (!ret.second) {
                ++ret.first->second;
                if (ret.first->second == 3) {
                    std::cout << ret.first->first << std::endl;
                    exit(0);
                }
            }
            card.clear();
        }
    }

    std::cout << "JOC OK" << std::endl;

    return 0;
}
