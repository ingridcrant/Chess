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

bool King::getInCheck() {
    return inCheck;
}

void King::setInCheck(bool val) {
    inCheck = val;
}

void King::generateNextPositions(std::vector<std::vector<Piece*>> board, int rows, int cols, Move* lastMove, bool checkIfKingInCheck) {
    nextPositions.clear();
    // TO DO:
    // 1. remove positions that put King in check - DONE
    // 2. castling - DONE

    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, lastMove, rows, cols, board, checkIfKingInCheck);
        for (auto pair : nextPositionsInD) {
            nextPositions[pair.first] = pair.second;
        }
    }

    // 2 - castling
    //     NOTE: can only handling castling in normal board setup
    int endRow = (colour == BLACK) ? 7 : 0;
    if (checkIfKingInCheck && firstMove && !inCheck && currPos.row == endRow && currPos.col == 4) {
        int dCol = (colour == BLACK) ? -1 : 1;
        char rookTarget = (colour == BLACK) ? 'r' : 'R';
        
        // castle right
        Piece* rightCornerPiece = board[currPos.row][currPos.col + 3 * dCol];
        bool noPiecesBetween = (!board[currPos.row][currPos.col + dCol] && !board[currPos.row][currPos.col + 2 * dCol]);
        if (rightCornerPiece && noPiecesBetween && rightCornerPiece->getFirstMove() && rightCornerPiece->getSymbol() == rookTarget) {
            bool noChecksInBetween = (!movePutsKingInCheck(board, lastMove, rows, cols, Position{currPos.row, currPos.col + dCol}) && !movePutsKingInCheck(board, lastMove, rows, cols, Position{currPos.row, currPos.col + 2 * dCol}));
            if (noChecksInBetween) {
                nextPositions[Position{currPos.row, currPos.col + 2 * dCol}] = CASTLE_RIGHT;
            }
        }

        // castle left
        Piece* leftCornerPiece = board[currPos.row][currPos.col - 4 * dCol];
        noPiecesBetween = (!board[currPos.row][currPos.col - dCol] && !board[currPos.row][currPos.col - 2 * dCol] && !board[currPos.row][currPos.col - 3 * dCol]);
        if (leftCornerPiece && noPiecesBetween && leftCornerPiece->getFirstMove() && leftCornerPiece->getSymbol() == rookTarget) {
            bool noChecksInBetween = (!movePutsKingInCheck(board, lastMove, rows, cols, Position{currPos.row, currPos.col - dCol}) && !movePutsKingInCheck(board, lastMove, rows, cols, Position{currPos.row, currPos.col - 2 * dCol}));
            if (noChecksInBetween) {
                nextPositions[Position{currPos.row, currPos.col - 2 * dCol}] = CASTLE_LEFT;
            }
        }
    }
}
