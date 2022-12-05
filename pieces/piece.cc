#include "piece.h"
#include "iostream"

Piece::Piece(Colour colour, char symbol, Position pos, Distance dist, bool specialCapture):colour{colour}, symbol{symbol}, currPos{pos}, dist{dist}, specialCapture{specialCapture} {}

InvalidDirection::InvalidDirection(std::string message): message{message} {}
void InvalidDirection::printMessage() const {std::cout << message << std::endl;};

bool Piece::movePutsKingInCheck(std::vector<std::vector<Piece*>> board, Move* lastMove, int rows, int cols, Position newPos, bool checkIfKingInCheck) {
    bool inCheck = false;

    Position oldPos = getPos();
    Piece* capturedPiece = board[newPos.row][newPos.col];

    board[newPos.row][newPos.col] = board[oldPos.row][oldPos.col];
    board[oldPos.row][oldPos.col] = nullptr;
    setPos(newPos);

    Colour opposingColour = (colour == BLACK) ? WHITE : BLACK;
    char kingChar = (colour == BLACK) ? 'k' : 'K';

    bool done = false;
    // check if possible moves put king in check
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Piece* nextPiece = board[r][c];
            if (nextPiece && nextPiece->getColour() == opposingColour) {
                nextPiece->generateNextPositions(board, rows, cols, lastMove, false);
                for (auto nextPossibleMove : nextPiece->getNextPositions()) {
                    if (board[nextPossibleMove.first.row][nextPossibleMove.first.col] && board[nextPossibleMove.first.row][nextPossibleMove.first.col]->getSymbol() == kingChar) {
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

    setPos(oldPos);
    board[newPos.row][newPos.col] = capturedPiece;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Piece* nextPiece = board[r][c];
            if (nextPiece && nextPiece->getColour() == opposingColour) {
                nextPiece->generateNextPositions(board, rows, cols, lastMove, false);
            }
        }
    }
    return inCheck;
}

std::map<Position, MoveTypes> Piece::allPosInDirection(Direction direction, Move* lastMove, int rows, int cols, std::vector<std::vector<Piece*>> board, bool checkIfKingInCheck) {
    std::map<Position, MoveTypes> nextPositionsInD;
    Colour opposingColour = (colour == BLACK) ? WHITE : BLACK;
    char opposingKing = (colour == BLACK) ? 'K' : 'k';

    int dx = 1;
    int dy = 1;

    if (dist == INFINITE) {
        dx = 8;
        dy = 8;
    }

    int aim = 1;
    if (colour == BLACK) {
        aim *= -1;
    }

    if (direction == LEFT) {
        for (int d = 1; d < dx; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row, currPos.col - i};

            if (0 > nextSpot.row || nextSpot.row >= rows || nextSpot.col < 0 || nextSpot.col >= cols) break;

            if (board[nextSpot.row][nextSpot.col] || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                        break;
                    }

                    nextPositionsInD[nextSpot] = MOVE;
                }
            } else {
                break;
            }
        }
    } else if (direction == RIGHT) {
        for (int d = 1; d < dx; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row, currPos.col + i};

            if (0 > nextSpot.row || nextSpot.row >= rows || nextSpot.col < 0 || nextSpot.col >= cols) break;

            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                        break;
                    }
                
                    nextPositionsInD[nextSpot] = MOVE;
                }
            } else {
                break;
            }
        }
    } else if (direction == UP) {
        for (int d = 1; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row + i, currPos.col};

            if (0 > nextSpot.row || nextSpot.row >= rows || nextSpot.col < 0 || nextSpot.col >= cols) break;
            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                        break;
                    }
                
                    nextPositionsInD[nextSpot] = MOVE;
                }
            } else {
                break;
            }
        }
    } else if (direction == PAWN_UP) {
        if (currPos.row + aim >= 0 && currPos.row + aim < rows) {
            if (!board[currPos.row + aim][currPos.col]) {
                Position nextSpot = Position{currPos.row + aim, currPos.col};
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    nextPositionsInD[nextSpot] = MOVE;
                }
            }
            if (0 <= currPos.row + aim && currPos.row + aim < rows && 0 <= currPos.col - 1 && currPos.col - 1 < cols) {
                if (board[currPos.row + aim][currPos.col - 1] && board[currPos.row + aim][currPos.col - 1]->getColour() == opposingColour) {
                    Position nextSpot = Position{currPos.row + aim, currPos.col - 1};
                    if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                    }
                }
            }
            if (0 <= currPos.row + aim && currPos.row + aim < rows && 0 <= currPos.col + 1 && currPos.col + 1 < cols) {
                if (board[currPos.row + aim][currPos.col + 1] && board[currPos.row + aim][currPos.col + 1]->getColour() == opposingColour) {
                    Position nextSpot = Position{currPos.row + aim, currPos.col + 1};
                    if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                    }
                }
            }
        }
    } else if (direction == DOWN) {
        for (int d = 1; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row - i, currPos.col};

            if (0 > nextSpot.row || nextSpot.row >= rows || nextSpot.col < 0 || nextSpot.col >= cols) break;
            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                        break;
                    }
                    nextPositionsInD[nextSpot] = MOVE;
                }
            } else {
                break;
            }
        }
    } else if (direction == LEFT_UP_DIAGONAL) {
        for (int d = 1; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row + i, currPos.col - i};

            if (0 > nextSpot.row || nextSpot.row >= rows || nextSpot.col < 0 || nextSpot.col >= cols) break;
            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                        break;
                    }

                    nextPositionsInD[nextSpot] = MOVE;
                }
            } else {
                break;
            }
        }
    } else if (direction == LEFT_DOWN_DIAGONAL) {
        for (int d = 1; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row - i, currPos.col - i};

            if (0 > nextSpot.row || nextSpot.row >= rows || nextSpot.col < 0 || nextSpot.col >= cols) break;
            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                        break;
                    }
                    
                    nextPositionsInD[nextSpot] = MOVE;
                }
            } else {
                break;
            }
        }
    } else if (direction == RIGHT_UP_DIAGONAL) {
        for (int d = 1; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row + i, currPos.col + i};

            if (0 > nextSpot.row || nextSpot.row >= rows || nextSpot.col < 0 || nextSpot.col >= cols) break;
            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                        break;
                    }

                    nextPositionsInD[nextSpot] = MOVE;
                }
            } else {
                break;
            }
        }
    } else if (direction == RIGHT_DOWN_DIAGONAL) {
        for (int d = 1; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row - i, currPos.col + i};

            if (0 > nextSpot.row || nextSpot.row >= rows || nextSpot.col < 0 || nextSpot.col >= cols) break;
            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                        break;
                    }

                    nextPositionsInD[nextSpot] = MOVE;
                }
            } else {
                break;
            }
        }
    } else if (direction == KNIGHT_DOWN_LEFT) {
        if (0 <= currPos.row - 2 * aim && currPos.row - 2 * aim < rows && currPos.col - aim >= 0 && currPos.col - aim < cols) {
            const Position nextSpot = Position{currPos.row - 2 * aim, currPos.col - aim};
            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr && board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                    } else if (board[nextSpot.row][nextSpot.col] == nullptr) {
                        nextPositionsInD[nextSpot] = MOVE;
                    }
                }
            }
        }
    } else if (direction == KNIGHT_DOWN_RIGHT) {
        if (0 <= currPos.row - 2 * aim && currPos.row - 2 * aim < rows && currPos.col + aim >= 0 && currPos.col + aim < cols) {
            const Position nextSpot = Position{currPos.row - 2 * aim, currPos.col + aim};
            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr && board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                    } else if (board[nextSpot.row][nextSpot.col] == nullptr) {
                        nextPositionsInD[nextSpot] = MOVE;
                    }
                }
            }
        }
    } else if (direction == KNIGHT_UP_LEFT) {
        if (0 <= currPos.row + 2 * aim && currPos.row + 2 * aim < rows && currPos.col - aim >= 0 && currPos.col - aim < cols) {
            const Position nextSpot = Position{currPos.row + 2 * aim, currPos.col - aim};
            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr && board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                    } else if (board[nextSpot.row][nextSpot.col] == nullptr) {
                        nextPositionsInD[nextSpot] = MOVE;
                    }
                }
            }
        }
    } else if (direction == KNIGHT_UP_RIGHT) {
        if (0 <= currPos.row + 2 * aim && currPos.row + 2 * aim < rows && currPos.col + aim >= 0 && currPos.col + aim < cols) {
            const Position nextSpot = Position{currPos.row + 2 * aim, currPos.col + aim};
            if (board[nextSpot.row][nextSpot.col] == nullptr || board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                if (!checkIfKingInCheck || !movePutsKingInCheck(board, lastMove, rows, cols, nextSpot)) {
                    if (board[nextSpot.row][nextSpot.col] != nullptr && board[nextSpot.row][nextSpot.col]->getColour() == opposingColour) {
                        nextPositionsInD[nextSpot] = CAPTURE;
                    } else if (board[nextSpot.row][nextSpot.col] == nullptr) {
                        nextPositionsInD[nextSpot] = MOVE;
                    }
                }
            }
        }
    } else {
        throw InvalidDirection{"Invalid direction."};
    }

    return nextPositionsInD;
}

// bool Piece::validateMove(Position newPos, Board* board, Move* lastMove) {
//     generateNextPositions(board, lastMove);
//     for (auto const pair : nextPositions) {
//         if (pair.first.row == newPos.row && pair.first.col == newPos.col) {
//             return true;
//         }
//     }
//     return false;
// }

char Piece::getSymbol() {
    return symbol;
}

Position Piece::getPos() {
    return currPos;
}

bool Piece::getSkipsTwo() { 
    return false;
}

Colour Piece::getColour() {
    return colour;
}

bool Piece::getFirstMove() {
    return firstMove;
}

bool Piece::getInCheck() {
    return false;
}

Distance Piece::getDist() {
    return dist;
}

bool Piece::getSpecialCapture() {
    return specialCapture;
}

std::vector<Direction> Piece::getDirections() {
    return directions;
}

void Piece::setInCheck(bool val) {}

void Piece::setSkipsTwo(bool val) {}

void Piece::notFirstMove() {
    firstMove = false;
}

void Piece::setPos(Position pos) {currPos = pos;}

std::map<Position, MoveTypes> Piece::getNextPositions() {
    return nextPositions;
}

void Piece::setDirections(std::vector<Direction> dirs) {
    directions = dirs;
}

void Piece::setDistance(Distance d) {
    dist = d;
}
