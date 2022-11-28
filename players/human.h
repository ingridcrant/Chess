#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player {
    public:
        Human(Colour colour, bool check, bool checkmate);
        ~Human() = default;
};

#endif
