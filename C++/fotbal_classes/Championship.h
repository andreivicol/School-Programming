//
// Created by Andrei on 15-Jul-20.
//

#ifndef FOTBAL_CLASSES_CHAMPIONSHIP_H
#define FOTBAL_CLASSES_CHAMPIONSHIP_H
#include <map>
#include <vector>


class Championship {
public:
    virtual void setPoints(std::map<std::string, class Team>& map, class Team& team1, class Team& team2, std::string& name1, std::string& name2);
    virtual void orderTeams(std::vector<std::pair<std::string, class Team> >& vect, const std::map<std::string, Team>& map);
    Championship();
    ~Championship();
private:
protected:
};


#endif //FOTBAL_CLASSES_CHAMPIONSHIP_H
