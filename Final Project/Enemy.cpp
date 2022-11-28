#pragma once
#include "Enemy.h"
#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
#include <sstream>

void Enemy::takeDamage(double dmg) {
    eHealth -= dmg;
    std::cout << "You hit the " << enemyName << " for " << dmg << "\n";
    std::cout << "The " << enemyName << " has " << eHealth << " / " << eMaxHealth << " left\n";
    if (eHealth <= 0) {
        isAlive = false;
    }
}

void  Enemy::Die() {
    std::cout << "The " << enemyName << " has been slain!\n";
}

int  Enemy::dropGold() {
    goldDrop = 5 * eLevel;
    return goldDrop;

}

int  Enemy::dropXP() {
    xpGiven = eLevel * 20;
    return xpGiven;
}

void  Enemy::spawnEnemy() {
    std::cout << "A Level " << eLevel << " " << enemyName << " has spawned!\n";
    isAlive = true;
}
double  Enemy::mobStrength() {
    double randDamage = std::rand() % (115 + 1 - 85) + 85;
    randDamage = (randDamage / 100);
    double damage = randDamage * eStrength;
    return damage;
}

void Enemy::enemy(std::string Name, int hp, int maxHp, int level, int strength) {
    enemyName = Name;
    eHealth = hp;
    eMaxHealth = maxHp;
    eLevel = level;
    eStrength = strength;

}

