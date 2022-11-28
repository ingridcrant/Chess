#ifndef COMP_H
#define COMP_H

#include "player.h"
#include "shared.h"

class Computer : public Player {

    public:
    Computer(Colour colour, bool check, bool checkmate);
    virtual ~Computer() = 0;

};

class LevelOne : public Computer {

    public:
    LevelOne(Colour colour, bool check, bool checkmate);
    ~LevelOne() = default;
};

#endif

