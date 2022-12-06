#ifndef PIECE_IMPL_H
#define PIECE_IMPL_H

#include <string>
#include "../shared.h"

class PlayerImpl {
    protected:
        Colour colour;

    public:
        PlayerImpl() {}
        virtual ~PlayerImpl() = default;
        void setColour(Colour colour) {this->colour = colour;}
        virtual Move chooseMove(Move* lastMove) = 0;
};



#endif

