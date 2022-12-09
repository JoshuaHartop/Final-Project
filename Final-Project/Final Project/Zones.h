#pragma once
#include <string>
#include "Player.h"
class Zones {
public:

	int shopVisits = 0;
	void starterTown(Player player);
	void stageUp();
	void plains();
	std::string locationDescribe();
	int getStage();

private:
	char playerResponse;
	int stage = 0;
    std::string EquipChoice;
	std::string location;
};