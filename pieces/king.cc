#include "king.h"

King::King(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos) : Piece{colour, symbol, board, pos, ONE, false} {
    directions.push_back(UP);
    directions.push_back(DOWN);
    directions.push_back(LEFT);
    directions.push_back(RIGHT);
    directions.push_back(LEFT_UP_DIAGONAL);
    directions.push_back(LEFT_DOWN_DIAGONAL);
    directions.push_back(RIGHT_UP_DIAGONAL);
    directions.push_back(RIGHT_DOWN_DIAGONAL);
    generateNextPositions();
}

void King::generateNextPositions() {
    // TO DO:
    // 1. remove positions that put King in check
    // 2. castling
    for (Direction d : directions) {
        std::vector<Position> nextPositionsInD = this->allPosInDirection(d);
        nextPositions.insert(nextPositions.end(), nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
