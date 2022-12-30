#include <cstddef>
#include <iostream>
using namespace std;

#include "terminal.h"
#include "newGameGetters.h"
#include "subGame.h"

short startRoom;
short countOfPlayers;
Player players[16];
string saveFile;

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
    saveFile = getSaveFileName();

    ClearTerminal();
    WriteGameInfo(startRoom, countOfPlayers, players, saveFile);

    DrawInTerm("Press any key to exit:");
    cin >> StringTrash;

    return 1;
}