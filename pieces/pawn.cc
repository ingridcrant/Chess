#include "pawn.h"

Pawn::Pawn(Colour colour, char symbol, Position pos) : Piece{colour, symbol, pos, ONE, true}, skipsTwo(false) {
    directions.push_back(PAWN_UP);
}

bool Pawn::getSkipsTwo() { 
    return skipsTwo;
}

void Pawn::generateNextPositions(Board* board, Move lastMove) {
    nextPositions.clear();
    // TO DO:
    // 1. skips two move - DONE
    int dRow = (colour == BLACK) ? -1 : 1;
    if (firstMove) {
        Position skipTwo = Position{currPos.row, currPos.col + 2 * dRow};
        if (board->getPieceAt(skipTwo.row - dRow, skipTwo.col) == nullptr && board->getPieceAt(skipTwo.row, skipTwo.col) == nullptr && !movePutsKingInCheck(board, lastMove, skipTwo)) {
            nextPositions[skipTwo] = SKIP_TWO;
        }
    }

    // 2. en passant - DONE
    char opponentPawn = (colour == BLACK) ? 'p' : 'P';
    int opponentDCol = (colour == BLACK) ? 1 : -1;
    if (lastMove.getPiece()->getSymbol() == opponentPawn && lastMove.getPiece()->getSkipsTwo()) {
        Position opponentPawnPos = lastMove.getPiece()->getPos();
        if (opponentPawnPos.col - 1 == currPos.col) {
            if (opponentPawnPos.row == currPos.row) {
                Position enPassant = Position{opponentPawnPos.row - opponentDCol, opponentPawnPos.col - 1};

                // checking that en passant doesn't put king in check
                std::unique_ptr<Piece> capturedPiece {std::move(board->getPieceAt(opponentPawnPos.row, opponentPawnPos.col))};
                board->changeBoard(capturedPiece->getPos());
                if (movePutsKingInCheck(board, lastMove, enPassant)) {
                    nextPositions[enPassant] = EN_PASSANT;
                }

                board->changeBoard(capturedPiece->getSymbol(), opponentPawnPos);
            }
        } else if (opponentPawnPos.col + 1 == currPos.col) {
            if (opponentPawnPos.row == currPos.row) {
                Position enPassant = Position{opponentPawnPos.row - opponentDCol, opponentPawnPos.col + 1};

                // checking that en passant doesn't put king in check
                std::unique_ptr<Piece> capturedPiece {std::move(board->getPieceAt(opponentPawnPos.row, opponentPawnPos.col))};
                board->changeBoard(capturedPiece->getPos());
                if (movePutsKingInCheck(board, lastMove, enPassant)) {
                    nextPositions[enPassant] = EN_PASSANT;
                }

                board->changeBoard(capturedPiece->getSymbol(), opponentPawnPos);
            }
        }
    }

    // 3. regular motion
    for (Direction d : directions) {
        std::map<Position, MoveTypes> nextPositionsInD = this->allPosInDirection(d, lastMove, board);
        nextPositions.insert(nextPositionsInD.begin(), nextPositionsInD.end());
    }
}
