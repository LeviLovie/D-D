#include <iostream>

#include "subGame.h"

Player :: Player() {}

Player :: Player(short health, short type, std::string name, std::string inventory[16]) {
    health = health;
    type = type;
    name = name;
    inventory = inventory;
}