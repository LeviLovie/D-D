#ifndef subGame_h
#define subGame_h

#include <iostream>

class Player {
    public:
        short health;
        short type;
        std::string name;
        std::string inventory[16];
        Player();
        Player(
            short health,
            short type,
            std::string name,
            std::string inventory[16]
        );
};

void WriteGameInfo(short startRoom, short countOfPlayers, Player players[16], std::string saveFile);
void SeeSaves();

#endif