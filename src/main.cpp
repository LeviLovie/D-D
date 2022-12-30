#include "terminal.h"
#include "menu.h"
#include "Game.h"

int main(int, char**) {
    ClearRAM();
    SetDefaultSizeOfTerminal();
    ClearTerminal();
    
    short menuMode = Menu();
    if (menuMode == 1) {
        short result = NewGame();
        if (result == 0) {
            ClearTerminal();
            MoveCursorTo(0, 0);
            CoutEndl("Starting new game ended not successfully. Please, try again, with another parameters.");
            CoutEndl("If it's don't help, please, wait for next update. :)");
            Exit(0);
        } else if (result == 1) {
            ClearTerminal();
            MoveCursorTo(0, 0);
            CoutEndl("Game ended successfully. I believe, you had a good time. :)");
            CoutEndl("Goodbye!");
            Exit(0);
        }
    }else if (menuMode == 2) {
        // Load game
    } else if (menuMode == 3) {
        ClearTerminal();
        MoveCursorTo(0, 0);
        CoutEndl("Goodbye!");
        Exit(0);
    }
}
