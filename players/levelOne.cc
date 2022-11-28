#include "computer.h"

Computer::Computer(int colour, bool check, bool checkmate): Player(colour, check, checkmate) {}

LevelOne::LevelOne(int colour, bool check, bool checkmate): Computer(colour, check, checkmate) {}

