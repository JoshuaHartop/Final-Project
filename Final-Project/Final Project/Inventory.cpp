#include "Player.h"
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
#include <algorithm>

void Player::addItem(Item item) {
	if (item.getType() != "placeholder") {
		Inventory.push_back(item);
		std::cout << "\n" << item.getName() << " was added to your inventory!\n";
	}
	
}
void Player::addItemM(Item item) {
	if (item.getType() != "placeholder") {
		mInventory.push_back(item);
	}
}

void Player::Equip(std::string EquipChoice){
	auto it = std::find_if(Inventory.begin(), Inventory.end(), [&](Item& I) { return I.getName() == EquipChoice; }); // iterator finding the item
	int index = std::distance(Inventory.begin(), it); //Pointer to the position of "Equip Choice"
	if (it == Inventory.end()){
		std::cout << "\nYou goofy ah, equip something you own\n";
	}
	else {
        if(Inventory[index].getType() == "Weapon" && WeaponE == true){
			std::cout << "\nUnequip your Weapon, before you try to equip another\n";
		}
		else if (Inventory[index].getType() == "Armor" && ArmorE == true) {
			std::cout << "\nUnequip your Armor, before you try to equip another\n";
		}
		//E2BIG
		else{
			if(Inventory[index].getType() == "Weapon"){
				WeaponE = true;
			}
			else{
				ArmorE = true;
			}
			statValue[0] += Inventory[index].getHP();
			statValue[1] += Inventory[index].getStr();
			statValue[2] += Inventory[index].getIntel();
			statValue[3] += Inventory[index].getDex();
			statValue[4] += Inventory[index].getAgi();
			std::cout << "\nYou have equipped your " << Inventory[index].getName() << " , its stats have been applied.\n\n";
			Equipped.push_back(Inventory[index]);
			Inventory.erase(Inventory.begin() + index);
		}
	}
}

void Player::unEquip(std::string unEquipChoice){
	auto it = std::find_if(Equipped.begin(), Equipped.end(), [&](Item& I) { return I.getName() == unEquipChoice; }); // iterator finding the item
	int index = std::distance(Equipped.begin(), it); //Pointer to the position of "Equip Choice"
    if (it == Equipped.end()){
		std::cout << "\nYou goofy ah, equip something you own\n";
	}
	else {
        if(Equipped[index].getType() == "Weapon" && WeaponE == false){
			std::cout << "\nEquip your Weapon, before you try to equip another\n";
		}
		else if (Equipped[index].getType() == "Armor" && ArmorE == false) {
			std::cout << "\nEquip your Armor, before you try to equip another\n";
		}
		//E2BIG

		else{
			if(Equipped[index].getType() == "Weapon"){
				WeaponE = false;
			}
			else{
				ArmorE = false;
			}
			statValue[0] -= Equipped[index].getHP();
			statValue[1] -= Equipped[index].getStr();
			statValue[2] -= Equipped[index].getIntel();
			statValue[3] -= Equipped[index].getDex();
			statValue[4] -= Equipped[index].getAgi();
			std::cout << "\nYou have Unequipped your " << Equipped[index].getName() << " , its stats have been removed.\n\n";
			Inventory.push_back(Equipped[index]);
			Equipped.erase(Equipped.begin() + index);
		}
	}
}
void Player::SellItems(std::string sellChoice) {
	auto it = std::find_if(Inventory.begin(), Inventory.end(), [&](Item& I) { return I.getName() == sellChoice; }); // iterator finding the item
	int index = std::distance(Inventory.begin(), it); //Pointer to the position of "sellChoice"
	int AddGold = Inventory[index].getMoney();
	if (it == Inventory.end()) {
		std::cout << "\nYou can only sell things you own.\n";
	}
	else {
		if (Inventory[index].getAmount() == 1) {
			std::cout << "Your " << Inventory[index].getName() << " has been sold you have recieved " << AddGold << " gold.";
			addGold(AddGold);
			Inventory.erase(Inventory.begin() + index);
		}
		else if (Inventory[index].getAmount() >= 2) {
			std::cout << "Your " << Inventory[index].getName() << " has been sold you have recieved " << AddGold << " coins.";
			addGold(AddGold);
			Inventory[index].takeAmount(1);
		}
	}
}
void Player::buyItems(std::string buyChoice) {
	auto it = std::find_if(mInventory.begin(), mInventory.end(), [&](Item& I) { return I.getName() == buyChoice; }); // iterator finding the item
	int index = std::distance(mInventory.begin(), it); //Pointer to the position of "sellChoice"
	if (it == mInventory.end()) {
		std::cout << "\nYou can only buy things on the menu.\n";
	}
	else {
		if (mInventory[index].getAmount() == 1 && getGold() >= mInventory[index].getMoney()) {
			minusGold(mInventory[index].getMoney());
			std::cout << "You have purchased " << mInventory[index].getName() << " ,it cost you " << mInventory[index].getMoney() << " coins.\n";
			Inventory.push_back(mInventory[index]);
			mInventory.erase(mInventory.begin() + index);
			}
		else if (mInventory[index].getAmount() >= 2 && getGold() >= mInventory[index].getMoney()) {
			minusGold(mInventory[index].getMoney());
			std::cout << "You have purchased " << mInventory[index].getName() << " ,it cost you " << mInventory[index].getMoney() << " coins.\n";
			mInventory[index].takeAmount(1);
			Inventory.push_back(mInventory[index]);
		}
		else {
			std::cout << "You don't have enough money.\n";
		}
	}
}