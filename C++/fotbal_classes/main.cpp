#include <iostream>
#include <vector>
#include <map>
#include "Championship.h"
#include "Team.h"

std::vector<std::pair<std::string, Team>> teamOrder;
std::map<std::string, Team> teamUnordered;

int teams, games;
std::string team1, team2, dash;

int main() {
    std::cin>>teams>>games;
    Team homeTeam, awayTeam;
    Championship champ;

    for ( int game=0; game!=games; ++game){
        std::cin>>team1>>homeTeam.goalsScored>>dash>>homeTeam.goalsTaken>>team2;
        awayTeam.goalsTaken=homeTeam.goalsScored;
        awayTeam.goalsScored=homeTeam.goalsTaken;

        champ.setPoints(teamUnordered, homeTeam, awayTeam, team1, team2);
        champ.orderTeams(teamOrder, teamUnordered);
    }

    for (const auto & team : teamOrder){
        std::cout<<team.first<<" "<<team.second.points<<" "<<team.second.goalsScored<<" "<<team.second.goalsTaken<<std::endl;
    }
    return 0;
}
