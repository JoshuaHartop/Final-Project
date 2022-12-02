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
	char shopChoice;
	bool leaveShop = false;
	std::string EquipChoice = " ";
	std::string unEquipChoice = " ";
	int statPointChoice;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Entering Riverbrook~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Well, " << player.playerName() << ", I am Josephine, welcome to Riverbrook!\n";
	do {
		std::cout << "Would you like to [a]dventure out of town, [s]hop, [r]est at the inn, check your [c]haracter stats, add attribute [p]oints, [e]quip an item, [u]nequip an item, or look at your [i]nventory\n";
		std::cin >> playerResponse;
		playerResponse = toupper(playerResponse);
		switch (playerResponse) {
#pragma region Adventure
		case 'A':
			location = "You venture out of the town.\n";
			locationDescribe();
			//adventure
			break;
#pragma endregion
#pragma region Shop
		case 'S':
			

			do {
				if (shopVisits == 0) {
					std::cout << "\nWelcome to my shop, I am Ansgard, and I have everything you need.\n\n";
				}
				else if (shopVisits == 1) {
					std::cout << "\nI never caught your name, what was it?\n\n";
				}
				else if (shopVisits >= 2 && shopVisits < 10) {
					std::cout << "\nHello again " << player.playerName() << " how is the adventuring going?\n\n";
				}

				else if (shopVisits >= 10 && shopVisits < 15) {
					std::cout << "\n\nDont you think you come here to much?\n\n";
				}
				else if (player.shopVisits >= 15 && shopVisits < 21) {
					std::cout << "\n\n" << player.playerName() << " Do you think I should start make a rewards card for my store?\n\n";
				}
				else if (player.shopVisits >= 21) {
					std::cout << "\n\nNice to see you again " << player.playerName() << ".\n\n";
				}
				std::cout << "So what is it you came here for?\n"
						  << "[A] Armor\n"
						  << "[S] Selling\n"
						  << "[E] Exit\n";
				std::cin >> shopChoice;
				shopChoice = toupper(shopChoice);
				switch (shopChoice) {
				case 'A':
				//Armor
				break;
				case'S':
					player.displayInventory();
					
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
			break;
#pragma endregion
#pragma region Rest
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
#pragma endregion
#pragma region Character Stats
		case 'C':
			player.displayStats();
			break;
#pragma endregion
#pragma region Inventory
		case 'I':
			player.displayInventory();
			break;
#pragma endregion
#pragma region Equip
		case 'E':
			std::cout << "Please enter the item you wish to equip.\n";
			std::cin.ignore();
			std::getline(std::cin, EquipChoice);
			std::transform(EquipChoice.begin(), EquipChoice.end(), EquipChoice.begin(), ::toupper);
			player.Equip(EquipChoice);
			break;
#pragma endregion
#pragma region Unequip
		case 'U':
			std::cout << "Please enter the item you wish to unequip.\n";
			std::cin.ignore();
			std::getline(std::cin, unEquipChoice);
			std::transform(unEquipChoice.begin(), unEquipChoice.end(), unEquipChoice.begin(), ::toupper);
			player.unEquip(unEquipChoice);
			break;
#pragma endregion
#pragma region Stat points
		case 'P':
			do {
				std::cout << "\nDisplaying available attributes:\n";
				player.displayStatPointPage();
				std::cout << "You currently have " << player.getStatPoints() << " attribute points\n";
				if (player.getStatPoints() >= 1) {
					std::cout << "Where would you like to put in 1 attribute point? Press 0 or spend all attribute points to exit\n";
					std::cin >> statPointChoice;
					player.addStatPoint(statPointChoice);
				}
				else {
					statPointChoice = 0;
				}
			} while (statPointChoice != 0);
			break;
#pragma endregion
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
	else if (stage == 2) {
		//stage 2 stuff
	}
	else if (stage == 3) {
		//stage 3 stuff
	}
}