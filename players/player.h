#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "../shared.h"

class Player {
    Colour colour;
    bool check;
    bool checkmate;

    public:
        Player(Colour colour);
        virtual ~Player() = 0;
};


#endif

