#pragma once
#include <string>
#include "Player.h"
class Zones {
public:
	void starterTown(Player player);
	void stageUp();
	void plains();
	std::string locationDescribe();
	int getStage();
private:
	char playerResponse;
	int stage;
    std::string EquipChoice;
	std::string location;
};