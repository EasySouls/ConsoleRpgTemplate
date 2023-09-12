//
// Created by retek on 2023. 09. 09..
//

#include "Event.h"

Event::Event() {
    this->nrOfEvents = 2;
}

void Event::generateEvent(Character &character, dArray<Enemy> &enemies) {

    int eventType = rand() % this->nrOfEvents;

    switch (eventType) {
        case 0:
            // Enemy encounter
            enemyEncounter(character, enemies);
            break;
        case 1:
            // Puzzle
            puzzleEncounter(character);
            break;
        default:
            printf("ERROR! Not a valid event type!");
            break;
    }
}

void Event::enemyEncounter(Character &character, dArray<Enemy> &enemies) {

}

void Event::puzzleEncounter(Character &character) {

}
