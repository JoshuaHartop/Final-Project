#pragma once
#include <string>
class Item {
public:
	
	Item() {}
	Item(std::string name, std::string rarity, std::string type, int price, int quantity, int str,int hp, int intel, int dex, int agi);
	std::string displayItem();
	std::string getName();
	std::string getType();
	int getStr();
	int getDex();
	int getIntel();
	int getAgi();
	int getHP();
	int getMoney();
	int getAmount();
	void addAmount(int Amount);
	void takeAmount(int Amount);
private:
	// stat modifiers
	
	int hpModifier;
	int intModifier;
	int dexModifier;
	int agiModifier; 
	int strModifier;
	// item description
	std::string itemName;
	std::string itemRarity;
	std::string itemType;
	int itemPrice;
	int itemQuantity;
	//
	
};