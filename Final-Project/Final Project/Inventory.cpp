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
	Inventory.push_back(item);
	std::cout <<"\n" << item.displayItem() << " was added to your inventory!\n";
}
//DOESNT WORK, ERROR CODE C2371, it REDEFINITION, DIFFERENT BASIC TYPES
/*void Player::Equip(std::string EquipChoice) {
	auto it = std::find_if(Inventory.begin(), Inventory.end(), [&](Item& I) { return I.getName() == EquipChoice; }); // iterator finding the item
	auto it = std::find_if(Inventory.begin(), Inventory.end(), [&](Item& I) { return I.getType() == "1 Handed"; }); // iterator finding the item
	int index = std::distance(Inventory.begin(), it); //Pointer to the position of "Equip Choice"
}*/


void unEquip(std::string item);