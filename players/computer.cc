#include "computer.h"
#include "../pieces/board.h"


Computer::Computer(Colour colour, Board * board): Player{colour}, board{board} {}

