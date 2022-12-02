#include "knight.h"

Knight::Knight(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, INFINITE, false} {
    directions.push_back(KNIGHT_DOWN_LEFT);
    directions.push_back(KNIGHT_DOWN_RIGHT);
    directions.push_back(KNIGHT_UP_LEFT);
    directions.push_back(KNIGHT_UP_RIGHT);
}

void Knight::generateNextPositions(Board* board, Move lastMove) {
    nextPositions.clear();
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, board);
        nextPositions.insert(nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
