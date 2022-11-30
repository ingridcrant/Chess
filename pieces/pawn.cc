#include "pawn.h"

Pawn::Pawn(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos) : Piece{colour, symbol, board, pos, ONE, true}, skipsTwo(false) {
    directions.push_back(UP);
    generateNextPositions();
}

void Pawn::generateNextPositions() {
    // TO DO:
    // 1. skips two move
    // 2. en passant
    for (Direction d : directions) {
        std::vector<Position> nextPositionsInD = this->allPosInDirection(d);
        nextPositions.insert(nextPositions.end(), nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
