//
// Created by retek on 2023. 09. 07..
//

#include "Game.h"

Game::Game() {
    choice = 0;
    canRest = false;
    isRunning = true;
    activeCharacter = 0;
    fileName = "characters.txt";
}

void Game::initGame() {
    createNewCharacter();
}

void Game::mainMenu() {
    std::cout << "ENTER to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    /*system("CLS");*/

    if (characters[activeCharacter].isAlive())
    {
        std::cout << "= MAIN MENU =" << std::endl << std::endl;
        std::cout << "Active character: " << this->characters[activeCharacter].getName() << " " << this->activeCharacter+1 << " / " << this->characters.size() << "\n" << std::endl;
        if (this->characters[activeCharacter].getExp() >= this->characters[activeCharacter].getExpNext())
        {
            std::cout << "Level up available!\n" << std::endl;
        }
        std::cout << "[0]: Quit" << std::endl;
        std::cout << "[1]: Travel" << std::endl;
        std::cout << "[2]: Shop" << std::endl;
        std::cout << "[3]: Level up" << std::endl;
        std::cout << "[4]: Rest" << std::endl;
        std::cout << "[5]: Character sheet" << std::endl;
        std::cout << "[6]: Create new character" << std::endl;
        std::cout << "[7]: Save characters" << std::endl;
        std::cout << "[8]: Load characters" << std::endl;
        std::cout << "[9]: Select character" << std::endl;
        std::cout << std::endl;

        std::cout << "Choice: ";
        std::cin >> this->choice;
        std::cout << std::endl;

        while (std::cin.fail())
        {
            std::cout << "Wrong input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');

            std::cout << std::endl << "Choice :";
            std::cin >> this->choice;
        }

        /*std::cin.ignore(100, '\n');
        std::cout << std::endl;*/

        switch (this->choice)
        {
            case 0: //QUIT
                isRunning = false;
                break;

            case 1: //TRAVEL
                travel();
                break;

            case 2: //SHOP
                break;

            case 3: //LEVEL UP
                levelUpCharacter();
                break;

            case 4: //REST
                rest();
                break;

            case 5: //CHARACTER SHEET
                characters[activeCharacter].printStats();
                break;

            case 6: //CREATE NEW CHARACTER
                std::cin.ignore();
                createNewCharacter();
                saveCharacters();
                break;

            case 7: //SAVE CHARACTER
                saveCharacters();
                break;

            case 8: //LOAD CHARACTERS
                loadCharacters();
                break;

            case 9: //SELECT CHARACTER
                selectCharacter();
                break;
            default:
                break;
        }
    }
    else
    {
        std::cout << "YOU ARE DEAD!\n" << std::endl;
        std::cout << "Press [1] to load a previous character or press [0] to quit" << std::endl;
        std::cin >> this->choice;

        while (std::cin.fail() || this->choice < 0 || this->choice > 1)
        {
            std::cout << "Even after death, you do not care enough to avoid your mistakes." << std::endl;
            std::cout << "Your options were [1] and [0]" << std::endl;
            std::cin >> this->choice;
            std::cout << std::endl;
        }

        if (this->choice == 1)
        {
            loadCharacters();
            selectCharacter();
        }
        else
        {
            std::cout << "You have failed to live up to the expectations, adventurer.\n" << std::endl;
            isRunning = false;
        }
    }

}

void Game::createNewCharacter() {
    std::string name;
    std::cout << "Enter the name of your character: ";
    std::getline(std::cin, name);
    std::cout << "\n" << std::endl;

    for (const auto & character : this->characters) {
        while (name == character.getName());
    }
}

void Game::levelUpCharacter() {

}

void Game::saveCharacters() {

}

void Game::loadCharacters() {

}

void Game::selectCharacter() {

}

void Game::travel() {

}

void Game::rest() {

}
