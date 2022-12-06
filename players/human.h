#ifndef HUMAN_H
#define HUMAN_H

#include "../shared.h"
#include "playerImpl.h"

class Human : public PlayerImpl {
    public:
        Human();
        ~Human() = default;
        Move chooseMove(Move* lastMove) override;
};

#endif
