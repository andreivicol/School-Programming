//
// Created by Andrei on 15-Jul-20.
//

#include "Championship.h"
#include "Team.h"

Championship::Championship() {}
Championship::~Championship() {}

void Championship::setPoints(std::map<std::string, class Team>& map, class Team& team1, class Team& team2, std::string& name1, std::string& name2){
    map.insert({name1, team1});
    map.insert({name2, team2});

    if (team1.goalsTaken > team1.goalsScored){
        map[name2].points+=3;
    }else if (team1.goalsScored == team1.goalsTaken){
        map[name2].points+=1;
        map[name1].points+=1;
    } else{
        map[name1].points+=3;
    }
}

void Championship::orderTeams(std::vector<std::pair<std::string, Team>> &vect, const std::map<std::string, Team>& map) {
    for (auto const& entry : map)
    {
        if (vect.empty()) { //check if vector is empty and add the first pair
            vect.push_back(std::make_pair(entry.first, entry.second));
            continue;
        }

        bool added = false;
        for (auto pos = vect.begin(); pos != vect.end(); ++pos) {
            if(entry.second.points > pos->second.points){
                vect.insert(pos, std::make_pair(entry.first, entry.second));
                added = true;
                break;
            }
        }
        if (!added){
            vect.push_back(std::make_pair(entry.first, entry.second));
        }
    }
}