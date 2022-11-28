#include "computer.h"

Computer::Computer(Colour colour, bool check, bool checkmate): Player(colour, check, checkmate) {}

LevelOne::LevelOne(Colour colour, bool check, bool checkmate): Computer(colour, check, checkmate) {}

