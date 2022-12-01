#include "bishop.h"

Bishop::Bishop(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos) : Piece{colour, symbol, board, pos, INFINITE, false} {
    directions.push_back(LEFT_UP_DIAGONAL);
    directions.push_back(LEFT_DOWN_DIAGONAL);
    directions.push_back(RIGHT_UP_DIAGONAL);
    directions.push_back(RIGHT_DOWN_DIAGONAL);
    generateNextPositions();
}

void Bishop::generateNextPositions() {
    for (Direction d : directions) {
        std::vector<Position> nextPositionsInD = this->allPosInDirection(d);
        nextPositions.insert(nextPositions.end(), nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
