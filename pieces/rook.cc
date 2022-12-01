#include "rook.h"

Rook::Rook(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, INFINITE, false} {
    directions.push_back(UP);
    directions.push_back(DOWN);
    directions.push_back(LEFT);
    directions.push_back(RIGHT);
}

void Rook::generateNextPositions(Board* board) {
    // TO DO:
    // 1. castling
    for (Direction d : directions) {
        std::vector<Position> nextPositionsInD = this->allPosInDirection(d, board);
        nextPositions.insert(nextPositions.end(), nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
