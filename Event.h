//
// Created by retek on 2023. 09. 09..
//

#ifndef TEXTRPGGAME_EVENT_H
#define TEXTRPGGAME_EVENT_H


class Event {
private:
    int nrOfEvents;

public:
    Event();

    void generateEvent();
    void enemyEncounter();
    void puzzleEncounter();
};


#endif //TEXTRPGGAME_EVENT_H
