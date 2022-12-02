#include "pawn.h"

Pawn::Pawn(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, ONE, true}, skipsTwo(false) {
    directions.push_back(UP);
}

bool Pawn::getSkipsTwo() { 
    return skipsTwo;
}

void Pawn::generateNextPositions(Board* board) {
    // TO DO:
    // 1. skips two move - DONE
    // 2. en passant

    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, board);
        nextPositions.insert(nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
