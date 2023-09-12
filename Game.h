#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Character.h"
#include "Enemy.h"
#include "dArray.h"
//
// Created by retek on 2023. 09. 07..
//

#ifndef TEXTRPGGAME_GAME_H
#define TEXTRPGGAME_GAME_H

class Game {
private:
    int choice;
    bool isRunning;
    bool canRest;

    // Character related
    int activeCharacter;
    std::vector <Character> characters;
    std::string fileName;

    // Enemies
    dArray<Enemy> enemies;

public:
    Game();

    // Functions

    void initGame();
    void mainMenu();
    void createNewCharacter();
    void levelUpCharacter();
    void saveCharacters();
    void loadCharacters();
    void selectCharacter();
    void travel();
    void rest();

    // Accessors
    [[nodiscard]] inline bool getIsRunning() const { return this->isRunning; }
};


#endif //TEXTRPGGAME_GAME_H
