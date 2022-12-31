#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "subGame.h"

void SavePreGame(string saveFile, short startRoom, short countOfPlayers, Player players[]) {
    ofstream file;
    file.open("saves/" + saveFile + ".dat");

    file << "<game setup>" << endl;
    file << startRoom << endl;
    file << countOfPlayers << endl;
    for (short player = 0; player < 16; player++) {
        file << "<player>" << endl;
        if (players[player].name == "") {
            file << "NameNULL" << endl;
        } else {
            file << players[player].name << endl;
        }
        file << players[player].health << endl;
        file << players[player].type << endl;
        for (short item = 0; item < 16; item++) {
            if (players[player].inventory[item] == "") {
                file << "ItemNULL" << endl;
            } else {
                file << players[player].inventory[item] << endl;
            }
        }
    }

    file.close();
}

Player LoadPlayer(string filename, short playerNumber) {
    Player player;
    ifstream file;
    file.open("saves/" + filename + ".dat");

    string line;
    short localPlayerNumber = 0;
    while (getline(file, line)) {
        if (line == "<player>") {
            localPlayerNumber++;
            // cout << "Player found! " << localPlayerNumber << " - " << playerNumber << endl;
            if (localPlayerNumber == playerNumber) {
                // cout << "Player " << playerNumber << " found!" << endl;
                getline(file, line);
                // if (line == "NameNULL") {
                    // player.name = "";
                // } else {
                    player.name = line;
                // }
                getline(file, line);
                player.health = stoi(line);
                getline(file, line);
                player.type = stoi(line);
                for (short item = 0; item < 16; item++) {
                    getline(file, line);
                    if (line == "ItemNULL") {
                        player.inventory[item] = "";
                    } else {
                        player.inventory[item] = line;
                    }
                }
            }
        }
    }
    return player;
}