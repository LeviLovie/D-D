#include <cstddef>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "terminal.h"
#include "newGameGetters.h"
#include "subGame.h"
#include "saving.h"

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

    SavePreGame(saveFile, startRoom, countOfPlayers, players);
    
    return 1;
}

string GetSave() {
    ClearTerminal();
    MoveCursorTo(0, 0);

    string wrongMessage = "";
    string loadfile;
    while (true) {
        ClearTerminal();
        MoveCursorTo(0, 0);
        cout << "Press file name to load save, to play, on save (write without \".dat\")" << endl;
        cout << "Saves:" << endl;
        SeeSaves();
        DrawInTerm(wrongMessage);
        cin >> loadfile;
        ifstream file("saves/" + loadfile + ".dat");
        if (loadfile.rfind(".dat") != string::npos) {
            wrongMessage = "You haven't write \".dat\" in save name";
        } else if (loadfile == "") {
            wrongMessage = "You haven't write save name";
        } else if (!file.good()) {
            wrongMessage = "Save doesn't exist";
        } else {
            break;
        }
    }

    return loadfile;
}