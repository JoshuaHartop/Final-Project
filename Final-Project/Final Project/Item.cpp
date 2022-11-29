#include "Item.h"
#include <string>
#include <iostream>


//My equip code was perfect before this
Item::Item(std::string name, std::string rarity, std::string type, int price, int quantity, int str, int hp, int intel, int dex, int agi) {
	itemName = name;
	itemRarity = rarity;
	itemType = type;
	itemPrice = price;
	itemQuantity = quantity;
	strModifier = str;
	hpModifier = hp;
	intModifier = intel;
	dexModifier = dex;
	agiModifier = agi;

}

std::string Item::displayItem() { // displays item
	return (itemName + " " + itemRarity + " $" + 
		std::to_string(itemPrice) + " x" + std::to_string(itemQuantity) + "\nSTR:" + std::to_string(strModifier) + " HP:" + std::to_string(hpModifier) + " INT:" +
		std::to_string(intModifier) + " DEX:" + std::to_string(dexModifier) + " AGI:" + std::to_string(agiModifier));
}

std::string Item::getName() { // gets item name
	return itemName;
}
std::string Item::getType() {
	return itemType;
}