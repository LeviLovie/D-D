#ifndef commannds_h
#define commannds_h

#include <string>

#include "subGame.h"

void commHelp();
void commRoom(char room[25][120]);
void commRefresh();
void commPlayer(Player players[16], short intInput);
void commPlayers(Player players[16], short intInput);

#endif