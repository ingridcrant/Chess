#include "pawn.h"

Pawn::Pawn(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos) : Piece{colour, symbol, board, pos, ONE, true}, skipsTwo(false) {
    directions.push_back(UP);
    generateNextPositions();
}

void Pawn::generateNextPositions() {
    // TO DO:
    // 1. skips two move - DONE
    // 2. en passant
    if (firstMove) {
        Position skipTwo = Position{currPos.row + 2, currPos.col};
        if (colour == BLACK) {
            skipTwo.row = currPos.row - 2;
        }

        nextPositions.emplace_back(skipTwo);
    }

    for (Direction d : directions) {
        std::vector<Position> nextPositionsInD = this->allPosInDirection(d);
        nextPositions.insert(nextPositions.end(), nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
