#include "levelOne.h"
#include "../shared.h"
#include "../pieces/board.h"


LevelOne::LevelOne(Colour colour, Board * board): Computer{colour, board} {}

//TODO
Move LevelOne::chooseMove() {
    //placeholder for now
    return Move{"a1 a2"};
}


