#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Zones.h"
    int main() {
        Item rustySword("Rusty Sword", " test", "common", "sword", 1, 1, 1, 1, 1, 1, 1);
#pragma region variables
        Enemy mob;
        int choosemob;
        char response = 'z';
        Player player;
        Zones zone;
        srand(static_cast<unsigned int>(time(0)));
#pragma endregion
        std::cout << "Hello, what should I call you?\n";
        player.setName();
        std::cout << "Hello " << player.playerName() << "\n"
            << "Welcome to [insert name]\n";
        player.gameStart(); // initializes player stats // player is alive
        do {
#pragma region startTown
            zone.starterTown(player);
#pragma endregion


#pragma region mobSpawns
            choosemob = rand() % (2) + 1; // decides what mob to spawn at random

            if (choosemob == 1) {
                mob.enemy("slime", 10, 10, 1, 1);
            }
            else if (choosemob == 2) {
                mob.enemy("rat", 15, 15, 2, 1);
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

                        mob.Die();
                        player.addGold(mob.dropGold());
                        player.addXP(mob.dropXP());
                        player.onLevel();
                        player.addItem(rustySword);

                    }
                }
                if (response == 's') {
                    player.displayStats();
                }
            };

#pragma endregion
        } while (player.isAlive == true);

    }


/*
The game must have a short, creative story supporting the adventure.                                | NOT DONE - Ryan
The game must allow for character creation for the hero.                                            | NOT DONE - Ryan/Josh
The hero must include all traits from A2 plus: hit points, combat traits, experience, and level.    | NOT DONE - Josh
The hero must have an inventory and must start with basic adventuring gear.                         | DONE - Ryan/Josh
The adventure must have enemies for the hero to engage in combat.                                   | DONE - Josh
The game must have a combat system.                                                                 | DONE - Josh
The player must earn rewards for victory in combat.                                                 | NOT DONE - Josh
The player must be able to visit a town or haven between challenges.                                | DONE - Ryan 
The player must be able to recover hit points.                                                      | NOT DONE - Josh
The player must be able to interact with merchants in the town/haven.                               | NOT DONE - Ryan
The game must have defined winning and losing conditions.                                           | NOT DONE - Josh/Ryan
*/