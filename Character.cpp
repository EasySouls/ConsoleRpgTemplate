//
// Created by retek on 2023. 09. 07..
//

#include "Character.h"

Character::Character() {
    name = "";
    hp = 0;
    maxHp = 0;
    speed = 0;
    armor = 0;
    accuracy = 0;
    damageMin = 0;
    damageMax = 0;
    luck = 0;

    distanceTraveled = 0;
    level = 0;
    gold = 0;
    exp = 0;
    expNext = 0;

    strength = 0;
    dexterity = 0;
    constitution = 0;
    intelligence = 0;
    wisdom = 0;
    charisma = 0;

    statPoints = 0;
    skillPoints = 0;
}

Character::Character(std::string name, int distanceTraveled, int gold, int level, int exp, int strength, int dexterity,
                     int constitution, int intelligence, int wisdom, int charisma, int hp, int statPoints,
                     int skillPoints) {
    name = name;
    hp = hp;
    maxHp = 0;
    speed = 0;
    armor = 0;
    accuracy = 0;
    damageMin = 0;
    damageMax = 0;
    luck = 0;

    distanceTraveled = distanceTraveled;
    level = level;
    gold = gold;
    exp = exp;
    expNext = 0;

    strength = strength;
    dexterity = dexterity;
    constitution = constitution;
    intelligence = intelligence;
    wisdom = wisdom;
    charisma = charisma;

    statPoints = statPoints;
    skillPoints = skillPoints;
}

void Character::initialize(std::string charName) {

    this->distanceTraveled = 0;

    this->gold = 100;

    this->name = std::move(charName);
    this->level = 1;
    this->exp = 0;
    this->expNext = 100;

    this->strength = 5;
    this->dexterity = 5;
    this->constitution = 5;
    this->intelligence = 5;
    this->wisdom = 5;
    this->charisma = 5;

    this->maxHp = (this->constitution * 2) + (this->strength / 2) + (this->level * 10);
    this->hp = maxHp;
    this->damageMin = this->strength;
    this->damageMax = this->strength + (this->level * 2);
    this->armor = this->dexterity + (this->intelligence / 2);
    this->accuracy = (this->dexterity / 2) + intelligence;
    this->luck = this->intelligence;

    this->statPoints = 0;
    this->skillPoints = 0;
}

void Character::updateStats() {
    this->maxHp = (this->constitution * 2) + (this->strength / 2) + (this->level * 10);
    this->damageMin = this->strength;
    this->damageMax = this->strength + (this->level * 2);
    this->armor = this->dexterity + (this->intelligence / 2);
    this->accuracy = (this->dexterity / 2) + intelligence;
    this->luck = this->intelligence;
    this->speed = 2 * dexterity - constitution;
}

void Character::levelUp() {
    if (exp >= expNext) {
        this->exp -= expNext;
        level++;
        this->expNext = (expNext * 2) + (level * 100);

        this->statPoints++;
        this->skillPoints++;

        this->updateStats();

        std::cout << "You are now level " << this->level << ".\n" << std::endl;
    } else {
        std::cout << "Not enough exp to level up.\n" << std::endl;
    }
}

std::string Character::getAsString() const {
    return name + " " + std::to_string(distanceTraveled) + " " + std::to_string(gold) + " " + std::to_string(level) +
           " " + std::to_string(exp) + " " + std::to_string(strength) + " " + std::to_string(dexterity) + " " +
           std::to_string(constitution) + " " + std::to_string(intelligence) + " " + std::to_string(wisdom) + " " +
           std::to_string(charisma) + " " + std::to_string(hp) + " " + std::to_string(statPoints) + " " +
           std::to_string(skillPoints);
}

std::string Character::getAsString2() const {
    throw "Not yet implemented";
}

void Character::addToStat(int stat, int value) {
    switch (stat) {
        case 1: //STR
            this->strength += value;
            updateStats();
            std::cout << "Your strength has leveled up by " << value << std::endl;
            break;
        case 2: //DEX
            this->dexterity += value;
            updateStats();
            std::cout << "Your dexterity has leveled up by " << value << std::endl;
            break;
        case 3: //CON
            this->constitution += value;
            updateStats();
            std::cout << "Your constitution has leveled up by " << value << std::endl;
            break;
        case 4: //INT
            this->intelligence += value;
            updateStats();
            std::cout << "Your intelligence has leveled up by " << value << std::endl;
            break;
        case 5: //WIS
            this->wisdom += value;
            updateStats();
            std::cout << "Your wisdom has leveled up by " << value << std::endl;
            break;
        case 6: //CHA
            this->charisma += value;
            updateStats();
            std::cout << "Your charisma has leveled up by " << value << std::endl;
            break;
        default:
            std::cout << "No such stat!\n" << std::endl;
            break;
    }
}

void Character::takeDamage(int damage) {
    this->hp -= damage;
}

void Character::heal(int value) {
    this->hp += value;
    if (this->hp > maxHp) this->hp = this->maxHp;
}

void Character::printStats() const {
    std::cout << "-- Character sheet --\n" << std::endl;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Level: " << this->level << std::endl;
    std::cout << std::endl;
    std::cout << "Gold: " << this->gold << std::endl;
    std::cout << "Distance traveled: " << this->distanceTraveled << std::endl;
    std::cout << std::endl;
    std::cout << "Exp: " << this->exp << std::endl;
    std::cout << "Exp to next level: " << this->expNext << std::endl;
    std::cout << std::endl;
    std::cout << "Strength: " << this->strength << std::endl;
    std::cout << "Dexterity: " << this->dexterity << std::endl;
    std::cout << "Constitution: " << this->constitution << std::endl;
    std::cout << "Intelligence: " << this->intelligence << std::endl;
    std::cout << "Wisdom: " << this->wisdom << std::endl;
    std::cout << "Charisma: " << this->charisma << std::endl;
    std::cout << std::endl;
    std::cout << "HP: " << this->hp << " / " << this->maxHp << std::endl;
    std::cout << "Damage: " << this->damageMin << " - " << this->damageMax << std::endl;
    std::cout << "Armor: " << this->armor << std::endl;
    std::cout << "Accuracy " << this->accuracy << std::endl;
    std::cout << "Luck: " << this->luck << std::endl;
    std::cout << std::endl;
    std::cout << "Stat points: " << this->statPoints << std::endl;
    std::cout << "Skill points: " << this->skillPoints << std::endl;
    std::cout << std::endl;
}


