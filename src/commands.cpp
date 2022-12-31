#include <iostream>
#include <string>
using namespace std;

#include "terminal.h"
#include "subGame.h"

void commHelp() {
    cout << "Commands:" << endl;
    cout << "    help - show this message;" << endl;
    cout << "    room - show room;" << endl;
    cout << "    player - show player info;" << endl;
    cout << "    players - show info about all players;" << endl;
    cout << "    end - end game without saving;" << endl;
    cout << "    refresh - clear RAM, clear terminal, clear useless data." << endl;
}

void commRoom(char room[25][120]) {
    for (short i = 0; i < 25; i++) {
        for (short j = 0; j < 120; j++) {
            cout << room[i][j];
        }
        cout << endl;
    }
}

void commRefresh() {
    cout << "\e[3J";
    cout << "Clearing Terminal..." << endl;
    cout << "Clearing RAM..."  << endl;
    ClearRAM();
    cout << "Clearing useless data..." << endl;
    cout << "Done!" << endl;
}

void commPlayer(Player players[16], short intInput) {
    cout << "Player " << intInput << endl;
    cout << "Name: " << players[intInput].name << endl;
    cout << "Health: " << players[intInput].health << endl;
    cout << "Type: " << PlayerTypes[players[intInput].type] << endl;
    cout << "Inventory: " << endl;
    for (short i = 0; i < 16; i++) {
        cout << "    " << players[intInput].inventory[i] << endl;
    }
}

void commPlayers(Player players[16], short intInput) {
    cout << "Name: " << players[0].name;
    cout << "    " << "Name: " << players[1].name;
    cout << "    " << "Name: " << players[2].name;
    cout << "    " << "Name: " << players[3].name << endl;

    cout << "Health: " << players[intInput].health;
    cout << "    " << "Health: " << players[intInput].health;
    cout << "    " << "Health: " << players[intInput].health;
    cout << "    " << "Health: " << players[intInput].health << endl;

    cout << "Type: " << PlayerTypes[players[intInput].type];
    cout << "    " << "Type: " << PlayerTypes[players[intInput].type];
    cout << "    " << "Type: " << PlayerTypes[players[intInput].type];
    cout << "    " << "Type: " << PlayerTypes[players[intInput].type] << endl;
}