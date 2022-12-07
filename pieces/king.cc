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
    std::vector<Position> maxPossibilities;
    maxPossibilities.emplace_back(Position{currPos.row - 1, currPos.col});
    maxPossibilities.emplace_back(Position{currPos.row + 1, currPos.col});
    maxPossibilities.emplace_back(Position{currPos.row, currPos.col - 1});
    maxPossibilities.emplace_back(Position{currPos.row, currPos.col + 1});
    maxPossibilities.emplace_back(Position{currPos.row - 1, currPos.col - 1});
    maxPossibilities.emplace_back(Position{currPos.row - 1, currPos.col + 1});
    maxPossibilities.emplace_back(Position{currPos.row + 1, currPos.col - 1});
    maxPossibilities.emplace_back(Position{currPos.row + 1, currPos.col + 1});

    Position oldPos = getPos();

    for (auto newPos : maxPossibilities) {
        bool inCheck = false;
        bool capture = false;

        Colour opposingColour = (colour == BLACK) ? WHITE : BLACK;

        if (newPos.row >= 0 && newPos.row < rows && newPos.col >= 0 && newPos.col < cols) {
            Piece *capturedPiece = board[newPos.row][newPos.col];
            bool validPiece = (!capturedPiece || capturedPiece->getColour() == opposingColour);
            if (validPiece) {
                if (capturedPiece) capture = true;

                board[newPos.row][newPos.col] = board[oldPos.row][oldPos.col];
                board[oldPos.row][oldPos.col] = nullptr;
                setPos(newPos);

                char kingChar = (colour == BLACK) ? 'k' : 'K';

                // check if possible moves of the opponent put king in check
                if (checkIfKingInCheck) {
                    bool done = false;
                    for (int r = 0; r < rows; r++) {
                        for (int c = 0; c < cols; c++) {
                            Piece *nextPiece = board[r][c];
                            if (nextPiece && nextPiece->getColour() == opposingColour) {
                                nextPiece->generateNextPositions(board, rows, cols, lastMove, false);
                                for (auto nextPossibleMove: nextPiece->getNextPositions()) {
                                    if (board[nextPossibleMove.first.row][nextPossibleMove.first.col] &&
                                        board[nextPossibleMove.first.row][nextPossibleMove.first.col]->getSymbol() ==
                                        symbol) {
                                        inCheck = true;
                                        done = true;
                                        break;
                                    }
                                }
                            }
                            if (done) break;
                        }
                        if (done) break;
                    }
                }

                board[oldPos.row][oldPos.col] = board[newPos.row][newPos.col];
                setPos(oldPos);
                board[newPos.row][newPos.col] = capturedPiece;

                if (checkIfKingInCheck) {
                    for (int r = 0; r < rows; r++) {
                        for (int c = 0; c < cols; c++) {
                            Piece *nextPiece = board[r][c];
                            if (nextPiece && nextPiece->getColour() == opposingColour) {
                                nextPiece->generateNextPositions(board, rows, cols, lastMove, false);
                            }
                        }
                    }
                }

                if (!inCheck) {
                    if (capture) nextPositions[std::move(newPos)] = CAPTURE;
                    else nextPositions[std::move(newPos)] = MOVE;
                }
            }
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
