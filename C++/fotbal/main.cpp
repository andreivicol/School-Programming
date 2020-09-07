#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int teams, games;

std::vector<std::string> placeHolder;
std::string game;

std::map<std::string, int>givenGoals, receivedGoals, points;

bool compare(const std::pair<std::string, int>& pair1, const std::pair<std::string, int>& pair2){
    return pair1.second > pair2.second;
}

int main() {
    std::cin>>teams>>games;

    for (int i = 0; i != games ; ++i) {
        for (int j = 0; j != 5; ++j) {
            std::cin >> game;
            if (game=="-")
                continue;
            placeHolder.push_back(game);
        }

        auto ret = givenGoals.insert({placeHolder[0], std::stoi(placeHolder[1])});
        if (!ret.second){ // insert returneaza o pereche <iterator, bool>, unde iterator pointeaza la o pereche (key, value)
            ret.first->second+=std::stoi(placeHolder[1]);
        }
        ret = givenGoals.insert({placeHolder[3], std::stoi(placeHolder[2])});
        if (!ret.second){
            ret.first->second+=std::stoi(placeHolder[2]);
        }

        ret=receivedGoals.insert({placeHolder[0], std::stoi(placeHolder[2])});
        if (!ret.second){
            ret.first->second+=std::stoi(placeHolder[2]);
        }
        ret=receivedGoals.insert({placeHolder[3], std::stoi(placeHolder[1])});
        if (!ret.second){
            ret.first->second+=std::stoi(placeHolder[1]);
        }

        if (std::stoi(placeHolder[1]) > std::stoi(placeHolder[2])) {
            ret = points.insert({placeHolder[0], 3});
            if (!ret.second)
                ret.first->second+=3;
        }else if (std::stoi(placeHolder[1]) == std::stoi(placeHolder[2])) {
            ret = points.insert({placeHolder[0], 1});
            if (!ret.second)
                ret.first->second+=1;
            ret = points.insert({placeHolder[3], 1});
            if (!ret.second)
                ret.first->second+=1;
        } else{
            ret = points.insert({placeHolder[3], 3});
            if (!ret.second)
                ret.first->second+=3;
        }
        for (auto match : placeHolder){ // daca o echipa are 0pct per total, nu va fi introdusa in mapa cu pct. inseet nu returneaza nimic daca o key exista deja
            points.insert({placeHolder[0], 0});
            points.insert({placeHolder[3], 0});
        }
        placeHolder.clear();
    }

    std::vector<std::pair<std::string, int>> order(points.begin(), points.end());
    std::sort(order.begin(),order.end(), compare);
    for(int i=0; i!=order.size(); ++i){
        std::cout<<order[i].first<<" "<<order[i].second<<" "<<givenGoals[order[i].first]<<" "<<receivedGoals[order[i].first]<<std::endl;
    }
    return 0;
}
