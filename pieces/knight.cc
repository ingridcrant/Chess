#include "knight.h"

Knight::Knight(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos) : Piece{colour, symbol, board, pos, INFINITE, false}{
    directions.push_back(KNIGHT_DOWN_LEFT);
    directions.push_back(KNIGHT_DOWN_RIGHT);
    directions.push_back(KNIGHT_UP_LEFT);
    directions.push_back(KNIGHT_UP_RIGHT);
    generateNextPositions();
}

void Knight::generateNextPositions() {
    for (Direction d : directions) {
        std::vector<Position> nextPositionsInD = this->allPosInDirection(d);
        nextPositions.insert(nextPositions.end(), nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
