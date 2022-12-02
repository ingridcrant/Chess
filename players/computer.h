#ifndef COMP_H
#define COMP_H

#include "player.h"

class Computer : public Player {

    public:
    Computer(Colour colour);
    virtual ~Computer() = 0;

};

class LevelOne : public Computer {

    public:
    LevelOne(Colour colour);
    ~LevelOne() = default;
};

#endif

