#include "king.h"

King::King(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, ONE, false} {
    directions.push_back(UP);
    directions.push_back(DOWN);
    directions.push_back(LEFT);
    directions.push_back(RIGHT);
    directions.push_back(LEFT_UP_DIAGONAL);
    directions.push_back(LEFT_DOWN_DIAGONAL);
    directions.push_back(RIGHT_UP_DIAGONAL);
    directions.push_back(RIGHT_DOWN_DIAGONAL);
}

void King::generateNextPositions(Board* board) {
    // TO DO:
    // 1. remove positions that put King in check
    // 2. castling

    std::map<Position, MoveTypes> nextPossibleMoves;
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, board);
        nextPossibleMoves.insert(nextPositionsInD.begin(), nextPositionsInD.end());
    }

    // 1 - removing positions that put King in check
    Colour opposingColour = (colour == WHITE) ? BLACK : WHITE;

    for (int r = 0; r < board->getRows(); r++) {
        for (int c = 0; c < board->getCols(); c++) {
            Piece* nextPiece = board->getPieceAt(r, c);
            if (nextPiece != nullptr && nextPiece->getColour() == opposingColour) {
                for (auto nextPossibleMove : nextPossibleMoves) {
                    if (nextPiece->getNextPositions().find(nextPossibleMove.first) != nextPiece->getNextPositions().end()) {
                        nextPossibleMoves.erase(nextPossibleMove.first);
                    }
                }
            }
        }
    }

    nextPositions.insert(nextPossibleMoves.begin(), nextPossibleMoves.end());
}
