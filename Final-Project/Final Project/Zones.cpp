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

void Zones::starterTown(Player player) {
	// send the player back to town
	bool leaveShop;
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
			char shopChoice;
			leaveShop = false;
#pragma region Shop
			do {
				if (player.shopVisits = 0) {
					std::cout << "\n\nWelcome to my shop, I am Ansgard, and I have everything you need.\n\n";
				}
				else if (player.shopVisits = 1) {
					std::cout << "\n\nI never caught your name, what was it?\n\n";
				}
				else if (player.shopVisits >= 2){
					std::cout << "\n\nHello again " << player.playerName() << " how is the adventuring going?\n\n";
				}
				else if (player.shopVisits >= 10) {
					std::cout << "\n\nDont you think you come here to much?\n\n";
				}
				else if (player.shopVisits == 20) {
					std::cout << "\n\n" << player.playerName() << " Do you think I should start make a rewards card for my store?\n\n";
				}
				else if (player.shopVisits >= 21) {
					std::cout << "\n\nNice to see you again " <<player.playerName()<<".\n\n";
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
				case 'P':
					//Potions
					break;
				case'S':
					//Selling
					break;
				case'E':
					std::cout << "\n\nReally? Next time you come in here make sure you buy something, I'm running a business here.\n\n";
					leaveShop = true;
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