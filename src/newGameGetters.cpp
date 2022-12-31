#include "subGame.h"
#include <iostream>
#include <string>
using namespace std;

#include "terminal.h"

short getStartRoom() {
    short chose = 0;
    string wrongString = "";
    short result;

    while (true) {
        ClearTerminal();
        cout << "Press type of start room" << endl;
        cout << "1. Dungeon;" << endl;

        DrawInTerm(wrongString);

        cin >> chose;
        if (chose != 1) {
            wrongString = "You writed not correct number! Try again.";
        } else {
            if (chose == 1) {
                result = 1;
            }
            break;
        }
    }

    return result;
}

short getCountOfPlayers() {
    short chose = 0;
    string wrongString = "";

    while (true) {
        ClearTerminal();
        cout << "Press count of players" << endl;

        DrawInTerm(wrongString);

        cin >> chose;
        if (chose <= 1) {
            wrongString = "Count of players can't be less of 2! Try again.";
        } else {
            break;
        }
    }

    return chose;
}

Player getPlayer(short playerNumber) {
    Player player(0, 0, "", NULL);
    ClearTerminal();
    MoveCursorTo(0, 0);

    string wrongString = "";
    while (true) {
        cout << "Press name of player " << playerNumber + 1 << ":";
        DrawInTerm(wrongString);
        cin >> player.name;

        if (player.name.length() > 16) {
            wrongString = "Name is too long! (Name can't be longer of 16 chars) Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else if (player.name == "") {
            wrongString = "Name can't be empty! Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else if (player.name == "fuck" || player.name == "Fuck") {
            wrongString = "Name can't be \"f**k\"! Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else {
            break;
        }
    }

    ClearTerminal();
    MoveCursorTo(0, 0);
    wrongString = "";
    while (true) {
        cout << "Press type of player " << playerNumber + 1 << ":" << endl;
        cout << "1. Warrior;" << endl;
        cout << "2. Mage;" << endl;
        cout << "3. Archer;" << endl;
        cout << "4. Scientist." << endl;

        DrawInTerm(wrongString);
        cin >> player.type;

        if (player.type != 1 && player.type != 2 && player.type != 3 && player.type != 4) {
            wrongString = "Wrong type! Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else {
            break;
        }
    }

    bool readHealth = false;
    if (readHealth) {
        ClearTerminal();
        MoveCursorTo(0, 0);
        wrongString = "";
        while (true) {
            cout << "Press start health of player " << playerNumber + 1 << ":";
            DrawInTerm(wrongString);
            cin >> player.health;

            if (player.health <= 0) {
                wrongString = "Health can't be less or equal of 0! Try again.";
                ClearTerminal();
                MoveCursorTo(0, 0);
            } else if (player.health > 127) {
                wrongString = "Health can't be more of 127! Try again.";
                ClearTerminal();
                MoveCursorTo(0, 0);
            } else {
                break;
            }
        }
    } else {
        player.health = 127;
    }

    ClearTerminal();
    MoveCursorTo(0, 0);
    wrongString = "";
    string playerTypes[4] = {"Warrior", "Mage", "Archer", "Scientist"};

    string warriorStuff[6] = {"Sword", "Shield", "Helmet", "Armor", "Boots", "Gold"};
    string mageStuff[5] = {"Bottle", "Robe", "Helmet", "Potion", "Scroll"};
    string archerStuff[6] = {"Bow", "Arrow", "Helmet", "Armor", "Boots", "Gold"};
    string scientistStuff[8] = {"Potion", "Scroll", "Book", "Key", "Gold", "Bottle", "Robe", "Magnifying glass"};

    string result = "";
    while (true) {
        cout << "Press numbers of objects which will in " << player.name << " inventory" << ":" << endl;
        if (player.type == 1) {
            cout << "Stuff for: " << playerTypes[player.type - 1] << endl;
            for (short i = 0; i < 6; i++) {
                cout << i + 1 << ". " << warriorStuff[i] << ";" << endl;
            }
        } else if (player.type == 2) {
            cout << "Stuff for: " << playerTypes[player.type - 1] << endl;
            for (short i = 0; i < 5; i++) {
                cout << i + 1 << ". " << mageStuff[i] << ";" << endl;
            }
        } else if (player.type == 3) {
            cout << "Stuff for: " << playerTypes[player.type - 1] << endl;
            for (short i = 0; i < 6; i++) {
                cout << i + 1 << ". " << archerStuff[i] << ";" << endl;
            }
        } else if (player.type == 4) {
            cout << "Stuff for: " << playerTypes[player.type - 1] << endl;
            for (short i = 0; i < 8; i++) {
                cout << i + 1 << ". " << scientistStuff[i] << ";" << endl;
            }
        }

        DrawInTerm(wrongString);
        cin >> result;

        for (short i = 0; i < result.length(); i++) {
            if (player.type == 1) {
                if (result[i] < '0' || result[i] > '6') {
                    wrongString = "Number have have to be between 1 and 6. Try again.";
                    ClearTerminal();
                    MoveCursorTo(0, 0);
                } else {
                    player.inventory[i] = warriorStuff[i];
                }
            } else if (player.type == 2) {
                if (result[i] < '0' || result[i] > '5') {
                    wrongString = "Number have have to be between 1 and 5. Try again.";
                    ClearTerminal();
                    MoveCursorTo(0, 0);
                } else {
                    player.inventory[i] = mageStuff[i];
                }
            } else if (player.type == 3) {
                if (result[i] < '0' || result[i] > '6') {
                    wrongString = "Number have have to be between 1 and 6. Try again.";
                    ClearTerminal();
                    MoveCursorTo(0, 0);
                } else {
                    player.inventory[i] = archerStuff[i];
                }
            } else if (player.type == 4) {
                if (result[i] < '0' || result[i] > '8') {
                    wrongString = "Number have have to be between 1 and 8. Try again.";
                    ClearTerminal();
                    MoveCursorTo(0, 0);
                } else {
                    player.inventory[i] = scientistStuff[i];
                }
            }
        }

        if (player.health <= 0) {
            wrongString = "Health can't be less or equal of 0! Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else if (player.health > 127) {
            wrongString = "Health can't be more of 127! Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else {
            break;
        }
    }

    return player;
}

string getSaveFileName() {
    string file;
    string wrongString = "";

    while (true) {
        ClearTerminal();
        cout << "Press file to save game" << endl;

        DrawInTerm(wrongString);

        cin >> file;
        if (file == "") {
            wrongString = "File path can't be empty! Try again.";
        } else if (file == "fuck" || file == "Fuck") {
            wrongString = "File path can't be \"f**k\"! Try again.";
        } else {
            break;
        }
    }

    return file;
}