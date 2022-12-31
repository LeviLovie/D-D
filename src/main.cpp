#include <iostream>

#include "terminal.h"
#include "menu.h"
#include "gameSetup.h"
#include "game.h"

int main(int, char**) {
    ClearRAM();
    SetDefaultSizeOfTerminalForSetup();
    ClearTerminal();
    
    short menuMode = Menu();
    if (menuMode == 1) {
        short result = NewGame();
        if (result == 0) {
            ClearTerminal();
            MoveCursorTo(0, 0);
            std::cout << "Setup new game ended not successfully. Please, try again, with another parameters." << std::endl;
            std::cout << "If it's don't help, please, wait for next update. :)" << std::endl;
            Exit(0);
        } else if (result == 1) {
            ClearTerminal();
            MoveCursorTo(0, 0);
            std::cout << "Setup new game ended successfully. You can run again, and chose 2th option, for loading game." << std::endl;
            Exit(0);
        }
    } else if (menuMode == 2) {
        std::string loadfile = GetSave();
        short result = Start(loadfile);
        if (result == 0) {
            ClearTerminal();
            MoveCursorTo(0, 0);
            std::cout << "Starting new game ended not successfully. Please, try again, with another parameters." << std::endl;
            std::cout << "If it's don't help, please, wait for next update. :)" << std::endl;
            Exit(0);
        } else if (result == 1) {
            ClearTerminal();
            MoveCursorTo(0, 0);
            std::cout << "Game ended successfully. I believe, you had a good time. :)" << std::endl;
            std::cout << "Goodbye!" << std::endl;
            Exit(0);
        }
    } else if (menuMode == 3) {
        ClearTerminal();
        MoveCursorTo(0, 0);
        CoutEndl("Soon... :)");
        Exit(0);
    } else if (menuMode == 4) {
        ClearTerminal();
        MoveCursorTo(0, 0);
        CoutEndl("Goodbye!");
        Exit(0);
    }
}
