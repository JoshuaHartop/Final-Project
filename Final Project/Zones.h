#pragma once
#include <string>
#include "Player.h"
class Zones {
public:
	void starterTown(Player player);
	void stageUp();
private:
	char playerResponse;
	int stage;
    std::string EquipChoice;
};

class Shop {
public:

private:
	char shopChoice;

};
