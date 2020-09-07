#include <iostream>
#include <map>

int batches, longestBatch = 0, usefulBatches = 0, batchSize;
std::map<char, int> components;
char component;

int main() {
    std::cin >> batches;

    for (int i = 0; i != batches; ++i){
        std::cin>> batchSize;

        if (longestBatch < batchSize){
            longestBatch = batchSize;
        }

        for (int j = 0; j != batchSize; ++j){
            std::cin>> component;
            auto ret = components.insert(std::make_pair(component, 1));

            if (!ret.second){
                ++ret.first->second;
            }
        }

        if (components.size() < 3){
            continue;
        }

        if (components['C'] >= components['T'] and components['R'] >= components['T']){
            ++usefulBatches;
        }
        components.clear();
    }

    std::cout<<usefulBatches<<" "<<longestBatch;

    return 0;
}