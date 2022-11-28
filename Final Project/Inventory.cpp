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


/*void Player::Equip(Item item, Player player) {
	std::transform(item.begin(), item.end(), item.begin(), ::toupper);
	auto it = find(Items.begin(), Items.end(), item);
	if (it != Items.end()) {
		int index = it - Items.begin();
		std::string ItemE = Items[index];
		int ItemPriceE = ItemPrice[index];
		std::string RarityE = Rarity[index];
		int QuantityE = Quantity[index];
		std::string ItemTypeE = ItemType[index];

		if (player.Quantity[index] >= 2 && ItemType[index] == "Sword" || ItemType[index] == "Shield") {
			Quantity[index] -= 1;
			std::cout << "\nYou have Equipped, your " << *it << ".\n" << endl;
		}
		else if (Quantity[index] == 1 && ItemType[index] == "Sword" || ItemType[index] == "Shield"){
			Quantity.erase(Quantity.begin() + index);
			Items.erase(Items.begin() + index);
			ItemPrice.erase(ItemPrice.begin() + index);
			Rarity.erase(Rarity.begin() + index);
			std::cout << "\nYou have Equipped, your " << *it << ".\n" << endl;
		}
		else{
			std::cout << "\nThat item, is not equipable!\n" << endl;
		}
	}
	else{
		std::cout << "\nThe item: " << item << " was not found.\n";
	}
}

void Player::unEquip(std::string item) {
	//do unequip stuff
}*/