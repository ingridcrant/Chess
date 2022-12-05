#include "human.h"
#include "../pieces/board.h"
#include <iostream>

Human::Human(): PlayerImpl{} {}

Move Human::chooseMove() {
    std::string move;
    getline(std::cin, move);
    return Move{move};
}



