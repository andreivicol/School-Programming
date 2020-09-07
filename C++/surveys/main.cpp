#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string placeHolder;
std::vector<int> points, vectorPlaceHolder;
int point, parties, numberOfSurveys;
std::vector<std::string> ascendingParties;

int main() {
    std::cin >> parties >> numberOfSurveys;
    std::pair<std::string, int> bestParty{"plm", 0}; // construct initialized 'bestParty' for ease of comparison
    // this assumes there will be no party having 0% improvement

    while (std::cin >> placeHolder){
        for (int i = 0; i != numberOfSurveys; ++i){
            std::cin >> point;
            points.push_back(point); // create std::vector<int> holding the points
        }

        if ( *(points.end() - 1) - *points.begin() > bestParty.second){ // .end() - 1 denotes last element in vector
            bestParty.first = placeHolder; // so if last - first > stored value in 'bestParty' => update std::pair
            bestParty.second = *(points.end() - 1) - *points.begin();
        }

        vectorPlaceHolder = points;
        std::sort(points.begin(), points.end());

        if (vectorPlaceHolder == points){ // if a party has a constantly ascending evolution => sorted == unsorted
            ascendingParties.push_back(placeHolder);
        }
        points.clear();
    }

    if (!ascendingParties.empty()){ // check if ascending party exists
        for (const auto& party : ascendingParties){ // const because you dont need to modify element
            std::cout << party << " ";
        }
        std::cout << '\n';
    } else {
        std::cout << "Nu exista" << '\n';
    }

    std::cout << bestParty.first << " " << bestParty.second << "%";

    return 0;
}
