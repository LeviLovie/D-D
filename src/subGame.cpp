#include <iostream>

#include "subGame.h"
#include "terminal.h"

Player :: Player() {}

Player :: Player(short health, short type, std::string name, std::string inventory[16]) {
    health = health;
    type = type;
    name = name;
    inventory = inventory;
}

void WriteGameInfo(short startRoom, short countOfPlayers, Player players[16], std::string saveFile) {
    std::string playerTypes[4] = {"Warrior", "Mage", "Archer", "Scientist"};
    ClearTerminal();
    MoveCursorTo(0, 0);
    std::cout << "Game info:" << std::endl;
    std::cout << "Start room: " << startRoom << std::endl;
    std::cout << "Count of players: " << countOfPlayers << std::endl;
    Player playerData;
    for (short player = 0; player < countOfPlayers; player++) {
        playerData = players[player];
        std::cout << "Player " << playerData.name << ": ";
        std::cout << "Health: " << playerData.health << ", ";
        std::cout << "Type: " << playerTypes[playerData.type - 1] << ", ";
        std::cout << "Inventory: " << playerData.inventory[0] << "; " << std::endl;
    }
    std::cout << "Save file: " << saveFile << std::endl;
}