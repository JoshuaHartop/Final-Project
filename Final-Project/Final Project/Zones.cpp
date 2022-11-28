#include "Zones.h"
#include <iostream>
#include "Player.h"
#include <string>
#include <algorithm>

void Zones::stageUp() {
	stage += 1;
}

void Zones::starterTown(Player player) {
	// send the player back to town
	std::cout << "Well, " << player.playerName() << ", I am Josephine, welcome to Riverbrook!\n";
	do {
		std::cout << "Would you like to [a]dventure out of town, [s]hop, [r]est at the inn, check your [c]haracter stats, [e]quip an item, or look at your [i]nventory\n";
		std::cin >> playerResponse;
		playerResponse = toupper(playerResponse);
		switch (playerResponse) {
		case 'A':
			//adventure
			break;

		case 'S':
			//shop
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

			//player.Equip(EquipChoice, player);
			break;

		default:
			std::cout << "Please enter a valid response!\n";
			break;
		}
	} while (playerResponse != 'A');
}