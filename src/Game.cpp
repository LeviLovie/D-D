#include "subGame.h"
#include <mutex>
#include <string>
#include <iostream>
using namespace std;

#include "terminal.h"
#include "subGame.h"
#include "saving.h"

char room[25][120];

void createRoom() {
    for (short i = 0; i < 25; i++) {
        for (short j = 0; j < 120; j++) {
            room[i][j] = ' ';
        }
    }
    for (short i = 0; i < 25; i++) {
        if (i > 3 && i < 21) {
            room[i][3] = '|';
            room[i][116] = '|';
        }
    }
    for (short i = 0; i < 120; i++) {
        if (i > 3 && i < 116) {
            room[3][i] = '-';
            room[21][i] = '-';
        }
    }
    room[3][3] = '+';
    room[3][116] = '+';
    room[21][3] = '+';
    room[21][116] = '+';
    // for (short i = 4; i < 21; i++) {
    //     for (short j = 4; j < 116; j++) {
    //         room[i][j] = ' ';
    //     }
    // }
}

Player localPlayers[16];

short Start(string savename) {
    SetDefaultSizeOfTerminalForGame();
    ClearTerminal();
    MoveCursorTo(0, 0);

    createRoom();
    for (short i = 0; i < 16; i++) {
        localPlayers[i] = LoadPlayer(savename, i);
    }

    string outputMessage = "Commands: refresh, help, room, player, players, end";
    string input = "";
    int intInput = 0;
    string output = "room";
    short playerNUmber = 1;
    string playerTypes[5] = {"Not playing", "Warrior", "Mage", "Archer", "Scientist"};
    string splitedInput[256];
    while (true) {
        ClearTerminal();
        MoveCursorTo(0, 0);
        if (output == "help") {
            cout << "Commands:" << endl;
            cout << "    help - show this message;" << endl;
            cout << "    room - show room;" << endl;
            cout << "    player - show player info;" << endl;
            cout << "    players - show info about all players;" << endl;
            cout << "    end - end game without saving;" << endl;
            cout << "    refresh - clear RAM, clear terminal, clear useless data." << endl;
        } else if (output == "room") {
            for (short i = 0; i < 25; i++) {
                for (short j = 0; j < 120; j++) {
                    cout << room[i][j];
                }
                cout << endl;
            }
        } else if (output == "refresh") {
            ClearTerminal();
            MoveCursorTo(0, 0);

            cout << "\e[3J";
            cout << "Clearing Terminal..." << endl;

            cout << "Clearing RAM..."  << endl;
            ClearRAM();

            cout << "Clearing useless data..." << endl;
            
            cout << "Done!" << endl;
        } else if (output == "player") {
            ClearTerminal();
            MoveCursorTo(0, 0);

            cout << "Name: " << localPlayers[intInput].name << endl;
            cout << "Health: " << localPlayers[intInput].health << endl;
            cout << "Type: " << playerTypes[localPlayers[intInput].type] << endl;
            cout << "Inventory: " << endl;
            for (short i = 0; i < 16; i++) {
                cout << "    " << localPlayers[intInput].inventory[i] << endl;
            }
        }  else if (output == "players") {
            ClearTerminal();
            MoveCursorTo(0, 0);

            cout << "Name: " << localPlayers[0].name;
            cout << "    " << "Name: " << localPlayers[1].name;
            cout << "    " << "Name: " << localPlayers[2].name;
            cout << "    " << "Name: " << localPlayers[3].name << endl;

            cout << "Health: " << localPlayers[intInput].health;
            cout << "    " << "Health: " << localPlayers[intInput].health;
            cout << "    " << "Health: " << localPlayers[intInput].health;
            cout << "    " << "Health: " << localPlayers[intInput].health << endl;

            cout << "Type: " << playerTypes[localPlayers[intInput].type];
            cout << "    " << "Type: " << playerTypes[localPlayers[intInput].type];
            cout << "    " << "Type: " << playerTypes[localPlayers[intInput].type];
            cout << "    " << "Type: " << playerTypes[localPlayers[intInput].type] << endl;
            
            // cout << "Inventory: " << endl;
            // for (short i = 0; i < 16; i++) {
            //     cout << "    " << localPlayers[intInput].inventory[i] << endl;
            // }
        }

        DrawInTerm(outputMessage);
        cin >> input;
        splitedInput[0] = input.substr(0, input.find(" "));
        if (splitedInput[0] == "help") {
            ClearTerminal();
            MoveCursorTo(0, 0);
            output = "help";
            outputMessage = "You are looking at help";
            DrawInTerm(outputMessage);
        } else if (splitedInput[0] == "room") {
            ClearTerminal();
            MoveCursorTo(0, 0);
            output = "room";
            outputMessage = "You are looking at room";
        } else if (splitedInput[0] == "refresh") {
            ClearTerminal();
            MoveCursorTo(0, 0);
            output = "refresh";
        } else if (splitedInput[0] == "player") {
            ClearTerminal();
            MoveCursorTo(0, 0);
            outputMessage = "Whith player:";
            DrawInTerm(outputMessage);
            cin >> intInput;
            if (intInput > 16 || intInput < 1) {
                outputMessage = "Player number must be between 1 and 16, will choose player 1. You are looking at inventory of player 1";
                intInput = 1;
            } else {
                outputMessage = "You are looking at info of player " + to_string(intInput);
            }
            output = "player";
        } else if (splitedInput[0] == "players") {
            ClearTerminal();
            MoveCursorTo(0, 0);
            output = "players";
            outputMessage = "You are looking at players info";
        } else if (splitedInput[0] == "end") {
            ClearTerminal();
            MoveCursorTo(0, 0);
            outputMessage = "Are you sure you want to exit? (Y/n)";
            DrawInTerm(outputMessage);
            cin >> input;
            if (input == "Y") {
                return 1;
            }
        } else {
            ClearTerminal();
            MoveCursorTo(0, 0);
            output = "help";
            outputMessage = "You writed: \"" + input + "\", but this is not a command. It's a help message by \"help\" command";
            DrawInTerm(outputMessage);
        }
        // if (input != "room" && input != "player" && input != "end") {
        //     outputMessage = "Commands: room, player, end";
        // } else {
        //     if (input == "room") {
        //         outputMessage = "You are in the room";
        //     } else if (input == "player") {
        //     } else if (input == "end") {
        //         outputMessage = "Are you sure you want to exit? (Y/n)";
        //         DrawInTerm(outputMessage);
        //         cin >> input;
        //         if (input == "Y") {
        //             return 1;
        //         }
        //     }
        //     outputMessage = "";
        //     output = input;
        // }

        // Draw inventory representation
        // Draw output representation
        // Draw input representation
        // break;
    }

    // cout << "Press any key to exit:" << endl;
    // cin >> StringTrash;
    return 0;
}