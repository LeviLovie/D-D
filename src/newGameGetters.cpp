#include "subGame.h"
#include <iostream>
using namespace std;

#include "terminal.h"

short getStartRoom() {
    short chose = 0;
    bool wrong = false;
    short result;

    MoveCursorTo(0, 27);
    cout << "";

    while (true) {
        ClearTerminal();
        cout << "Press type of start room" << endl;
        cout << "1. Dungeon;" << endl;

        MoveCursorTo(0, 26);
        for (short i = 0; i < 120; i++) {
            cout.write(FullRectCharBytes, 3);
        }
        MoveCursorTo(0, 27);
        if (wrong) {
            cout << "Wrong chose! Try again.";
            wrong = false;
        }
        MoveCursorTo(0, 28);
        wcout << ">";

        cin >> chose;
        if (chose != 1) {
            wrong = true;
        } else {
            wrong = false;
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
    bool wrong = false;

    MoveCursorTo(0, 27);
    cout << "";

    while (true) {
        ClearTerminal();
        cout << "Press type of count of players" << endl;

        MoveCursorTo(0, 26);
        for (short i = 0; i < 120; i++) {
            cout.write(FullRectCharBytes, 3);
        }
        MoveCursorTo(0, 27);
        if (wrong) {
            cout << "Wrong chose! Try again.";
            wrong = false;
        }
        MoveCursorTo(0, 28);
        wcout << ">";

        cin >> chose;
        if (chose <= 1) {
            wrong = true;
        } else {
            wrong = false;
            break;
        }
    }

    return chose;
}

Player getPlayer(short playerNumber) {
    Player player(0, 0, "", NULL);
    ClearTerminal();
    MoveCursorTo(0, 0);

    bool wrong = false;
    string wrongString = "";
    while (true) {
        cout << "Press name of player " << playerNumber + 1 << ":";
        DrawInTerm(wrongString);
        cin >> player.name;

        if (player.name.length() > 16) {
            wrong = true;
            wrongString = "Name is too long! (Name can't be longer of 16 chars) Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else if (player.name == "") {
            wrong = true;
            wrongString = "Name can't be empty! Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else if (player.name == "fuck" || player.name == "Fuck") {
            wrong = true;
            wrongString = "Name can't be \"f**k\"! Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else {
            wrong = false;
            break;
        }
    }

    ClearTerminal();
    MoveCursorTo(0, 0);
    wrong = false;
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
            wrong = true;
            wrongString = "Wrong type! Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else {
            wrong = false;
            break;
        }
    }

    ClearTerminal();
    MoveCursorTo(0, 0);
    wrong = false;
    wrongString = "";
    while (true) {
        cout << "Press start health of player " << playerNumber + 1 << ":";
        DrawInTerm(wrongString);
        cin >> player.health;

        if (player.health <= 0) {
            wrong = true;
            wrongString = "Health can't be less or equal of 0! Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else if (player.health > 127) {
            wrong = true;
            wrongString = "Health can't be more of 127! Try again.";
            ClearTerminal();
            MoveCursorTo(0, 0);
        } else {
            wrong = false;
            break;
        }
    }

    return player;
}