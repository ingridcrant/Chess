#include "pawn.h"

Pawn::Pawn(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, ONE, true}, skipsTwo(false) {
    directions.push_back(UP);
}

bool Pawn::getSkipsTwo() { 
    return skipsTwo;
}

void Pawn::generateNextPositions(Board* board) {
    nextPositions.clear();
    // TO DO:
    // 1. skips two move - DONE
    int dRow = (colour == BLACK) ? -1 : 1;
    if (firstMove) {
        Position skipTwo = Position{currPos.row, currPos.col + 2 * dx};
        if (board->getPos(skipTwo.row - dRow, skipTwo.col) == nullptr && board->getPos(skipTwo.row, skipTwo.col) == nullptr) {
            nextPositions[skipTwo] = SKIP_TWO;
        }
    }

    // 2. en passant

    // 3. regular motion
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, board);
        nextPositions.insert(nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
