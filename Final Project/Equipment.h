#pragma once
#include "Player.h"
#include <string>
#include <typeinfo>
class Equipment
{
public:

	virtual const char* getType() = 0;

private:
	std::string itemName;
	Player player;
protected:
	Equipment(std::string name, Player player) :
		itemName(name),
		player(player) {}
};

enum class armorSlots {
	UNDEF,
	Helmet,
	Chestplate,
	Gloves,
	Leggings,
	Boots,
	Shield
};

class Armor : public Equipment {
	virtual const char* getType() { return typeid(*this).name(); };
};