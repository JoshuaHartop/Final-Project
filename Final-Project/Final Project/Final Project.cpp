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
    do {
        std::cout.flush();
        std::cerr << "Hello traveller, what should I call you?" << std::endl;
        player.setName();
        std::cout << "Nice to meet you " << player.playerName() << "\n"
            << "Welcome to Humongalongous\n";
#pragma region Character Creator
        player.pCreateChar();
#pragma endregion
        player.gameStart(); // initializes player stats // player is alive

        std::cout << "As you walk through the forest on the way to your home, you see it, MONSTERS, the forest overflows with them.\n";
        std::cout << "Some start to notice you and they form a wave to come and destroy you, a grotesque humanoid creature emerges from behind them and points at you.\n";
        std::cout << "In a shrill shriek scream, it manages to form the words -Food is ready- the only thing you can think of is to run.\n";
        std::cout << "You know that the Monster Kings attack are indiscriminate whether you are a " << player.getRace() << " or not you know your only chance is escape.\n";
        std::cout << "You ran so long that when you stopped you collapsed, you knew it had been many hours, as the sun had already emerged by then.\n";
        std::cout << "You know you still need to find safety, you see smoke rising from the east, that must mean a person is over there as all monsters hate light.\n";
        std::cout << "You run towards it at full speed, not knowing the toll it takes on your body.\n";
        std::cout << "Eventually, you make it to a town, and are greeted by a voice that sounds more familiar than person who owns it looks...\n\n";
#pragma region startTown
        zone.starterTown(player);
#pragma endregion
        return 0;
    } while (player.isAlive != false);
#pragma region mobSpawn

}
/*
The game must have a short, creative story supporting the adventure.                                | DONE - Ryan
The game must allow for character creation for the hero.                                            | DONE - Ryan/Josh
The hero must include all traits from A2 plus: hit points, combat traits, experience, and level.    | DONE - Josh
The hero must have an inventory and must start with basic adventuring gear.                         | DONE - Ryan/Josh
The adventure must have enemies for the hero to engage in combat.                                   | DONE - Josh
The game must have a combat system.                                                                 | DONE - Josh
The player must earn rewards for victory in combat.                                                 | DONE - Josh
The player must be able to visit a town or haven between challenges.                                | DONE - Ryan 
The player must be able to recover hit points.                                                      | DONE - Josh
The player must be able to interact with merchants in the town/haven.                               | DONE - Ryan
The game must have defined winning and losing conditions.                                           | HALF DONE - Josh/Ryan
*/