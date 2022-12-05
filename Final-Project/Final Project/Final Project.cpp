#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Zones.h"
#include <algorithm>
    int main() {


#pragma region variables
    
    int choosemob;
    char response = 'z';
    Player player;
    Zones zone;
    Item nothing;
    bool finalBossKilled = false;
    srand(static_cast<unsigned int>(time(0)));
#pragma endregion

    std::cout << "Hello traveller, what should I call you?\n";
    player.setName();
    std::cout << "Nice to meet you " << player.playerName() << "\n"
        << "Welcome to Humongalongous\n";
#pragma region Character Creator
    player.pCreateChar();
#pragma endregion
    player.gameStart(); // initializes player stats // player is alive
    do {

#pragma region startTown
        zone.starterTown(player);
#pragma endregion

#pragma region mobSpawns

    } while (player.isAlive == true);
}


/*
The game must have a short, creative story supporting the adventure.                                | NOT DONE - Ryan
The game must allow for character creation for the hero.                                            | DONE - Ryan/Josh
The hero must include all traits from A2 plus: hit points, combat traits, experience, and level.    | DONE - Josh
The hero must have an inventory and must start with basic adventuring gear.                         | DONE - Ryan/Josh
The adventure must have enemies for the hero to engage in combat.                                   | DONE - Josh
The game must have a combat system.                                                                 | DONE - Josh
The player must earn rewards for victory in combat.                                                 | DONE - Josh
The player must be able to visit a town or haven between challenges.                                | DONE - Ryan 
The player must be able to recover hit points.                                                      | DONE - Josh
The player must be able to interact with merchants in the town/haven.                               | NOT DONE - Ryan
The game must have defined winning and losing conditions.                                           | HALF DONE - Josh/Ryan
*/