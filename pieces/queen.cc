#include "queen.h"

Queen::Queen(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, INFINITE, false} {
    directions.push_back(UP);
    directions.push_back(DOWN);
    directions.push_back(LEFT);
    directions.push_back(RIGHT);
    directions.push_back(LEFT_UP_DIAGONAL);
    directions.push_back(LEFT_DOWN_DIAGONAL);
    directions.push_back(RIGHT_UP_DIAGONAL);
    directions.push_back(RIGHT_DOWN_DIAGONAL);
}

void Queen::generateNextPositions(Board* board) {
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, board);
        nextPositions.insert(nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
