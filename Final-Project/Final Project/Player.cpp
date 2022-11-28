#include "Player.h"
#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>


void Player::rest() {
    pHealth = pMaxHealth;
}

int Player::getXP() {
    return pXP;
}

int Player::getGold() {
    return playerGold;
}

void Player::addGold(int goldGiven) {
    playerGold += goldGiven;
}

bool Player::minusGold(int goldSubtracted) {
    if (playerGold >= goldSubtracted) {
        playerGold -= goldSubtracted;
        return true;
    }
    else {
        return false;
    }

}

void Player::addXP(int xpGiven) {
    pXP += xpGiven;
}

void Player::gameStart() {
    isAlive = true;
    pStrength = 100;
    pHealth = 100;
    pMaxHealth = 100;
    pXP = 0;
    pLevel = 1;
    pRequiredXP = (100 * pLevel) * 1.5;
    pArmor = 0;
    playerGold = 0;

}

void Player::setName() { // sets the players name
    std::cin >> pName;
}

std::string Player::playerName() {
    return pName;
}

void Player::Die() {
    isAlive = false;
    std::cout << "You Died! Game over!\n";

}

double Player::pDamage() {
    double randDamage = std::rand() % (115 + 1 - 85) + 85;
    randDamage = (randDamage / 100);
    double damage = randDamage * pStrength;
    return damage;
}

void Player::takeDamage(double dmg) {
    pHealth -= dmg;
    std::cout << "You were hit for " << dmg << "\n";
    std::cout << "You have " << pHealth << " / " << pMaxHealth << " left\n";
    if (pHealth <= 0) {
        Die();

    }
    else {

    }

}

void Player::onLevel() { // levels up the player
    while (pXP >= pRequiredXP) {
        pXP -= pRequiredXP;
        pLevel += 1;
        pRequiredXP = 100 * pLevel * 1.5;
        std::cout << "Congrats you've reached level " << pLevel << "\n"
            << "Your Health has been fully restored.\n"
            << "And you have been given 3 Attribute Points!\n";
    };
}

void Player::displayInventory() {
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
              << "Gold: " << playerGold << "\n";
    std::cout << std::left << "Name" << std::setw(11) << " Rarity" << std::setw(9) << " Description" << std::setw(50) << " Price" << std::setw(5) << " Quantity" << std::setw(2) << " Stats\n";
    for (int i = 0; i < Inventory.size(); i++) {
        std::cout << Inventory[i].displayItem() << "\n";
    }

    
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void Player::displayStats() // displays users stats
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
        << "Displaying stats for: " << pName << "\n\n"
        << "Level: " << pLevel << "\n"
        << "XP: " << pXP << "/" << pRequiredXP << "\n"
        << "Strength: " << pStrength << "\n"
        << "HP: " << pHealth << "/" << pMaxHealth << "\n"
        << "Armor: " << pArmor << "\n"
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}