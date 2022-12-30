#include <cstddef>
#include <iostream>
using namespace std;

#include "terminal.h"
#include "newGameGetters.h"
#include "subGame.h"

short startRoom;
short countOfPlayers;
std::string playerTypes[4] = {"Warrior", "Mage", "Archer", "Scientist"};
Player players[16];

void WriteGameInfo() {
    ClearTerminal();
    MoveCursorTo(0, 0);
    cout << "Start room: " << startRoom << endl;
    cout << "Count of players: " << countOfPlayers << endl;

    Player playerData;
    for (short player = 0; player < countOfPlayers; player++) {
        playerData = players[player];
        cout << "Player " << playerData.name << ": ";
        cout << "Health: " << playerData.health << ", ";
        cout << "Type: " << playerTypes[playerData.type] << ", ";
        cout << "Inventory: " << playerData.inventory[0] << "; " << endl;
    }
}

short NewGame() {
    ClearTerminal();
    cout << "New game's starting" << endl;

    startRoom = getStartRoom();
    countOfPlayers = getCountOfPlayers();
    Player localPlayers[countOfPlayers];
    for (short player = 0; player < countOfPlayers; player++) {
        localPlayers[player] = getPlayer(player);
    }
    for (short player = 0; player < countOfPlayers; player++) {
        if (player <= countOfPlayers) {
            players[player] = localPlayers[player];
        } else {
            players[player] = Player(0, 0, "", NULL);
        }
    }

    ClearTerminal();
    WriteGameInfo();
    DrawInTerm("Press any key to exit:");
    cin >> StringTrash;
    return 1;
}