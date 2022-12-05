#ifndef COMP_H
#define COMP_H

#include "player.h"

class Board;

class Computer : public Player {
    Board * board;

    public:
        Computer(Colour colour, Board * board);
        virtual ~Computer() = default;
        virtual Move chooseMove() = 0;

};
#endif

