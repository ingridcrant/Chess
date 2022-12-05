#include "knight.h"
#include <iostream>

Knight::Knight(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, INFINITE, false} {
    directions.push_back(KNIGHT_DOWN_LEFT);
    directions.push_back(KNIGHT_DOWN_RIGHT);
    directions.push_back(KNIGHT_UP_LEFT);
    directions.push_back(KNIGHT_UP_RIGHT);
}

void Knight::generateNextPositions(std::vector<std::vector<Piece*>> board, int rows, int cols, Move* lastMove, bool checkIfKingInCheck) {
    nextPositions.clear();
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, lastMove, rows, cols, board, checkIfKingInCheck);
        for (auto pair : nextPositionsInD) {
            nextPositions[pair.first] = pair.second;
        }
    }
}
