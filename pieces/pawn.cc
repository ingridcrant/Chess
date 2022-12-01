#include "pawn.h"

Pawn::Pawn(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, ONE, true}, skipsTwo(false) {
    directions.push_back(UP);
}

bool Pawn::getSkipsTwo() { 
    return skipsTwo;
}

void Pawn::generateNextPositions(Board* board) {
    // TO DO:
    // 1. skips two move - DONE
    // 2. en passant - DONE

    // 1.
    if (firstMove) {
        Position skipTwo = Position{currPos.row + 2, currPos.col};
        if (colour == BLACK) {
            skipTwo.row = currPos.row - 2;
        }

        nextPositions.emplace_back(skipTwo);
    }

    // 2.
    char otherPawnSymbol = (colour == WHITE) ? 'p' : 'P';

    if (currPos.col > 0) {
        Piece* leftPiece = board->getPieceAt(currPos.row, currPos.col - 1);

        if (leftPiece != nullptr && leftPiece->getSymbol() == otherPawnSymbol && leftPiece->getSkipsTwo()) {
            Position enPassantLeft = Position{currPos.row, currPos.col - 1};
            nextPositions.emplace_back(enPassantLeft);
        }
    }

    if (currPos.col < board->getCols() - 1) {
        Piece* rightPiece = board->getPieceAt(currPos.row, currPos.col + 1);

        if (rightPiece != nullptr && rightPiece->getSymbol() == otherPawnSymbol && rightPiece->getSkipsTwo()) {
            Position enPassantRight = Position{currPos.row, currPos.col - 1};
            nextPositions.emplace_back(enPassantRight);
        }
    }

    for (Direction d : directions) {
        std::vector<Position> nextPositionsInD = this->allPosInDirection(d, board);
        nextPositions.insert(nextPositions.end(), nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
