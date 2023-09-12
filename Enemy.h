//
// Created by retek on 2023. 09. 12..
//

#ifndef TEXTRPGGAME_ENEMY_H
#define TEXTRPGGAME_ENEMY_H


class Enemy {
    int level;
    int hp;
    int hpMax;
    int damageMin;
    int damageMax;
    float dropChance;
    int defense;
    int accuracy;

public:
    explicit Enemy(int level = 1);

    inline bool isAlive() { return this->hp > 0; }

    [[nodiscard]]
    std::string getAsString() const;

    void takeDamage(int damage);

    [[nodiscard]] inline int getDamage() const { return rand() % this->damageMax + this->damageMin; };
    [[nodiscard]] inline int getExp() const { return this->level * 100; }
    [[nodiscard]] inline int getHp() const { return this->hp; }
    [[nodiscard]] inline int getHpMax() const { return this->hpMax; }
    [[nodiscard]] inline int getLevel() const { return this->level; }
    [[nodiscard]] inline int getDefense() const { return this->defense; }
    [[nodiscard]] inline int getAccuracy() const { return this->accuracy; }
};


#endif //TEXTRPGGAME_ENEMY_H
