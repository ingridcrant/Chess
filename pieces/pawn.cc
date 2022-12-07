#include "pawn.h"
#include <iostream>

Pawn::Pawn(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, ONE, true}, skipsTwo(false) {
    directions.push_back(PAWN_UP);
}

bool Pawn::getSkipsTwo() { 
    return skipsTwo;
}

void Pawn::setSkipsTwo(bool val) {
    skipsTwo = val;
}

void Pawn::generateNextPositions(std::vector<std::vector<Piece*>> board, int rows, int cols, Move* lastMove, bool checkIfKingInCheck) {
    nextPositions.clear();
    // TO DO:
    // 1. skips two move - DONE
    int dRow = (colour == BLACK) ? -1 : 1;
//    for (int r = rows - 1; r >= 0; r--) {
//        for (int c = 0; c < cols; c++) {
//            if (board[r][c]) std::cout << board[r][c]->getSymbol();
//            else std::cout << "_";
//        }
//        std::cout << std::endl;
//    }
    if (firstMove) {
        Position skipTwo = Position{currPos.row + 2 * dRow, currPos.col};
        if (!board[skipTwo.row - dRow][skipTwo.col] && !board[skipTwo.row][skipTwo.col]) {
            if (checkIfKingInCheck) {
                if (!movePutsKingInCheck(board, lastMove, rows, cols, skipTwo)) nextPositions[skipTwo] = SKIP_TWO;
            } else {
                nextPositions[skipTwo] = SKIP_TWO;
            }
        }
    }

    // 2. en passant - DONE
    char opponentPawn = (colour == BLACK) ? 'P' : 'p';
    int opponentDRow = (colour == BLACK) ? 1 : -1;
    /*if (lastMove && lastMove->getNewPos().row == 4 && lastMove->getNewPos().col == 3) {
        std::cout << "HELLO1 " << lastMove->getPiece()->getSymbol() << std::endl;
    }*/
    if (lastMove && lastMove->getPiece()->getSymbol() == opponentPawn && lastMove->getPiece()->getCount() == 1 && lastMove->getPiece()->getSkipsTwo()) {
        Position opponentPawnPos = lastMove->getPiece()->getPos();
        if (opponentPawnPos.col == currPos.col - 1) {
            if (opponentPawnPos.row == currPos.row) {
                Position enPassant = Position{opponentPawnPos.row - opponentDRow, opponentPawnPos.col};

                // checking that en passant doesn't put king in check
                Piece* capturedPiece = board[opponentPawnPos.row][opponentPawnPos.col];
                board[opponentPawnPos.row][opponentPawnPos.col] = nullptr;

                if (checkIfKingInCheck) {
                    if (!movePutsKingInCheck(board, lastMove, rows, cols, enPassant)) {
                        nextPositions[std::move(enPassant)] = EN_PASSANT;
                    }
                } else {
                    nextPositions[std::move(enPassant)] = EN_PASSANT;
                }

                board[opponentPawnPos.row][opponentPawnPos.col] = capturedPiece;
            }
        } else if (opponentPawnPos.col == currPos.col + 1) {
            if (opponentPawnPos.row == currPos.row) {
                Position enPassant = Position{opponentPawnPos.row - opponentDRow, opponentPawnPos.col};

                // checking that en passant doesn't put king in check
                Piece* capturedPiece = board[opponentPawnPos.row][opponentPawnPos.col];
                board[opponentPawnPos.row][opponentPawnPos.col] = nullptr;

                if (checkIfKingInCheck) {
                    if (!movePutsKingInCheck(board, lastMove, rows, cols, enPassant)) nextPositions[std::move(enPassant)] = EN_PASSANT;
                } else {
                    nextPositions[std::move(enPassant)] = EN_PASSANT;
                }

                board[opponentPawnPos.row][opponentPawnPos.col] = capturedPiece;
            }
        }
    }

    // 3. regular motion
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = std::move(this->allPosInDirection(d, lastMove, rows, cols, board, checkIfKingInCheck));
        for (auto pair : nextPositionsInD) {
            nextPositions[std::move(pair.first)] = pair.second;
        }
    }
}
