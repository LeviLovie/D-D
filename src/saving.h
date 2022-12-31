#ifndef saving_h
#define saving_h

#include <iostream>
#include "subGame.h"

void SavePreGame(std::string saveFile, short startRoom, short countOfPlayers, Player players[]);
Player LoadPlayer(std::string filename, short playerNumber);

#endif