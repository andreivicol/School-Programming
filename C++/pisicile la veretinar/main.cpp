#include <iostream>
#include <vector>
#include <algorithm>

int cats, boxes, counter = 0, placeHolder;
std::vector<int> catSizes, boxVolume;

int main() {
    std::cin >> cats >> boxes;

    while (std::cin >> placeHolder) {
        if (catSizes.size() < cats) {
            catSizes.emplace_back(placeHolder);
        } else {
            boxVolume.emplace_back(placeHolder);
        }
    }

    std::sort(catSizes.begin(), catSizes.end());
    std::sort(boxVolume.begin(), boxVolume.end());

    for (const auto &cat : catSizes) {
        for (auto &box : boxVolume) {
            if (box - cat > 0) {
                ++counter;
                box = 0;
                break;
            }
        }
    }

    std::cout << counter << '\n';

    return 0;
}
