#ifndef COMP_H
#define COMP_H

#include "playerImpl.h"

class Board;

class Computer : public PlayerImpl {

    protected:
        Board * board;

    public:
        Computer(Board * board): board{board} {}
        ~Computer() = default;
        virtual Move chooseMove() = 0;
};

#endif
