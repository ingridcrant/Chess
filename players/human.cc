#include "human.h"
#include <iostream>

Human::Human(Colour colour): Player(colour) {}

Move Human::chooseMove() {
    std::string move;
    std::cin >> move;
    return Move{move};
}



