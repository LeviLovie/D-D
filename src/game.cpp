#include "subGame.h"
#include <mutex>
#include <string>
#include <iostream>
using namespace std;

#include "terminal.h"
#include "subGame.h"
#include "saving.h"
#include "commands.h"

char room[25][120];

Player localPlayers[16];

short Start(string savename) {
    SetDefaultSizeOfTerminalForGame();
    ClearTerminalAndMoveCursorTo(0, 0);

    createRoom(room);
    for (short i = 0; i < 16; i++) {
        localPlayers[i] = LoadPlayer(savename, i);
    }

    string outputMessage = "Get list of commands with \"help\"";
    string input = "help";
    int intInput = 0;

    while (true) {
        ClearTerminal();
        MoveCursorTo(0, 0);

        if (input == "help") {
            ClearTerminalAndMoveCursorTo(0, 0);
            outputMessage = "Help message";
            commHelp();
        } else if (input == "room") {
            ClearTerminalAndMoveCursorTo(0, 0);
            outputMessage = "Local room";
            commRoom(room);
        } else if (input == "refresh") {
            outputMessage = "Clearing terminal, RAM and useless data...";
            ClearTerminalAndMoveCursorTo(0, 0);
            commRefresh();
        } else if (input == "player") {
            ClearTerminalAndMoveCursorTo(0, 0);
            outputMessage = "Whith player:";
            DrawInTerm(outputMessage);
            cin >> intInput;
            if (intInput > 16 || intInput < 1) {
                outputMessage = "Player number must be between 1 and 16. Infromation about player 1";
                intInput = 1;
            } else {
                outputMessage = "Information about player " + to_string(intInput);
            }
            ClearTerminalAndMoveCursorTo(0, 0);
            commPlayer(localPlayers, intInput);
        } else if (input == "players") {
            ClearTerminalAndMoveCursorTo(0, 0);
            outputMessage = "You are looking at players info";
            commPlayers(localPlayers, intInput);
        } else if (input == "end") {
            ClearTerminalAndMoveCursorTo(0, 0);
            outputMessage = "Are you sure you want to exit? (Y/n)";
            DrawInTerm(outputMessage);
            cin >> input;
            if (input == "Y") {
                return 1;
            }
        } else {
            ClearTerminalAndMoveCursorTo(0, 0);
            outputMessage = "You writed: \"" + input + "\", but this is not a command. It's a help message by \"help\" command";
        }

        DrawInTerm(outputMessage);
        cin >> input;
    }
    return 0;
}
