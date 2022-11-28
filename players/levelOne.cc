#include "computer.h"


Computer::Computer(int colour, bool check, bool checkmate): Player(colour, check, checkmate) {}

Computer::~Computer() {}

LevelOne::LevelOne(int colour, bool check, bool checkmate): Computer(colour, check, checkmate) {}

