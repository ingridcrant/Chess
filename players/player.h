#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "../shared.h"

class PlayerImpl;

class Player {
    Colour colour;
    bool check;
    bool checkmate;
    PlayerImpl * behaviour;
    float wins;

    public:
        Player(Colour colour, PlayerImpl * behaviour);
        ~Player() = default;
        Colour getColour() {return colour;}
        bool getCheck() {return check;}
        bool getCheckmate() {return checkmate;}
        float getWins() {return wins;}
        void increaseWin(float num) {wins += num;}
        void setBehaviour(PlayerImpl * behaviour);
        Move chooseMove(Move* lastMove);
};


#endif

