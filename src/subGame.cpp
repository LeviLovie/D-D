#include <iostream>

#include "subGame.h"
#include "terminal.h"

Player :: Player() {}

std::string PlayerTypes[5] = {"Not playing", "Warrior", "Mage", "Archer", "Scientist"};

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

void SeeSaves() {
    FILE* ls = popen("ls saves", "r");
    if (!ls) {
        std::cerr << "Error executing command" << std::endl;
    }
    char line[256];
    while (fgets(line, sizeof(line), ls)) {
        std::cout << "    " << line;
    }
    pclose(ls);
}

void createRoom(char room[25][120]) {
    for (short i = 0; i < 25; i++) {
        for (short j = 0; j < 120; j++) {
            room[i][j] = ' ';
        }
    }
    for (short i = 0; i < 25; i++) {
        if (i > 3 && i < 21) {
            room[i][3] = '|';
            room[i][116] = '|';
        }
    }
    for (short i = 0; i < 120; i++) {
        if (i > 3 && i < 116) {
            room[3][i] = '-';
            room[21][i] = '-';
        }
    }
    room[3][3] = '+';
    room[3][116] = '+';
    room[21][3] = '+';
    room[21][116] = '+';
}