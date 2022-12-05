#ifndef LEVELONE_H
#define LEVELONE_H

#include "computer.h"

class Board;

class LevelOne : public Computer {

    public:
        LevelOne(Board * board);
        ~LevelOne() = default;
        Move chooseMove() override;
};

#endif

