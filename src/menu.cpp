#include "iostream"
using namespace std;

#include "terminal.h"

void Menu() {
    short chose = 0;
    bool wrong = false;

    MoveCursorTo(0, 27);
    cout << "";
    
    while (true) {
        ClearTerminal();
        cout << "1. New game;" << endl;
        cout << "2. Load game;" << endl;
        cout << "3. Exit." << endl;

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
        if (chose != 1 && chose != 2 && chose != 3) {
            wrong = true;
        } else {
            wrong = false;
            break;
        }
    }

    if (chose == 1) {
        // New game
    } else if (chose == 2) {
        // Load game
    } else if (chose == 3) {
        ClearTerminal();
        cout << "Goodbye!" << endl;
        Exit(0);
    }
}