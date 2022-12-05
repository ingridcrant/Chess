#include "bishop.h"

Bishop::Bishop(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, INFINITE, false} {
    directions.push_back(LEFT_UP_DIAGONAL);
    directions.push_back(LEFT_DOWN_DIAGONAL);
    directions.push_back(RIGHT_UP_DIAGONAL);
    directions.push_back(RIGHT_DOWN_DIAGONAL);
}

void Bishop::generateNextPositions(std::vector<std::vector<Piece*>> board, int rows, int cols, Move* lastMove, bool checkIfKingInCheck) {
    nextPositions.clear();
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, lastMove, rows, cols, board, checkIfKingInCheck);
        for (auto pair : nextPositionsInD) {
            nextPositions[pair.first] = pair.second;
        }
    }
}
