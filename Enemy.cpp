//
// Created by retek on 2023. 09. 12..
//

#include <cstdlib>
#include <string>
#include "Enemy.h"

Enemy::Enemy(int level)
{
    this->level = level;
    this->hpMax = level * 10;
    this->hp = this->hpMax;
    this->damageMin = this->level * 2;
    this->damageMax = this->level * 3;
    this->dropChance = rand() % 100 + 1;
    this->defense = rand() % level*4 + 1;
    this->accuracy = rand() % level*4 + 1;
}

void Enemy::takeDamage(int damage)
{
    this->hp -= damage;

    if (this->hp <= 0)
    {
        this->hp = 0;
        //enemy dies
    }
}

std::string Enemy::getAsString() const
{
    return "Level: " + std::to_string(this->level) + "\n" + "Hp: " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax) + "\n" + "Damage: " + std::to_string(damageMin) + " - " + std::to_string(damageMax) + "\n" + "Defence: " + std::to_string(this->defense) + "\n" + "Accuracy: " + std::to_string(this->accuracy) + "\n" + "Drop chance: " + std::to_string(this->dropChance) + "\n";
}
