#pragma once
#include <string>
class Item {
public:
	
	Item() {}
	Item(std::string name, std::string rarity, std::string type, int price, int quantity, int str,int hp, int intel, int dex, int agi);
	std::string displayItem();
	std::string getName();
	std::string getType();
private:
	// stat modifiers
	int strModifier;
	int hpModifier;
	int intModifier;
	int dexModifier;
	int agiModifier; 
	
	// item description
	std::string itemName;
	std::string itemRarity;
	std::string itemType;
	int itemPrice;
	int itemQuantity;
	//
	
};

