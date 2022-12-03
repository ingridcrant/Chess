#ifndef COMP_H
#define COMP_H

#include "player.h"

class Computer : public Player {

    public:
        Computer(Colour colour);
        virtual ~Computer() = default;
        virtual Move chooseMove() = 0;

};
#endif

