#include "rook.h"
#include <iostream>

Rook::Rook(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, INFINITE, false} {
    directions.push_back(UP);
    directions.push_back(DOWN);
    directions.push_back(LEFT);
    directions.push_back(RIGHT);
}

void Rook::generateNextPositions(std::vector<std::vector<Piece*>> board, int rows, int cols, Move* lastMove, bool checkIfKingInCheck) {
    nextPositions.clear();
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, lastMove, rows, cols, board, checkIfKingInCheck);
        for (auto pair : nextPositionsInD) {
            nextPositions[pair.first] = pair.second;
        }
    }
}
