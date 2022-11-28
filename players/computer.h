#ifndef COMP_H
#define COMP_H

#include "player.h"

class Computer : public Player {

    public:
    Computer(int colour, bool check, bool checkmate);
    virtual ~Computer() = 0;

};

class LevelOne : public Computer {

    public:
    LevelOne(int colour, bool check, bool checkmate);
    ~LevelOne() = default;
};

#endif

