#include "Zones.h"
#include <iostream>
#include "Player.h"
#include <string>
#include <algorithm>
#include "Enemy.h"
#include "Item.h"


void Zones::stageUp() {
	stage += 1;
}

int Zones::getStage() {
	return stage;
}

std::string Zones::locationDescribe() {
	return location;
}
char shopChoice;
bool leaveShop = false;
void Zones::starterTown(Player player) {
	// send the player back to town
	std::string EquipChoice = " ";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Entering Riverbrook~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Well, " << player.playerName() << ", I am Josephine, welcome to Riverbrook!\n";
	do {
		std::cout << "Would you like to [a]dventure out of town, [s]hop, [r]est at the inn, check your [c]haracter stats, [e]quip an item, or look at your [i]nventory\n";
		std::cin >> playerResponse;
		playerResponse = toupper(playerResponse);
		switch (playerResponse) {
		case 'A':
			location = "You venture out of the town.\n";
			locationDescribe();
			//adventure
			break;

		case 'S':
			
#pragma region Shop
			do {
				if (shopVisits <= 0) {
					std::cout << "\nWelcome to my shop, I am Ansgard, and I have everything you need.\n\n";
				}
				else if (shopVisits == 1) {
					std::cout << "\nI never caught your name, what was it?\n\n";
				}
				else if (shopVisits >= 2) {
					std::cout << "\nHello again " << player.playerName() << " how is the adventuring going?\n\n";
				}
				std::cout << "So what is it you came here for?\n";
				std::cout << "[W] Weapons\n";
				std::cout << "[P] Potions\n";
				std::cout << "[S] Selling\n";
				std::cout << "[E] Exit\n";
				std::cin >> shopChoice;
				shopChoice = toupper(shopChoice);
				switch (shopChoice) {
				case 'W':
					//weapons
					break;
					leaveShop = true;
					shopVisits += 1;
				case 'P':
					//Potions
					break;
					leaveShop = true;
					shopVisits += 1;
				case'S':
					//Selling
					leaveShop = true;
					shopVisits += 1;
					break;
				case'E':
					std::cout << "\n\nAlright then see you later.\n\n";
					leaveShop = true;
					shopVisits += 1;
					break;
				default:
					std::cout << "\n\n" << shopChoice << " Is not an option, cant you read?\n\n";
					break;
				}
			} while (leaveShop != true);
			
#pragma endregion
			break;

		case 'R': //rest at inn restoring all hp
			std::cout << "Would you like to sleep at the inn? (150 gold) y/n\n";
			std::cin >> playerResponse;
			playerResponse = toupper(playerResponse);
			if (playerResponse == 'Y') {
				if (player.minusGold(150) == true) {
					std::cout << "You sleep at the inn, fully restoring all hp!\n";
					player.rest();
					break;
				}
				else {
					std::cout << "Not enough gold!\n";
					break;
				}
			}
			else {
				break;
			}

		case 'C':
			player.displayStats();
			break;

		case 'I':
			player.displayInventory();
			break;

		case 'E':
			std::cout << "Please enter the item you wish to equip.\n";
			std::cin.ignore();
			std::getline(std::cin, EquipChoice);
			//player.Equip(EquipChoice);
			break;

		default:
			std::cout << "Please enter a valid response!\n";
			break;
		}
	} while (playerResponse != 'A');
}

void Zones::plains() {
	if (stage == 1) {
		location = "Rolling hills with sharp blades of grass for all the eye can see\n";
	}
}