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
#include "Item.h"

int Enemy::getLevel() {
    return eLevel;
}

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

Item Enemy::dropItem(Enemy enemy) {
#pragma region Droppable Items
    //tier 1 items
    Item birchBow("BIRCH BOW", "Common", "Weapon", 15, 1, 0, 0, 0, 0, 1);
    Item rustySword("RUSTY SWORD", "Common", "Weapon", 15, 1, 0, 1, 0, 0, 0); // creates an item
    Item warpedStaff("WARPED STAFF", "Common", "Weapon", 15, 1, 0, 0, 1, 0, 0);
    //tier 2 items
    Item mapleBow("MAPLE BOW", "Uncommon", "Weapon", 50, 1, 0, 0, 0, 0, 10);
	Item copperSword("COPPER SWORD", "Uncommon", "Weapon", 50, 1, 0, 10, 0, 0, 0);
	Item fireStaff("FIRE STAFF", "Uncommon", "Weapon", 50, 1, 0, 0, 10, 0, 0);
    //tier 3
    Item eucalyptusBow("EUCALYPTUS BOW", "Epic", "Weapon", 150, 1, 0, 0, 0, 0, 45);
	Item tungstenSword("TUNGSTEN SWORD", "Epic", "Weapon", 150, 1, 0, 45, 0, 0, 0);
	Item electricStaff("ELECTRIC STAFF", "Epic", "Weapon", 150, 1, 0, 0, 45, 0, 0);
    //Boss Gear
    Item bloodwoodBow("BLOODWOOD BOW", "LEGENDARY", "Weapon", 1000, 1, 0, 0, 0, 0, 100);
	Item hellflameSword("HELLFLAME SWORD", "LEGENDARY", "Weapon", 1000, 1, 0, 100, 0, 0, 0);
	Item kingsStaff("KINGS STAFF", "LEGENDARY", "Weapon", 1000, 1, 0, 0, 100, 0, 0);
    Item crownOfLies("CROWN OF LIES", "MYTHIC", "Armor", 3500, 1, 150, 150, 150, 150, 150);
    //placeholder
    Item g("", "", "placeholder", 0, 0, 0, 0, 0, 0, 0);
    
#pragma endregion
    int randomDrop;
    int itemSelect;
    randomDrop = std::rand() % (100 + 1);
    itemSelect = std::rand() % (3) + 1;
    
    //randomly select item based on level of mob
    if (enemy.getLevel() < 5) {
        std::cout << randomDrop << " <- random drop " << itemSelect << " <- Item select\n";
        if (randomDrop >= 60 && randomDrop <= 85) {
            std::cout << "The " << enemyName << " Dropped a ";
            if (itemSelect == 1) {
                return rustySword;
            }
            else if (itemSelect == 2) {
                return birchBow;
            }
            else if (itemSelect == 3) {
                return warpedStaff;
            }
            
        }
        else {
            return g;
        }
    }

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

