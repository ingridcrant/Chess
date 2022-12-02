#include "computer.h"
#include "player.h"

Computer::~Computer() {}
Computer::Computer(Colour colour): Player{colour} {}