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
        Colour getColour() {return colour;}
        bool getCheck() {return check;}
        bool getCheckmate() {return checkmate;}
};


#endif

