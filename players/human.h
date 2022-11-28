#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player {

    public:
    Human(int colour, bool check, bool checkmate);
    ~Human() = default;


};

#endif
