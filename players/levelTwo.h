#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "computer.h"

class LevelTwo : public Computer {

    public:
        LevelTwo(Colour colour);
        ~LevelTwo() = default;
        Move chooseMove() override;
};

#endif


