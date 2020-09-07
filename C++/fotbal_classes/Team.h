//
// Created by Andrei on 15-Jul-20.
//

#ifndef FOTBAL_CLASSES_TEAM_H
#define FOTBAL_CLASSES_TEAM_H

#include "Championship.h"
#include <string>

class Team : public Championship {
public:
    int points;
    int goalsScored;
    int goalsTaken;

    Team();
    ~Team();
private:
protected:
};


#endif //FOTBAL_CLASSES_TEAM_H
