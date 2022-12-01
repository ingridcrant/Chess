#include "knight.h"

Knight::Knight(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, INFINITE, false} {
    directions.push_back(KNIGHT_DOWN_LEFT);
    directions.push_back(KNIGHT_DOWN_RIGHT);
    directions.push_back(KNIGHT_UP_LEFT);
    directions.push_back(KNIGHT_UP_RIGHT);
}

void Knight::generateNextPositions(Board* board) {
    for (Direction d : directions) {
        std::vector<Position> nextPositionsInD = this->allPosInDirection(d, board);
        nextPositions.insert(nextPositions.end(), nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
