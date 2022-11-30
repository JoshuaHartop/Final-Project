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
#include "Item.h"


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
    pMaxHealth = 100 + (statValue[0] * 3);
    pHealth = pMaxHealth;
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
    double damage = randDamage * statValue[1];
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
    std::cout << "Name ||" << " Rarity ||" << " Description ||" << " Price ||" << " Quantity ||" << " Item Stats\n";
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
        << "Constitution: " << statValue[0] << "\n"
        << "Strength: " << statValue[1] << "\n"
        << "Intelligence: " << statValue[2] << "\n"
        << "Dexterity: " << statValue[3] << "\n"
        << "Agility: " << statValue[4] << "\n"
        << "HP: " << pHealth << "/" << pMaxHealth << "\n"
        << "Crit chance: " << (0 + statValue[3]) << "%\n"
        << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
//Player creator stuff

void Player::pCreateChar() {
    pClassSet();
    pRaceSet();
    pStatSet();
}

void Player::pStatSet() {
        int statBonus = 2;
        if (pClass == "Warrior") {
            Player::statValue[1] += statBonus;
            Player::statValue[0] += statBonus;
        }
        else if (pClass == "Archer") {
            Player::statValue[4] += statBonus;
            Player::statValue[3] += statBonus;
        }
        else if (pClass == "Mage") {
            Player::statValue[3] += statBonus;
            Player::statValue[2] += statBonus;
        }
        else {
            std::cout << "\nCould not retrieve stats, invalid Class\n";
        }

        if (pRace == "Human") {
            Player::statValue[0] += statBonus;
            Player::statValue[1] += statBonus;
        }
        else if (pRace == "Elf") {
            Player::statValue[4] += statBonus;
            Player::statValue[3] += statBonus;
        }
        else if (pRace == "Dwarf") {
            Player::statValue[0] += statBonus;
            Player::statValue[3] += statBonus;
        }
        else if (pRace == "Gnome") {
            Player::statValue[3] += statBonus;
            Player::statValue[2] += statBonus;
        }
        else if (pRace == "Orc") {
            Player::statValue[0] += statBonus;
            Player::statValue[1] += statBonus;
        }
        else {
            std::cout << "\nCould not retrieve stats, invalid Race\n";
        }
}

void Player::pClassSet() {
    bool hasClass = false;
    int choice;
    do {
        std::cout << "Which class would you like to pick? \n";
        for (int i = 0; i < 3; i++) {
            std::cout << "[" << i + 1 << "]" << " " << pClassSelect[i] << "\n";
        }
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); std::cin.ignore(512, '\n');
        }
        switch (choice)
        {
        case 1:
            pClass = pClassSelect[choice - 1];
            std::cout << "Ah yes the " << pClass << " a good choice\n";
            hasClass = true;
            break;
        case 2:
            pClass = pClassSelect[choice - 1];
            std::cout << "Ah yes the " << pClass << " a good choice\n";
            hasClass = true;
            break;
        case 3:
            pClass = pClassSelect[choice - 1];
            std::cout << "Ah yes the " << pClass << " a good choice\n";
            hasClass = true;
            break;
        default:
            std::cout << "Please enter a valid option.\n";
            break;
        }
    } while (hasClass = false);
}

void Player::pRaceSet() {
    std::cout << "What is your Race? \n";
    int choice;
    for (int i = 0; i < 5; i++) {
        std::cout << "[" << i + 1 << "]" << " " << pRaceSelect[i] << "\n";
    }
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        pRace = pRaceSelect[choice - 1];
        std::cout << "Ah yes the " << pRace << " a good choice\n";
        break;
    case 2:
        pRace = pRaceSelect[choice - 1];
        std::cout << "Ah yes the " << pRace << " a good choice\n";
        break;
    case 3:
        pRace = pRaceSelect[choice - 1];
        std::cout << "Ah yes the " << pRace << " a good choice\n";
        break;
    case 4:
        pRace = pRaceSelect[choice - 1];
        std::cout << "Ah yes the " << pRace << " a good choice\n";
        break;
    case 5:
        pRace = pRaceSelect[choice - 1];
        std::cout << "Ah yes the " << pRace << " a good choice\n";
        break;

    default:
        std::cout << "Please enter a valid option.\n";
        break;
    }
}