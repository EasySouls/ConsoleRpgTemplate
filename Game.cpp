//
// Created by retek on 2023. 09. 07..
//

#include <fstream>
#include <sstream>
#include "Game.h"
#include "Event.h"

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

    if (characters[activeCharacter].isAlive()) {
        std::cout << "= MAIN MENU =" << std::endl << std::endl;
        std::cout << "Active character: " << this->characters[activeCharacter].getName() << " "
                  << this->activeCharacter + 1 << " / " << this->characters.size() << "\n" << std::endl;
        if (this->characters[activeCharacter].getExp() >= this->characters[activeCharacter].getExpNext()) {
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

        while (std::cin.fail()) {
            std::cout << "Wrong input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');

            std::cout << std::endl << "Choice :";
            std::cin >> this->choice;
        }

        /*std::cin.ignore(100, '\n');
        std::cout << std::endl;*/

        switch (this->choice) {
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
    } else {
        std::cout << "YOU ARE DEAD!\n" << std::endl;
        std::cout << "Press [1] to load a previous character or press [0] to quit" << std::endl;
        std::cin >> this->choice;

        while (std::cin.fail() || this->choice < 0 || this->choice > 1) {
            std::cout << "Even after death, you do not care enough to avoid your mistakes." << std::endl;
            std::cout << "Your options were [1] and [0]" << std::endl;
            std::cin >> this->choice;
            std::cout << std::endl;
        }

        if (this->choice == 1) {
            loadCharacters();
            selectCharacter();
        } else {
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

    for (const auto &character: this->characters) {
        if (name == character.getName()) {
            std::cout << "This name is already taken. Please choose a different name." << std::endl;
            std::getline(std::cin, name); // Allow the user to enter a new name
            std::cout << "\n" << std::endl;
        }
    }

    characters.push_back(Character());
    activeCharacter = (int) characters.size() - 1;
    characters[activeCharacter].initialize(name);
}

void Game::levelUpCharacter() {
    Character character = this->characters[activeCharacter];
    character.levelUp();
    int unspentStatPoints = character.getStatsPoints();
    int unspentSkillPoints = character.getSkillPoints();

    if (unspentStatPoints > 0) {
        std::cout << "\nYou have " << unspentStatPoints << " unspent stat points." << std::endl;
        std::cout << "\nStats to upgrade: " << std::endl;
        std::cout << "[1] Strength -- " << character.getStrenght() << std::endl;
        std::cout << "[2] Dexterity -- " << character.getDexterity() << std::endl;
        std::cout << "[3] Constitution -- " << character.getConstitution() << std::endl;
        std::cout << "[4] Intelligence -- " << character.getIntelligence() << std::endl;
        std::cout << "[5] Wisdom -- " << character.getWisdom() << std::endl;
        std::cout << "[6] Charisma -- " << character.getCharisma() << std::endl;

        std::cout << "Your choice: " << std::endl;
        std::cin >> this->choice;
        std::cout << std::endl;

        while (std::cin.fail() || this->choice < 1 || this->choice > 6) {
            std::cout << "Wrong input!" << std::endl;
            std::cin.clear();
            std::cout << "Your choice: ";
            std::cin >> this->choice;
            std::cout << std::endl;
        }

        switch (this->choice) {
            case 1:
                character.upgradeStrenght();
                character.addStatPoints(-1);
                std::cout << "Strength upgraded!" << std::endl;
                break;
            case 2:
                character.upgradeDexterity();
                character.addStatPoints(-1);
                std::cout << "Dexterity upgraded!" << std::endl;
                break;
            case 3:
                character.upgradeConstitution();
                character.addStatPoints(-1);
                std::cout << "Constitution upgraded!" << std::endl;
                break;
            case 4:
                character.upgradeIntelligence();
                character.addStatPoints(-1);
                std::cout << "Intelligence upgraded!" << std::endl;
                break;
            case 5:
                character.upgradeWisdom();
                character.addStatPoints(-1);
                std::cout << "Wisdom upgraded!" << std::endl;
                break;
            case 6:
                character.upgradeCharisma();
                character.addStatPoints(-1);
                std::cout << "Charisma upgraded!" << std::endl;
                break;
            default:
                std::cout << "Wrong input. Error handling gone wrong." << std::endl;
        }

        character.updateStats();
    } else std::cout << "You have no unspent stat points!" << std::endl;
}

void Game::saveCharacters() {
    std::ofstream outFile(this->fileName);

    if (outFile.is_open()) {
        for (const auto &character: characters) {
            outFile << character.getAsString() << std::endl;
        }
    }
    outFile.close();

    std::cout << this->characters[activeCharacter].getName() << " is saved!" << std::endl;
}

void Game::loadCharacters() {
    std::ifstream inFile(this->fileName);

    std::string name;
    int distanceTraveled, gold, level, exp, strength, dexterity, constitution, intelligence, wisdom, charisma, hp, statPoints, skillPoints;
    std::string line;
    std::stringstream str;

    if (inFile.is_open()) {
        while (std::getline(inFile, line)) {
            str.str(line);
            str >> name;
            str >> distanceTraveled;
            str >> gold;
            str >> level;
            str >> exp;
            str >> strength;
            str >> dexterity;
            str >> constitution;
            str >> intelligence;
            str >> wisdom;
            str >> charisma;
            str >> hp;
            str >> statPoints;
            str >> skillPoints;

            Character temp(name, distanceTraveled, gold, level, exp, strength, dexterity, constitution, intelligence, wisdom, charisma, hp, statPoints, skillPoints);

            this->characters.push_back(temp);
            std::cout << "Character " << name << " loaded!" << std::endl;
            str.clear();
        }
    }
    inFile.close();

    if (this->characters.empty()) {
        throw "ERROR! NO CHARACTERS LOADED OR EMPTY FILE!";
    }
}

void Game::selectCharacter() {
    std::cout << "\nSelect character: " << std::endl;

    for (size_t i = 0; i < this->characters.size(); i++) {
        std::cout << "[" << i << "] " << this->characters[i].getName() << "(lvl " << this->characters[i].getLevel() << ")" << std::endl;
    }

    std::cout << "Choice: ";
    std::cin >> this->choice;

    while (std::cin.fail() || this->choice >= this->characters.size() || this->choice < 0)
    {
        std::cout << "Wrong input!" << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');

        std::cout << "Select character: ";
        std::cin >> this->choice;
    }

    this->activeCharacter = this->choice;
    std::cout << this->characters[activeCharacter].getName() << " is selected." << std::endl;
}

void Game::travel() {
    this->characters[activeCharacter].travel();

    auto *event = new Event();
    event->generateEvent(characters[activeCharacter], enemies);
    this->canRest = true;
}

void Game::rest() {
    if (canRest)
    {
        if (this->characters[activeCharacter].getMaxHp() == this->characters[activeCharacter].getHp())
        {
            std::cout << "You are already at max hp.\n" << std::endl;
        }
        else
        {
            std::cout << "You take a rest under a nearby tree and regain some of you hp" << std::endl;
            int level = characters[activeCharacter].getLevel();
            characters[activeCharacter].heal(level * 10);
            canRest = false;
            std::cout << "You healed for" << level * 10 << " points" << std::endl;
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "You have already taken a rest this day" << std::endl;
        std::cout << "Only after traveling will you be able to rest again" << std::endl;
        std::cout << std::endl;
    }
}
