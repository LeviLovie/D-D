#include "iostream"
#include <string>
using namespace std;

#include "terminal.h"

short Menu() {
    short chose = 0;
    bool wrong = false;
    string wrongString = "";

    MoveCursorTo(0, 27);
    cout << "";

    while (true) {
        ClearTerminal();
        cout << "Press type of menu mode" << endl;
        cout << "1. New game setup;" << endl;
        cout << "2. Load game sutep file and start game;" << endl;
        cout << "3. Load last full game file; (Will work in next updates)" << endl;
        cout << "4. Exit." << endl;

        DrawInTerm(wrongString);

        cin >> chose;
        if (chose != 1 && chose != 2 && chose != 3 && chose != 4) {
            wrong = true;
        } else {
            wrong = false;
            break;
        }
    }

    return chose;
}