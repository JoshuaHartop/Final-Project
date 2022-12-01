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

void Player::addItem(Item item) {
	if (item.getType() != "placeholder") {
		Inventory.push_back(item);
		std::cout << "\n" << item.getName() << " was added to your inventory!\n";
	}
	
}
void Player::Equip(std::string EquipChoice){
	auto it = std::find_if(Inventory.begin(), Inventory.end(), [&](Item& I) { return I.getName() == EquipChoice; }); // iterator finding the item
	int index = std::distance(Inventory.begin(), it); //Pointer to the position of "Equip Choice"
	if (it == Inventory.end()){
		std::cout << "\nYou goofy ah mf, equip something you own\n";
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
		std::cout << "\nYou goofy ah mf, equip something you own\n";
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