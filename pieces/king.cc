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
    nextPositions.clear();
    // TO DO:
    // 1. remove positions that put King in check - DONE
    // 2. castling - DONE

    std::map<Position, MoveTypes> nextPossibleMoves;
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, board);
        nextPossibleMoves.insert(nextPositionsInD.begin(), nextPositionsInD.end());
    }

    // 2 - castling
    //     NOTE: can only handling castling in normal board setup
    int endRow = (colour == BLACK) ? 7 : 0;
    if (firstMove && !inCheck && currPos.row == endRow && currPos.col == 4) {
        int dCol = (colour == BLACK) ? -1 : 1;
        char rookTarget = (colour == BLACK) ? 'r' : 'R';

        // castle right
        Piece* rightCornerPiece = board->getPieceAt(currPos.row, currPos.col + 3 * dCol);
        bool noPiecesBetween = (board->getPieceAt(currPos.row, currPos.col + dCol) == nullptr && board->getPieceAt(currPos.row, currPos.col + 2 * dCol) == nullptr);
        if (rightCornerPiece != nullptr && noPiecesBetween && leftCornerPiece->getFirstMove() && leftCornerPiece->getSymbol() == rookTarget) {
            bool noChecksInBetween = (!inCheck(Position{currPos.row, currPos.col + dCol}) && !inCheck(Position{currPos.row, currPos.col + 2 * dCol}));
            if (noChecksInBetween) {
                nextPossibleMoves[Position{currPos.row, currPos.col + 3 * dCol}] = CASTLE_RIGHT;
            }
        }

        // castle left
        Piece* leftCornerPiece = board->getPieceAt(currPos.row, currPos.col - 4 * dCol);
        noPiecesBetween = (board->getPieceAt(currPos.row, currPos.col - dCol) == nullptr && board->getPieceAt(currPos.row, currPos.col - 2 * dCol) == nullptr);
        if (leftCornerPiece != nullptr && noPiecesBetween && leftCornerPiece->getFirstMove() && leftCornerPiece->getSymbol() == rookTarget) {
            bool noChecksInBetween = (!inCheck(Position{currPos.row, currPos.col - dCol}) && !inCheck(Position{currPos.row, currPos.col - 2 * dCol}s));
            if (noChecksInBetween) {
                nextPossibleMoves[Position{currPos.row, currPos.col - 3 * dCol}] = CASTLE_LEFT;
            }
        }
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

bool King::inCheck(Board* board, Position pos) {
    Colour opposingColour = (colour == WHITE) ? BLACK : WHITE;

    for (int r = 0; r < board->getRows(); r++) {
        for (int c = 0; c < board->getCols(); c++) {
            Piece* nextPiece = board->getPieceAt(r, c);
            if (nextPiece != nullptr && nextPiece->getColour() == opposingColour) {
                for (auto nextPossibleMove : nextPossibleMoves) {
                    if (nextPiece->getNextPositions().find(pos) != nextPiece->getNextPositions().end()) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
