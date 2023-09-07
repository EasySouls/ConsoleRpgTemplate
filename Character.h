#include <string>
#include <utility>
#include <iostream>
//
// Created by retek on 2023. 09. 07..
//

#ifndef TEXTRPGGAME_CHARACTER_H
#define TEXTRPGGAME_CHARACTER_H


class Character {
private:
    std::string name;
    int hp{};
    int maxHp;
    int level{};
    int speed;
    int armor;
    int accuracy;
    int damageMin;
    int damageMax;
    int luck;

    int distanceTraveled{};
    int gold{};
    int exp{};
    int expNext{};

    int strength{};
    int dexterity{};
    int constitution{};
    int intelligence{};
    int wisdom{};
    int charisma{};

    int statPoints{};
    int skillPoints{};

public:
    Character();
    Character(std::string name, int distanceTraveled, int gold, int level, int exp, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int hp, int statPoints, int skillPoints);

    void initialize(std::string name);
    void updateStats();
    void levelUp();
    [[nodiscard]] std::string getAsString() const;
    [[nodiscard]] std::string getAsString2() const;
    void addToStat(int stat, int value);
    void takeDamage(int damage);
    void heal(int value);
    void printStats() const;

    // Accessors
    [[nodiscard]] inline const int& getDistanceTraveled() const { return this->distanceTraveled; }
    [[nodiscard]] inline const std::string& getName() const { return this->name; }
    [[nodiscard]] inline const int& getLevel() const { return this->level; }
    [[nodiscard]] inline const int& getExp() const { return this->exp; }
    [[nodiscard]] inline const int& getExpNext() const { return this->expNext; }
    [[nodiscard]] inline const int& getHp() const { return this->hp; }
    [[nodiscard]] inline const int& getMaxHp() const { return this->maxHp; }
    [[nodiscard]] inline bool isAlive() const { return this->hp > 0; }
    [[nodiscard]] inline const int& getGold() const { return this->gold; }
    [[nodiscard]] inline const int& getSpeed() const { return this->speed; }
    [[nodiscard]] inline const int& getDamageMin() const { return this->damageMin; }
    [[nodiscard]] inline const int& getDamageMax() const { return this->damageMax; }
    [[nodiscard]] inline const int& getLuck() const { return this->luck; }
    [[nodiscard]] inline const int& getArmor() const { return this->armor; }
    [[nodiscard]] inline const int& getAccuracy() const { return this->accuracy; }
    [[nodiscard]] inline const int& getStatsPoints() const { return this->statPoints; }
    [[nodiscard]] inline const int& getSkillPoints() const { return this->skillPoints; }
    [[nodiscard]] inline const int& getStrenght() const { return this->strength; }
    [[nodiscard]] inline const int& getDexterity() const { return this->dexterity; }
    [[nodiscard]] inline const int& getConstitution() const { return this->constitution; }
    [[nodiscard]] inline const int& getIntelligence() const { return this->intelligence; }
    [[nodiscard]] inline const int& getWisdom() const { return this->wisdom; }
    [[nodiscard]] inline const int& getCharisma() const { return this->charisma; }
    [[nodiscard]] inline const int& getDamage() const { return rand() % this->damageMax + this->damageMin; }

    // Modifiers
    inline void setDistanceTraveled(const int& distance) { this->distanceTraveled = distance; }
    inline void travel() { this->distanceTraveled++; }
    inline void gainExp(const int& gainedExp) { this->exp += gainedExp; }
    inline void upgradeStrenght() { this->strength++; updateStats(); }
    inline void upgradeDexterity() { this->dexterity++; updateStats(); }
    inline void upgradeConstitution() { this->constitution++; updateStats(); }
    inline void upgradeIntelligence() { this->intelligence++; updateStats(); }
    inline void upgradeWisdom() { this->wisdom++; updateStats(); }
    inline void upgradeCharisma() { this->charisma++; updateStats(); }
    inline void addStatPoints(int num) { this->statPoints = this->statPoints + num; }
};


#endif //TEXTRPGGAME_CHARACTER_H
