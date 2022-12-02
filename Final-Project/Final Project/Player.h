#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include "Item.h"


class Player {

public:

    // public variables
    bool isAlive = false; // checks if the player has died
    int shopVisits;
    ~Player() {}
    //public functions
    int getXP(); // gets the players amount of xp
    int getGold(); // gets the players amount of gold
    void addGold(int goldGiven); // adds gold
    void addXP(int xpGiven); // adds xp
    void gameStart(); // initializes players stats
    void setName();// gets the players name  
    std::string playerName(); // sets the players name
    void Die();// player dies
    double pDamage(); // player damage
    void takeDamage(double dmg); // player takes damage
    void onLevel(); // levels the character
    void displayInventory();// checks users inventory and displays gold
    void displayStats(); // displays users stats
    void displayStatPointPage();
    int getStatPoints();
    bool minusGold(int goldSubtracted);
    void rest();
    void addStatPoint(int stat);

    //player class stuff
    std::string getClass();

    
    //inventory functions
    void Equip(std::string EquipChoice);
    void unEquip(std::string item);
    void addItem(Item item);


    //character creator
    void pCreateChar();
    void pStatSet();
    void pClassSet();
    void pRaceSet();
private:
    //private variables
    //player variables
    int playerGold; // players gold
    std::string pName; // players name

    int pXP; // players current xp
    int pRequiredXP; // players xp required to level up
    int pLevel; // players current level
    int pArmor; // players current armor
    int damage; // players current damage

    //player stats
    std::string pStats[5]{
        "Constitution", // affects hp
        "Strength", // affects melee dmg
        "Intelligence", // affects spell dmg
        "Dexterity", // affects crit chance
        "Agility", // affects ranged dmg


    };
    int statPoints;
    int statValue[5]{ 1, 1 ,1 ,1 ,1 }; // first is constitution, second is strength, third is intelligence, fourth is Dexterity, fifth is Agility
    double pHealth; // players current hp
    int pMaxHealth; // players max hp

    //class select stuff
    std::string pClassSelect[3]{
     "Warrior",
     "Mage",
     "Archer"
    };
    std::string pClass;
  
    //race selection
    std::string pRaceSelect[5]{
        "Human",
        "Elf",
        "Dwarf",
        "Gnome",
        "Orc",
    };
    std::string pRace;

    //equipment/inventory
    std::vector<Item> Inventory;
    std::vector<Item> Equipped;
	bool WeaponE = false;
	bool ArmorE = false;
};

//work on char creation