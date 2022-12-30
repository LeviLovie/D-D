#ifndef newGameGetters_h
#define newGameGetters_h

#include <iostream>

#include "subGame.h"

short getStartRoom();
short getCountOfPlayers();
Player getPlayer(short playerNumber);
std::string getSaveFileName();

#endif