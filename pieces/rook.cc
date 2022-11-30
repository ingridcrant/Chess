#include "rook.h"

Rook::Rook(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos) : Piece{colour, symbol, board, pos, INFINITE, false} {
    directions.push_back(UP);
    directions.push_back(DOWN);
    directions.push_back(LEFT);
    directions.push_back(RIGHT);
    generateNextPositions();
}

void Rook::generateNextPositions() {
    // TO DO:
    // 1. castling
    for (Direction d : directions) {
        std::vector<Position> nextPositionsInD = this->allPosInDirection(d);
        nextPositions.insert(nextPositions.end(), nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
