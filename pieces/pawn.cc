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

    // 1.
    if (firstMove) {
        Position skipTwo = Position{currPos.row + 2, currPos.col};
        if (colour == BLACK) {
            skipTwo.row = currPos.row - 2;
        }

        nextPositions.emplace_back(skipTwo);
    }

    for (Direction d : directions) {
        std::vector<Position> nextPositionsInD = this->allPosInDirection(d, board);
        nextPositions.insert(nextPositions.end(), nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
