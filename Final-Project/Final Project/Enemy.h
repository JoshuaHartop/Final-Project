#pragma once
#include <iostream>
#include "Item.h"
class Enemy {

public:

    bool isAlive = false;
    void enemy(std::string Name, int hp, int maxHp, int level, int strength);
    void takeDamage(double dmg);
    void Die();
    int dropGold();
    int dropXP();
    void spawnEnemy();
    double mobStrength();
    Item dropItem();
    int getLevel();

private:
    std::string enemyName;
    int xpGiven;
    int goldDrop;
    double eStrength = 5;
    double eHealth = 100;
    int eMaxHealth = 100;
    int eLevel = 1;
    int damage = 0;
};