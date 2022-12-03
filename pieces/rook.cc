#include "rook.h"

Rook::Rook(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, INFINITE, false} {
    directions.push_back(UP);
    directions.push_back(DOWN);
    directions.push_back(LEFT);
    directions.push_back(RIGHT);
}

void Rook::generateNextPositions(Board* board, Move lastMove) {
    nextPositions.clear();
    // TO DO:
    // 1. castling
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, lastMove, board);
        nextPositions.insert(nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
