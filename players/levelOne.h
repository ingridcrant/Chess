#ifndef LEVELONE_H
#define LEVELONE_H

#include "computer.h"

class LevelOne : public Computer {

    public:
        LevelOne(Colour colour);
        ~LevelOne() = default;
        Move chooseMove();
};

#endif

