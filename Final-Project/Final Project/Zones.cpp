#include "Zones.h"
#include <iostream>
#include "Player.h"
#include <string>
#include <algorithm>
#include "Enemy.h"
#include "Item.h"
#include "Bossfight_and_Ending.h"


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
	Enemy mob;
	BossFight boss;
	int choosemob;
	int runaway;
	char response = 'z';
	char playerResponse = '1';
	char shopChoice;
	bool leaveShop = false;
	std::string EquipChoice = " ";
	std::string unEquipChoice = " ";
	std::string sellChoice = " ";
	std::string buyChoice = " ";
	int statPointChoice;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Entering Riverbrook~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Well, " << player.playerName() << ", I am Josephine, welcome to Riverbrook!\n";
	do {
		std::cout << "Would you like to [a]dventure out of town, [s]hop, [r]est at the inn, check your [c]haracter stats, add attribute [p]oints, [e]quip an item, [u]nequip an item, or look at your [i]nventory\n";
		std::cin >> playerResponse;
		playerResponse = toupper(playerResponse);
		//switch (playerResponse) {
#pragma region Adventure
		//case 'A':
		if (playerResponse == 'A') {
			location = "You venture out of the town.\n";
			locationDescribe();
			choosemob = rand() % (2) + 1;
			runaway = rand() % (4) + 1;// decides what mob to spawn at random
			//name, hp, maxhp, level, strength
			if (getStage() < 5) {
				if (choosemob == 1) {
					mob.enemy("slime", 10, 10, 1, 1);
				}
				else if (choosemob == 2) {
					mob.enemy("rat", 15, 15, 2, 1);
				}
			}
			else if (getStage() == 5) {
				mob.enemy("Big rat", 50, 50, 5, 5);
			}
			else  if (getStage() > 5 && getStage() < 10) {
				mob.enemy("slimey", 15, 15, 5, 2);
			}
			else if (getStage() == 10) {
				mob.enemy("Big rat", 75, 75, 10, 10);
			}
			else  if (getStage() > 10 && getStage() <15) {
				mob.enemy("slimey", 35, 35, 10, 5);
			}
			else if (getStage() == 15) {
				boss.StartTicTacToe(player);
				stageUp();
				mob.enemy("Knight carrying away the Queens Loot", 115, 115, 15, 15);
			}
			else  if (getStage() > 15) {
				if (choosemob == 1) {
					mob.enemy("Knight of the Monster Queen", 115, 115, 18, 20);
				}
				else if (choosemob == 2) {
					mob.enemy("God Tier Rat", 100, 100, 16, 15);
				}
			}
			mob.spawnEnemy();
#pragma endregion

#pragma region fightCode
			while (player.isAlive == true && mob.isAlive == true) {

				std::cout << "Would you like to [f]ight? or [r]un\n";

				std::cin >> response;
				response = toupper(response); // negates caps/lowercase
				if (response == 'F') {
					mob.takeDamage(player.pDamage());
					player.takeDamage(mob.mobStrength());
					if (mob.isAlive == false) {
						stageUp();
						mob.Die();
						player.addGold(mob.dropGold());
						player.addXP(mob.dropXP()); // gives the player xp from the mob
						player.onLevel(); // checked if the player can level
						player.addItem(mob.dropItem(mob)); // adds the dropped item to the players inventory
						if (mob.getLevel() == 15) {
							Item hellflameSword("HELLFLAME SWORD", "LEGENDARY", "Weapon", 1000, 1, 0, 100, 0, 0, 0);
							Item queensStaff("QUEENS STAFF", "LEGENDARY", "Weapon", 1000, 1, 0, 0, 100, 0, 0);
							Item crownOfLies("CROWN OF LIES", "MYTHIC", "Armor", 3500, 1, 150, 1000, 250, 475, 630);
							player.addItem(hellflameSword);
							player.addItem(queensStaff);
							player.addItem(crownOfLies);
						}
					}
				}
				if (response == 'R') {
					std::cout << "\nYou attempt to run\n\n";
					if (runaway >= 1 && runaway < 4) {
						std::cout << "You run away succesfully\n\n";
						mob.isAlive == false;
					}
					else {
						std::cout << "Your attempt failed\n\n";
					}
				}
				if (response == 's') {
					player.displayStats();
				}
			};

#pragma endregion
			//adventure
			////////continue;
		}
#pragma endregion
#pragma region Shop
		else if (playerResponse == 'S') {


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
				if (shopChoice == 'A') {
					player.MdisplayInventory();
					std::cout << "Please enter the item you wish to buy.\n";
					std::cin.ignore();
					std::getline(std::cin, buyChoice);
					std::transform(buyChoice.begin(), buyChoice.end(), buyChoice.begin(), ::toupper);
					player.buyItems(buyChoice);
				}

				else if (shopChoice == 'S') {
					player.displayInventory();
					std::cout << "Please enter the item you wish to sell.\n";
					std::cin.ignore();
					std::getline(std::cin, sellChoice);
					std::transform(sellChoice.begin(), sellChoice.end(), sellChoice.begin(), ::toupper);
					player.SellItems(sellChoice);
				}
				else if (shopChoice == 'E') {
					std::cout << "\n\nAlright then see you later.\n\n";
					leaveShop = true;
					shopVisits += 1;
				}
				else {
					std::cout << "\n\n" << shopChoice << " Is not an option, cant you read?\n\n";
				}
			} while (leaveShop != true);
			////////continue;
		}
#pragma endregion
#pragma region Rest
		//case 'R': //rest at inn restoring all hp
		else if (playerResponse == 'R'){
			std::cout << "Would you like to sleep at the inn? (150 gold) y/n\n";
			std::cin >> playerResponse;
			playerResponse = toupper(playerResponse);
			if (playerResponse == 'Y') {
				if (player.minusGold(150) == true) {
					std::cout << "You sleep at the inn, fully restoring all hp!\n";
					player.rest();
					////continue;
				}
				else {
					std::cout << "Not enough gold!\n";
					////continue;
				}
			}
			else {
				////continue;
			}
		}
#pragma endregion
#pragma region Character Stats
		//case 'C':
		else if (playerResponse == 'C'){
			player.displayStats();
			////continue;
		}
#pragma endregion
#pragma region Inventory
		else if (playerResponse == 'I'){
			player.displayInventory();
			////continue;
		}
#pragma endregion
#pragma region Equip
		//case 'E':
		else if (playerResponse == 'E'){
			std::cout << "Please enter the item you wish to equip.\n";
			std::cin.ignore();
			std::getline(std::cin, EquipChoice);
			std::transform(EquipChoice.begin(), EquipChoice.end(), EquipChoice.begin(), ::toupper);
			player.Equip(EquipChoice);
			////continue;
		}
#pragma endregion
#pragma region Unequip
		//case 'U':
		else if (playerResponse == 'U') {
			std::cout << "Please enter the item you wish to unequip.\n";
			std::cin.ignore();
			std::getline(std::cin, unEquipChoice);
			std::transform(unEquipChoice.begin(), unEquipChoice.end(), unEquipChoice.begin(), ::toupper);
			player.unEquip(unEquipChoice);
			////continue;
		}
#pragma endregion
#pragma region Stat points
		//case 'P':
		else if (playerResponse == 'P') {
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
			////continue;
		}
#pragma endregion
		else{
			std::cout << "Please enter a valid response!\n";
			////continue;
		}
	} while (player.isAlive != false);
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