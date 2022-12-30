#include <fstream>
#include <string>
using namespace std;

#include "subGame.h"

void SavePreGame(string saveFile, short startRoom, short countOfPlayers, Player players[]) {
    ofstream file;
    file.open("saves/" + saveFile + ".txt");

    file << "<game setup>" << endl;
    file << startRoom << endl;
    file << countOfPlayers << endl;
    for (short player = 0; player < 16; player++) {
        file << "<player>" << endl;
        file << players[player].health << endl;
        file << players[player].type << endl;
        if (players[player].name == "") {
            file << "NameNULL" << endl;
        } else {
            file << players[player].name << endl;
        }
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