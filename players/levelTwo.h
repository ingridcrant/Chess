#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "computer.h"

class Board;

class LevelTwo : public Computer {

    public:
        LevelTwo(Colour colour, Board * board);
        ~LevelTwo() = default;
        Move chooseMove() override;
};

#endif


