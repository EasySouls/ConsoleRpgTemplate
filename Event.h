//
// Created by retek on 2023. 09. 09..
//

#ifndef TEXTRPGGAME_EVENT_H
#define TEXTRPGGAME_EVENT_H


#include "Character.h"
#include "Enemy.h"
#include "dArray.h"

class Event {
private:
    int nrOfEvents;

public:
    Event();

    void generateEvent(Character &character, dArray<Enemy> &enemies);
    void enemyEncounter(Character &character, dArray<Enemy> &enemies);
    void puzzleEncounter(Character &character);
};


#endif //TEXTRPGGAME_EVENT_H
