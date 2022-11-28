#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "../shared.h"

class Player {
    bool check;
    bool checkmate;
    int colour;

    public:
        Player(Colour colour, bool check, bool checkmate);
        virtual ~Player() = 0;
};


#endif

