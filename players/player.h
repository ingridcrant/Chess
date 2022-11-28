#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    bool check;
    bool checkmate;
    int colour;

    public:
        enum {White=0, Black};
        Player(int colour, bool check, bool checkmate);
        virtual ~Player() = 0;
};


#endif

